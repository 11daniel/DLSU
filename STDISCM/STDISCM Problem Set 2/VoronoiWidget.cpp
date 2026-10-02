#include "VoronoiWidget.h"
#include <QPainter>
#include <QPen>
#include <QFont>

#include <random>
#include <limits>
#include <cmath>

VoronoiWidget::VoronoiWidget(int w, int h, QWidget* parent)
    : QWidget(parent), W_(w), H_(h), image_(W_, H_, QImage::Format_RGB32) {
    image_.fill(Qt::white);
    setMinimumSize(W_, H_);
}

VoronoiWidget::~VoronoiWidget() {
    stopSimulation();
}

void VoronoiWidget::setUpdateDelay(int ms) {
    if (ms < 1) ms = 1;
    delayMs_ = ms;
}

void VoronoiWidget::stopSimulation() {
    // Stop repaint timer
    if (repaintTimer_) {
        repaintTimer_->stop();
        repaintTimer_->deleteLater();
        repaintTimer_ = nullptr;
    }

    // Stop workers
    for (auto& sp : sensors_) {
        if (!sp) continue;
        sp->running.store(false, std::memory_order_relaxed);
    }
    for (auto& sp : sensors_) {
        if (!sp) continue;
        if (sp->worker.joinable()) sp->worker.join();
    }
    sensors_.clear();
}

void VoronoiWidget::assignColorsDeterministic(int n) {
    colors_.clear();
    colors_.reserve(n);

    std::mt19937 rng(42u);
    std::uniform_int_distribution<int> dist(60, 230);
    for (int i = 0; i < n; ++i) {
        colors_.push_back(QColor(dist(rng), dist(rng), dist(rng)));
    }
}

void VoronoiWidget::buildGraph() {
    // Euclidean neighbor graph using threshold_
    const int N = static_cast<int>(sensors_.size());
    for (int i = 0; i < N; ++i) {
        sensors_[i]->neighbors.clear();
    }
    for (int i = 0; i < N; ++i) {
        const auto& pi = sensors_[i]->pos;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            const auto& pj = sensors_[j]->pos;
            float dx = float(pi.x() - pj.x());
            float dy = float(pi.y() - pj.y());
            float dist = std::sqrt(dx * dx + dy * dy);
            if (dist <= threshold_) {
                sensors_[i]->neighbors.push_back(j);
            }
        }
    }
}

void VoronoiWidget::startWorkers() {
    // Launch one worker per sensor: average self + neighbors, sleep delayMs_
    const int N = static_cast<int>(sensors_.size());
    for (int i = 0; i < N; ++i) {
        auto node = sensors_[i];
        node->running.store(true, std::memory_order_relaxed);

        node->worker = std::thread([this, node]() {
            // Each node loops independently (asynchronous, no notifications) — matches PDF spec
            while (node->running.load(std::memory_order_relaxed)) {
                float sum = node->temperature.load(std::memory_order_relaxed);
                int count = 1;

                // read neighbors' latest values
                for (int idx : node->neighbors) {
                    auto nsp = sensors_[idx];
                    sum += nsp->temperature.load(std::memory_order_relaxed);
                    ++count;
                }

                float avg = sum / static_cast<float>(count);
                node->temperature.store(avg, std::memory_order_relaxed);

                std::this_thread::sleep_for(std::chrono::milliseconds(delayMs_));
            }
            });
    }

    // Periodic GUI refresh to show evolving values
    repaintTimer_ = new QTimer(this);
    connect(repaintTimer_, &QTimer::timeout, this, QOverload<>::of(&VoronoiWidget::update));
    repaintTimer_->start(250);
}

void VoronoiWidget::makeVoronoiBackground() {
    // Compute nearest seed index and color the pixel accordingly (sensors' positions)
    image_.fill(Qt::white);
    if (sensors_.empty()) return;

    const int N = static_cast<int>(sensors_.size());

    for (int y = 0; y < H_; ++y) {
        QRgb* scan = reinterpret_cast<QRgb*>(image_.scanLine(y));
        for (int x = 0; x < W_; ++x) {
            int bestIdx = -1;
            long bestD2 = std::numeric_limits<long>::max();

            for (int i = 0; i < N; ++i) {
                long dx = x - sensors_[i]->pos.x();
                long dy = y - sensors_[i]->pos.y();
                long d2 = dx * dx + dy * dy;
                if (d2 < bestD2) {
                    bestD2 = d2;
                    bestIdx = i;
                }
            }
            const QColor& col = colors_[bestIdx];
            scan[x] = qRgb(col.red(), col.green(), col.blue());
        }
    }
}

void VoronoiWidget::loadSensorsAndStart(float threshold, const QVector<SensorInput>& inputs) {
    // Reset any prior run
    stopSimulation();

    threshold_ = threshold;

    // Create sensor nodes (shared_ptr because SensorNode is neither copyable nor movable)
    sensors_.reserve(inputs.size());
    for (const auto& s : inputs) {
        sensors_.push_back(std::make_shared<SensorNode>(s.pos, s.temperature));
    }

    assignColorsDeterministic(static_cast<int>(sensors_.size()));
    buildGraph();
    makeVoronoiBackground();
    update();
    startWorkers();
}

void VoronoiWidget::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.drawImage(0, 0, image_);

    // Overlay seeds and live temperatures (1 decimal place)
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPen pen(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(Qt::white);

    const int r = 5;
    QFont f = painter.font();
    f.setPointSize(9);
    painter.setFont(f);

    for (size_t i = 0; i < sensors_.size(); ++i) {
        const auto& s = sensors_[i];
        painter.drawEllipse(s->pos, r, r);

        // Draw temperature slightly offset from the seed point
        const QString tempStr = QString::number(s->temperature.load(std::memory_order_relaxed), 'f', 1);
        painter.drawText(s->pos + QPoint(8, -8), tempStr);
    }
}
