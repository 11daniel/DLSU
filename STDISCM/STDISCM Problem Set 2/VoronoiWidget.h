#pragma once
#include <QWidget>
#include <QImage>
#include <QVector>
#include <QPoint>
#include <QColor>
#include <QTimer>

#include <atomic>
#include <thread>
#include <vector>
#include <memory>

struct SensorInput {
    QPoint pos;
    float temperature;
};

class VoronoiWidget : public QWidget {
    Q_OBJECT
public:
    explicit VoronoiWidget(int w, int h, QWidget* parent = nullptr);
    ~VoronoiWidget();

    // Load config (threshold + sensors), build graph, start threads and GUI updates
    void loadSensorsAndStart(float threshold, const QVector<SensorInput>& sensors);

    // You can adjust the worker sleep (ms) while running
    void setUpdateDelay(int ms);

    QSize sizeHint() const override { return image_.size(); }

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    // ---- Types & Data ----
    struct SensorNode {
        QPoint pos;
        std::atomic<float> temperature;
        std::vector<int> neighbors;
        std::thread worker;
        std::atomic<bool> running{ false };

        SensorNode(QPoint p, float t) : pos(p), temperature(t) {}
        SensorNode(const SensorNode&) = delete;
        SensorNode& operator=(const SensorNode&) = delete;
    };

    int W_, H_;
    QImage image_;                         // static Voronoi background
    std::vector<std::shared_ptr<SensorNode>> sensors_; // store by shared_ptr (non-copyable/movable members)
    QVector<QColor> colors_;
    float threshold_ = 0.0f;
    int delayMs_ = 300;
    QTimer* repaintTimer_ = nullptr;

    // ---- Helpers ----
    void stopSimulation();
    void assignColorsDeterministic(int n);
    void buildGraph();
    void startWorkers();
    void makeVoronoiBackground(); // fill image_ by nearest seed only (static)
};
