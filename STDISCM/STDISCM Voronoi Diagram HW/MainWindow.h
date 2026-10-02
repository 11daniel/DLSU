#pragma once
#include <QWidget>
#include <QVector>
#include <QPoint>

class QPushButton;
class QLabel;
class VoronoiWidget;

class MainWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);

private slots:
    void onLoadClicked();

private:
    QPushButton* loadBtn_;
    VoronoiWidget* canvas_;
    QLabel* status_;
    QVector<QPoint> parsePointsFromFile(const QString& path);
};
