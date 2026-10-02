#include "MainWindow.h"
#include "VoronoiWidget.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>
#include <fstream>
#include <sstream>
#include <string>

static constexpr int kWidth = 800;
static constexpr int kHeight = 600;

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {
    setWindowTitle("Voronoi Diagram (Qt)");
    resize(kWidth + 40, kHeight + 120);

    loadBtn_ = new QPushButton("Load config.txt");
    canvas_ = new VoronoiWidget(kWidth, kHeight, this);
    status_ = new QLabel("Tip: Click 'Load config.txt' and pick a file with 'x y' integer pairs.");

    auto topRow = new QHBoxLayout();
    topRow->addWidget(loadBtn_);
    topRow->addStretch();
    topRow->addWidget(status_);

    auto root = new QVBoxLayout(this);
    root->addLayout(topRow);
    root->addWidget(canvas_, /*stretch*/1);

    connect(loadBtn_, &QPushButton::clicked, this, &MainWindow::onLoadClicked);
}

QVector<QPoint> MainWindow::parsePointsFromFile(const QString& path) {
    QVector<QPoint> pts;
    std::ifstream fin(path.toStdString());
    if (!fin) return pts;

    std::string line;
    while (std::getline(fin, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        int x, y;
        if (iss >> x >> y) {
            // Clamp to canvas bounds
            if (x < 0) x = 0; if (x >= kWidth)  x = kWidth - 1;
            if (y < 0) y = 0; if (y >= kHeight) y = kHeight - 1;
            pts.push_back(QPoint(x, y));
        }
        // ignore malformed lines silently
    }
    return pts;
}

void MainWindow::onLoadClicked() {
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Load configuration file",
        "",
        "Text Files (*.txt)"
    );
    if (fileName.isEmpty()) return;

    auto points = parsePointsFromFile(fileName);
    if (points.isEmpty()) {
        QMessageBox::warning(this, "No points", "No valid 'x y' pairs found in file.");
        return;
    }

    canvas_->setSeeds(points);
    canvas_->generateVoronoi();
    status_->setText(QString("Loaded %1 seed(s) from: %2").arg(points.size()).arg(fileName));
}
