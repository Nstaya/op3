#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPointF>
#include <QPen>
#include <QColor>

struct GraphSettings {

    QColor backgroundColor = Qt::white;
    QColor axisColor = Qt::black;
    QColor gridColor = Qt::lightGray;
    QColor dataColor = Qt::blue;
    QColor minLineColor = Qt::red;
    QColor maxLineColor = Qt::green;
    QColor medianLineColor = Qt::darkYellow;

    int margin = 50;
    int topMargin = 80;
    int axisOffset = 20;
    int pointSize = 10;
    int tickLength = 5;
    int horizontalTitlePosX = 1;
    int horizontalTitlePosY = 35;
    int verticalTitlePosX = 50;
    int verticalTitlePosY = -10;
    int lineWight = 1;

    int axisWidth = 2;
    int gridWidth = 1;
    int dataWidth = 2;
    int metricWidth = 1;
    int axisLineWidth = 2;
    int xEllipse = 4;
    int yEllipse = 4;

    QString defaultXLabel = "Year";
    QString defaultYLabel = "Value";
};

class GraphWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GraphWidget(QWidget *parent = nullptr);

    void setData(const QVector<QPointF> &data, float min, float max, float median);
    void setAxisLabels(const QString &xLabel, const QString &yLabel);
    void setTitle(const QString &title);
    void clear();

    GraphSettings& settings() { return graphSettings; }

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawAxes(QPainter &painter);
    void drawGrid(QPainter &painter);
    void drawData(QPainter &painter);
    void drawMetrics(QPainter &painter);
    void drawTitle(QPainter &painter);

    QVector<QPointF> points;
    float minValue;
    float maxValue;
    float medianValue;
    QString xAxisLabel;
    QString yAxisLabel;
    QString title;

    GraphSettings graphSettings;
    QRect getGraphRect() const;
};

#endif // GRAPHWIDGET_H
