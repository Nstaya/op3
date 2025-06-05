// #include "graphwidget.h"
// #include <QPainter>
// #include <QFontMetrics>

// GraphWidget::GraphWidget(QWidget *parent) : QWidget(parent),
//     minValue(0), maxValue(0), medianValue(0)
// {
//     setBackgroundRole(QPalette::Base);
//     setAutoFillBackground(true);

//     xAxisLabel = graphSettings.defaultXLabel;
//     yAxisLabel = graphSettings.defaultYLabel;
// }

// void GraphWidget::setData(const QVector<QPointF> &data, float min, float max, float median)
// {
//     points = data;
//     minValue = min;
//     maxValue = max;
//     medianValue = median;
//     update();
// }

// void GraphWidget::setAxisLabels(const QString &xLabel, const QString &yLabel)
// {
//     xAxisLabel = !xLabel.isEmpty() ? xLabel : graphSettings.defaultXLabel;
//     yAxisLabel = !yLabel.isEmpty() ? yLabel : graphSettings.defaultYLabel;
//     update();
// }

// void GraphWidget::clear()
// {
//     points.clear();
//     update();
// }

// void GraphWidget::setTitle(const QString &title)
// {
//     this->title = title;
//     update();
// }

// void GraphWidget::drawTitle(QPainter &painter)
// {
//     if (title.isEmpty())
//         return;

//     QFont font = painter.font();
//     font.setBold(true);
//     font.setPointSize(graphSettings.pointSize);
//     painter.setFont(font);

//     QRect titleRect = rect();
//     titleRect.setHeight(graphSettings.verticalTitlePosX);
//     painter.drawText(titleRect, Qt::AlignCenter, title);

//     font.setBold(false);
//     font.setPointSize(graphSettings.pointSize);
//     painter.setFont(font);
// }

// void GraphWidget::paintEvent(QPaintEvent *event)
// {
//     Q_UNUSED(event);

//     QPainter painter(this);
//     painter.setRenderHint(QPainter::Antialiasing);

//     painter.fillRect(rect(), graphSettings.backgroundColor);

//     if (points.isEmpty())
//     {
//         painter.drawText(rect(), Qt::AlignCenter, "Введите данные");
//         return;
//     }

//     drawAxes(painter);
//     drawGrid(painter);
//     drawData(painter);
//     drawMetrics(painter);
// }

// void GraphWidget::drawAxes(QPainter &painter)
// {
//     QRect graphRect = getGraphRect();

//     QPen axisPen(graphSettings.axisColor, graphSettings.axisLineWidth);
//     painter.setPen(axisPen);

//     painter.drawLine(graphRect.bottomLeft(), graphRect.bottomRight()); // X
//     painter.drawLine(graphRect.bottomLeft(), graphRect.topLeft());    // Y

//     painter.drawText(graphRect.bottomRight() + QPoint(-graphSettings.horizontalTitlePosX, graphSettings.horizontalTitlePosY), xAxisLabel);
//     painter.drawText(graphRect.topLeft() + QPoint(-graphSettings.verticalTitlePosX, graphSettings.verticalTitlePosY), yAxisLabel);

//     float minX = points.first().x();
//     float maxX = points.last().x();
//     float minY = minValue;
//     float maxY = maxValue;

//     float xStep = (maxX - minX);
//     float yStep = (maxY - minY);

//     for (int i = 0; i <= xStep; ++i)
//     {
//         float xValue = minX + i;
//         int xPos = graphRect.left() + i * (graphRect.width() / xStep);

//         painter.drawLine(xPos, graphRect.bottom(), xPos, graphRect.bottom());
//         painter.drawText(xPos - graphSettings.axisOffset, graphRect.bottom() + graphSettings.axisOffset, QString::number(xValue, 'f', 0));
//     }

//     for (int i = 0; i <= yStep; ++i)
//     {
//         float yValue = minY + i * yStep;
//         int yPos = graphRect.bottom() - i * (graphRect.height() / yStep);

