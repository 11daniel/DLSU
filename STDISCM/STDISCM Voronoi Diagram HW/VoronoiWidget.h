#pragma once
#include <QWidget>
#include <QImage>
#include <QVector>
#include <QPoint>
#include <QColor>

class VoronoiWidget : public QWidget {
    Q_OBJECT
public:
    explicit VoronoiWidget(int w, int h, QWidget* parent = nullptr);

    void setSeeds(const QVector<QPoint>& pts);
    void generateVoronoi(); // brute-force (squared Euclidean)
    QSize sizeHint() const override { return image_.size(); }

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    int W_, H_;
    QImage image_;
    QVector<QPoint> seeds_;
    QVector<QColor> colors_;

    void assignColorsDeterministic();
};
