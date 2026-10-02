#pragma once
#include <QWidget>
#include <QVector>
#include <QPoint>

#include <memory>

class QPushButton;
class QLabel;
class QSlider;

#include "VoronoiWidget.h"  // brings in SensorInput declaration

class MainWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);

private slots:
    void onLoadClicked();
    void onDelayChanged(int value);

private:
    QPushButton* loadBtn_;
    QLabel* status_;
    QSlider* delaySlider_;
    QLabel* delayLabel_;
    VoronoiWidget* canvas_;

    QVector<SensorInput> parseSensorsFromFile(const QString& path, float& threshold);
};