//         painter.drawLine(graphRect.left() - yStep, yPos, graphRect.left(), yPos);
//         painter.drawText(graphRect.left() - graphSettings.margin + yStep, yPos + yStep, QString::number(yValue, 'f', graphSettings.axisLineWidth));
//     }
// }

// void GraphWidget::drawGrid(QPainter &painter)
// {
//     QRect graphRect = getGraphRect();
//     QPen gridPen(graphSettings.gridColor, graphSettings.lineWight, Qt::DotLine);
//     painter.setPen(gridPen);

//     float minX = points.first().x();
//     float maxX = points.last().x();
//     float minY = minValue;
//     float maxY = maxValue;
//     float xStep = (maxX - minX); // optimalSteps;
//     float yStep = (maxY - minY);

//     for (int i = 1; i < xStep; ++i)
//     {
//         int xPos = graphRect.left() + i * (graphRect.width() / xStep);
//         painter.drawLine(xPos, graphRect.top(), xPos, graphRect.bottom());
//     }

//     for (int i = 1; i < yStep; ++i)
//     {
//         int yPos = graphRect.bottom() - i * (graphRect.height() / yStep);
//         painter.drawLine(graphRect.left(), yPos, graphRect.right(), yPos);
//     }
// }

// void GraphWidget::drawData(QPainter &painter)
// {
//     QRect graphRect = getGraphRect();
//     float minX = points.first().x();
//     float maxX = points.last().x();
//     float minY = minValue;
//     float maxY = maxValue;

//     QVector<QPoint> plotPoints;
//     for (const QPointF &point : points)
//     {
//         int x = graphRect.left() + (point.x() - minX) * graphRect.width() / (maxX - minX);
//         int y = graphRect.bottom() - (point.y() - minY) * graphRect.height() / (maxY - minY);
//         plotPoints.append(QPoint(x, y));
//     }

//     QPen dataPen(graphSettings.dataColor, graphSettings.axisLineWidth);
//     painter.setPen(dataPen);
//     painter.drawPolyline(plotPoints.constData(), plotPoints.size());

//     painter.setBrush(graphSettings.dataColor);
//     for (const QPoint &point : plotPoints)
//     {
//         painter.drawEllipse(point, graphSettings.xEllipse, graphSettings.yEllipse);
//     }
// }

// void GraphWidget::drawMetrics(QPainter &painter)
// {
//     QRect graphRect = getGraphRect();

//     float minY = minValue;
//     float maxY = maxValue;
//     float yStep = (maxY - minY);

//     int minYPos = graphRect.bottom() - (minValue - minY) * graphRect.height() / (maxY - minY);
//     int maxYPos = graphRect.bottom() - (maxValue - minY) * graphRect.height() / (maxY - minY);
//     int medianYPos = graphRect.bottom() - (medianValue - minY) * graphRect.height() / (maxY - minY);

//     QPen minPen(graphSettings.minLineColor, graphSettings.lineWight, Qt::DashLine);
//     QPen maxPen(graphSettings.maxLineColor, graphSettings.lineWight, Qt::DashLine);
//     QPen medianPen(graphSettings.medianLineColor, graphSettings.lineWight, Qt::DashLine);

//     painter.setPen(minPen);
//     painter.drawLine(graphRect.left(), minYPos, graphRect.right(), minYPos);
//     painter.drawText(graphRect.right() - graphSettings.margin, minYPos - yStep, "Min: " + QString::number(minValue, 'f', graphSettings.axisLineWidth));

//     painter.setPen(maxPen);
//     painter.drawLine(graphRect.left(), maxYPos, graphRect.right(), maxYPos);
//     painter.drawText(graphRect.right() - graphSettings.margin, maxYPos - yStep, "Max: " + QString::number(maxValue, 'f', graphSettings.axisLineWidth));

//     painter.setPen(medianPen);
//     painter.drawLine(graphRect.left(), medianYPos, graphRect.right(), medianYPos);
//     painter.drawText(graphRect.right() - graphSettings.margin, medianYPos - yStep, "Median: " + QString::number(medianValue, 'f', graphSettings.axisLineWidth));
// }

