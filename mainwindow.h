#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "entry_point.h"
#include "graphwidget.h"
#include <QWidget>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct MetricsSettings {
    float min = 0;
    float max = 0;
    float median = 0;

    static const int MIN_COL = 1;
    static const int MAX_COL = 6;

    static bool isColumnValid(int column) {
        return column >= MIN_COL && column <= MAX_COL;
    }
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSelectFileClicked();
    void onLoadDataClicked();
    void onCalculateAndDrawClicked();
    void onApplyFilterClicked();

private:
    Ui::MainWindow *ui;
    Context context;
    GraphWidget *graphWidget;
    MetricsSettings metrics;

    void updateTable(Node* head);
    void drawGraph(QPainter& painter);
    void drawMetrics(QPainter& painter, float min, float max, float median);
    void setupGraphArea();
    void filterDataByYear(int minYear, int maxYear);

    QStringList getAvailableRegions() const;
    QVector<int> getAvailableYears() const;
    void setupComboBoxes();

    QWidget* graphArea;
};

#endif // MAINWINDOW_H
