#include "MainWindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>
#include <QSlider>

#include <fstream>
#include <sstream>
#include <string>

static constexpr int kWidth = 800;
static constexpr int kHeight = 600;

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
    setWindowTitle("WSN Voronoi Simulation (Qt)");
    resize(kWidth + 40, kHeight + 160);

    loadBtn_ = new QPushButton("Load config.txt");
    status_ = new QLabel("Tip: Load a file with:\nLine 1 = threshold (float), then lines: x y temp");
    delaySlider_ = new QSlider(Qt::Horizontal);
    delaySlider_->setRange(10, 2000);
    delaySlider_->setValue(300);
    delayLabel_ = new QLabel("Delay: 300 ms");

    canvas_ = new VoronoiWidget(kWidth, kHeight, this);
    canvas_->setUpdateDelay(delaySlider_->value());

    auto topRow = new QHBoxLayout();
    topRow->addWidget(loadBtn_);
    topRow->addSpacing(16);
    topRow->addWidget(new QLabel("Sleep per iteration:"));
    topRow->addWidget(delaySlider_, /*stretch*/1);
    topRow->addWidget(delayLabel_);
    topRow->addStretch();
    topRow->addWidget(status_);

    auto root = new QVBoxLayout(this);
    root->addLayout(topRow);
    root->addWidget(canvas_, /*stretch*/1);

    connect(loadBtn_, &QPushButton::clicked, this, &MainWindow::onLoadClicked);
    connect(delaySlider_, &QSlider::valueChanged, this, &MainWindow::onDelayChanged);
}

void MainWindow::onDelayChanged(int value) {
    delayLabel_->setText(QString("Delay: %1 ms").arg(value));
    if (canvas_) canvas_->setUpdateDelay(value);
}

QVector<SensorInput> MainWindow::parseSensorsFromFile(const QString& path, float& threshold) {
    QVector<SensorInput> sensors;
    threshold = 0.0f;

    std::ifstream fin(path.toStdString());
    if (!fin) return sensors;

    std::string line;
    // Line 1: distance threshold (float, single-decimal allowed) — PDF spec
    if (std::getline(fin, line)) {
        try {
            threshold = std::stof(line);
        }
        catch (...) {
            threshold = 0.0f;
        }
    }

    // Remaining lines: x y temp  (x,y ints; temp float) — PDF spec
    while (std::getline(fin, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        int x, y;
        float t;
        if (iss >> x >> y >> t) {
            // clamp to canvas bounds
            if (x < 0) x = 0; if (x >= kWidth)  x = kWidth - 1;
            if (y < 0) y = 0; if (y >= kHeight) y = kHeight - 1;
            sensors.push_back({ QPoint(x, y), t });
        }
        // silently ignore malformed lines
    }
    return sensors;
}

void MainWindow::onLoadClicked() {
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Load configuration file",
        "",
        "Text Files (*.txt)"
    );
    if (fileName.isEmpty()) return;

    float threshold = 0.0f;
    auto sensors = parseSensorsFromFile(fileName, threshold);
    if (sensors.isEmpty()) {
        QMessageBox::warning(this, "Invalid config",
            "No valid data found.\nExpected: first line threshold, then lines: x y temp");
        return;
    }

    canvas_->loadSensorsAndStart(threshold, sensors);
    status_->setText(QString("Loaded %1 sensor(s), threshold = %2")
        .arg(sensors.size())
        .arg(threshold, 0, 'f', 1));

}