// QRect GraphWidget::getGraphRect() const {
//     return rect().adjusted(graphSettings.margin, graphSettings.topMargin, -graphSettings.margin, -graphSettings.margin);
// }

#include "graphwidget.h"
#include <QPainter>
#include <QFontMetrics>

GraphWidget::GraphWidget(QWidget *parent) : QWidget(parent),
    minValue(0), maxValue(0), medianValue(0)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    xAxisLabel = graphSettings.defaultXLabel;
    yAxisLabel = graphSettings.defaultYLabel;
}

void GraphWidget::setData(const QVector<QPointF> &data, float min, float max, float median)
{
    points = data;
    minValue = min;
    maxValue = max;
    medianValue = median;
    update();
}

void GraphWidget::setAxisLabels(const QString &xLabel, const QString &yLabel)
{
    xAxisLabel = !xLabel.isEmpty() ? xLabel : graphSettings.defaultXLabel;
    yAxisLabel = !yLabel.isEmpty() ? yLabel : graphSettings.defaultYLabel;
    update();
}

void GraphWidget::clear()
{
    points.clear();
    update();
}

void GraphWidget::setTitle(const QString &title)
{
    this->title = title;
    update();
}

void GraphWidget::drawTitle(QPainter &painter)
{
    if (title.isEmpty())
        return;

    QFont font = painter.font();
    font.setBold(true);
    font.setPointSize(graphSettings.pointSize);
    painter.setFont(font);

    QRect titleRect = rect();
    titleRect.setHeight(graphSettings.verticalTitlePosX);
    painter.drawText(titleRect, Qt::AlignCenter, title);

    font.setBold(false);
    font.setPointSize(graphSettings.pointSize);
    painter.setFont(font);
}

void GraphWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.fillRect(rect(), graphSettings.backgroundColor);

    if (points.isEmpty())
    {
        painter.drawText(rect(), Qt::AlignCenter, "Введите данные");
        return;
    }

    drawAxes(painter);
    drawGrid(painter);
    drawData(painter);
    drawMetrics(painter);
}

void GraphWidget::drawAxes(QPainter &painter)
{
    QRect graphRect = getGraphRect();

    QPen axisPen(graphSettings.axisColor, graphSettings.axisLineWidth);
    painter.setPen(axisPen);

    painter.drawLine(graphRect.bottomLeft(), graphRect.bottomRight()); // X
    painter.drawLine(graphRect.bottomLeft(), graphRect.topLeft());    // Y

    painter.drawText(graphRect.bottomRight() + QPoint(-graphSettings.horizontalTitlePosX, graphSettings.horizontalTitlePosY), xAxisLabel);
    painter.drawText(graphRect.topLeft() + QPoint(-graphSettings.verticalTitlePosX, graphSettings.verticalTitlePosY), yAxisLabel);

    float minX = points.first().x();
    float maxX = points.last().x();
    float minY = minValue;
    float maxY = maxValue;

    int optimalSteps = qMin(graphSettings.tickLength, points.size());
    float xStep = (maxX - minX) / optimalSteps;
    float yStep = (maxY - minY) / graphSettings.tickLength;

    for (int i = 0; i <= graphSettings.tickLength; ++i)
    {
        float xValue = minX + i * xStep;
        int xPos = graphRect.left() + i * (graphRect.width() / graphSettings.tickLength);

        painter.drawLine(xPos, graphRect.bottom(), xPos, graphRect.bottom() + graphSettings.tickLength);
        painter.drawText(xPos - graphSettings.axisOffset, graphRect.bottom() + graphSettings.axisOffset, QString::number(xValue, 'f', 0));
    }

    for (int i = 0; i <= graphSettings.tickLength; ++i)
    {
        float yValue = minY + i * yStep;
        int yPos = graphRect.bottom() - i * (graphRect.height() / graphSettings.tickLength);

        painter.drawLine(graphRect.left() - graphSettings.tickLength, yPos, graphRect.left(), yPos);
        painter.drawText(graphRect.left() - graphSettings.margin + graphSettings.tickLength, yPos + graphSettings.tickLength, QString::number(yValue, 'f', graphSettings.axisLineWidth));
    }
}

