#include "VoronoiWidget.h"
#include <QPainter>
#include <QElapsedTimer>
#include <random>
#include <limits>

VoronoiWidget::VoronoiWidget(int w, int h, QWidget* parent)
    : QWidget(parent), W_(w), H_(h), image_(W_, H_, QImage::Format_RGB32) {
    image_.fill(Qt::white);
    setMinimumSize(W_, H_);
}

void VoronoiWidget::setSeeds(const QVector<QPoint>& pts) {
    seeds_ = pts;
    assignColorsDeterministic();
}

void VoronoiWidget::assignColorsDeterministic() {
    colors_.clear();
    colors_.reserve(seeds_.size());

    // deterministic random colors for reproducibility
    std::mt19937 rng(42u);
    std::uniform_int_distribution<int> dist(60, 230);

    for (int i = 0; i < seeds_.size(); ++i) {
        QColor c(dist(rng), dist(rng), dist(rng));
        colors_.push_back(c);
    }
}

void VoronoiWidget::generateVoronoi() {
    if (seeds_.isEmpty()) {
        image_.fill(Qt::white);
        update();
        return;
    }

    // Fill per pixel: nearest seed by squared Euclidean distance
    for (int y = 0; y < H_; ++y) {
        QRgb* scan = reinterpret_cast<QRgb*>(image_.scanLine(y));
        for (int x = 0; x < W_; ++x) {
            int bestIdx = -1;
            long bestD2 = std::numeric_limits<long>::max();

            for (int i = 0; i < seeds_.size(); ++i) {
                long dx = x - seeds_[i].x();
                long dy = y - seeds_[i].y();
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

    // Overlay seed points (white filled circle with black border)
    QPainter p(&image_);
    p.setRenderHint(QPainter::Antialiasing, true);
    QPen pen(Qt::black);
    pen.setWidth(2);
    p.setPen(pen);
    p.setBrush(Qt::white);

    const int r = 5;
    for (int i = 0; i < seeds_.size(); ++i) {
        const QPoint& s = seeds_[i];
        p.drawEllipse(QPoint(s.x(), s.y()), r, r);
    }

    update(); // trigger repaint
}

void VoronoiWidget::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.drawImage(0, 0, image_);
}