void GraphWidget::drawGrid(QPainter &painter)
{
    QRect graphRect = getGraphRect();
    QPen gridPen(graphSettings.gridColor, graphSettings.lineWight, Qt::DotLine);
    painter.setPen(gridPen);

    for (int i = 1; i < graphSettings.tickLength; ++i)
    {
        int xPos = graphRect.left() + i * (graphRect.width() / graphSettings.tickLength);
        painter.drawLine(xPos, graphRect.top(), xPos, graphRect.bottom());
    }

    for (int i = 1; i < graphSettings.tickLength; ++i)
    {
        int yPos = graphRect.bottom() - i * (graphRect.height() / graphSettings.tickLength);
        painter.drawLine(graphRect.left(), yPos, graphRect.right(), yPos);
    }
}

void GraphWidget::drawData(QPainter &painter)
{
    QRect graphRect = getGraphRect();
    float minX = points.first().x();
    float maxX = points.last().x();
    float minY = minValue;
    float maxY = maxValue;

    QVector<QPoint> plotPoints;
    for (const QPointF &point : points)
    {
        int x = graphRect.left() + (point.x() - minX) * graphRect.width() / (maxX - minX);
        int y = graphRect.bottom() - (point.y() - minY) * graphRect.height() / (maxY - minY);
        plotPoints.append(QPoint(x, y));
    }

    QPen dataPen(graphSettings.dataColor, graphSettings.axisLineWidth);
    painter.setPen(dataPen);
    painter.drawPolyline(plotPoints.constData(), plotPoints.size());

    painter.setBrush(graphSettings.dataColor);
    for (const QPoint &point : plotPoints)
    {
        painter.drawEllipse(point, graphSettings.xEllipse, graphSettings.yEllipse);
    }
}

void GraphWidget::drawMetrics(QPainter &painter)
{
    QRect graphRect = getGraphRect();

    float minY = minValue;
    float maxY = maxValue;

    int minYPos = graphRect.bottom() - (minValue - minY) * graphRect.height() / (maxY - minY);
    int maxYPos = graphRect.bottom() - (maxValue - minY) * graphRect.height() / (maxY - minY);
    int medianYPos = graphRect.bottom() - (medianValue - minY) * graphRect.height() / (maxY - minY);

    QPen minPen(graphSettings.minLineColor, graphSettings.lineWight, Qt::DashLine);
    QPen maxPen(graphSettings.maxLineColor, graphSettings.lineWight, Qt::DashLine);
    QPen medianPen(graphSettings.medianLineColor, graphSettings.lineWight, Qt::DashLine);

    painter.setPen(minPen);
    painter.drawLine(graphRect.left(), minYPos, graphRect.right(), minYPos);
    painter.drawText(graphRect.right() - graphSettings.margin, minYPos - graphSettings.tickLength, "Min: " + QString::number(minValue, 'f', graphSettings.axisLineWidth));

    painter.setPen(maxPen);
    painter.drawLine(graphRect.left(), maxYPos, graphRect.right(), maxYPos);
    painter.drawText(graphRect.right() - graphSettings.margin, maxYPos - graphSettings.tickLength, "Max: " + QString::number(maxValue, 'f', graphSettings.axisLineWidth));

    painter.setPen(medianPen);
    painter.drawLine(graphRect.left(), medianYPos, graphRect.right(), medianYPos);
    painter.drawText(graphRect.right() - graphSettings.margin, medianYPos - graphSettings.tickLength, "Median: " + QString::number(medianValue, 'f', graphSettings.axisLineWidth));
}

QRect GraphWidget::getGraphRect() const {
    return rect().adjusted(graphSettings.margin, graphSettings.topMargin, -graphSettings.margin, -graphSettings.margin);
}

