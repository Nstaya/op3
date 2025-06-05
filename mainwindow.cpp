#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphwidget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <cstring>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    graphWidget = new GraphWidget(this);
    ui->verticalLayout->addWidget(graphWidget);
    doOperation(&context, INIT);

    graphWidget->setAxisLabels("Year", "Value");
    QStringList headers = {"Year", "Region", "Natural Growth",
                           "Birth Rate", "Death Rate", "Demographic Weight", "Urbanization"};
    ui->tableWidget->setColumnCount(NUM_COLUMN);
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    ui->outputMetrics->setColumnCount(3);
    ui->outputMetrics->setHorizontalHeaderLabels({"Min", "Max", "Median"});
    ui->outputMetrics->setRowCount(1);

    if (context.dataHead) {
        Node* current = context.dataHead;
        int min = current->data.year, max = current->data.year;
        while (current) {
            min = qMin(min, current->data.year);
            max = qMax(max, current->data.year);
            current = current->next;
        }
    }
    setupComboBoxes();

    connect(ui->selectFile, &QPushButton::clicked, this, &MainWindow::onSelectFileClicked);
    connect(ui->loadData, &QPushButton::clicked, this, &MainWindow::onLoadDataClicked);
    connect(ui->calculateAndDraw, &QPushButton::clicked, this, &MainWindow::onCalculateAndDrawClicked);
    connect(ui->applyFilterYears, &QPushButton::clicked, this, &MainWindow::onApplyFilterClicked);

}

void MainWindow::onSelectFileClicked() {
    QString filename = QFileDialog::getOpenFileName(this, "Open CSV", "", "CSV Files (*.csv)");
    ui->fileName->setText(filename);
}

void MainWindow::onLoadDataClicked() {

    QString filename = ui->fileName->toPlainText();
    if (filename.isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Выберите файл");
        return;
    }

    QString regionFilter = ui->region->currentText();
    if (regionFilter == "Все регионы") {
        regionFilter = "";
    }
    if (context.region) {
        free(context.region);
    }
    context.region = regionFilter.isEmpty() ? NULL : strdup(regionFilter.toUtf8().constData());

    doOperation(&context, LOAD_DATA, filename.toUtf8().constData());

    if (context.error) {
        QMessageBox::critical(this, "Ошибка", "Данные не загружены");
        return;
    }

    int minYear = INT_MAX;
    int maxYear = INT_MIN;
    Node* current = context.dataHead;

    while (current) {
        minYear = qMin(minYear, current->data.year);
        maxYear = qMax(maxYear, current->data.year);
        current = current->next;
    }

    updateTable(context.dataHead);
    if (!context.error) {
        setupComboBoxes();
        updateTable(context.dataHead);
        QMessageBox::information(this, "Info", "Данные успешно загружены");
    }
}

void MainWindow::updateTable(Node* head) {
    ui->tableWidget->setRowCount(0);
    int row = 0;
    Node* current = head;

    while (current) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(current->data.year)));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(current->data.region));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(current->data.natural_population_growth)));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(current->data.birth_rate)));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(current->data.death_rate)));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(current->data.general_demographic_weight)));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(current->data.urbanization)));

        current = current->next;
        row++;
    }
}

void MainWindow::onCalculateAndDrawClicked() {
    int column = ui->numberOfCol->currentData().toInt();

    if (!MetricsSettings::isColumnValid(column)) {
        QMessageBox::critical(this, "Ошибка", "Некорректный номер колонки");
        return;
    }

    if (!context.dataHead) {
        QMessageBox::critical(this, "Ошибка", "Данные не загружены. Сначала загрузите файл");
        return;
    }

    QString regionFilter = ui->region->currentText();
    if (regionFilter == "Все регионы") {
        regionFilter = "";
    }

    if (!regionFilter.isEmpty()) {
        bool regionFound = false;
        Node* current = context.dataHead;
        while (current) {
            if (QString(current->data.region) == regionFilter) {
                regionFound = true;
                break;
            }
            current = current->next;
        }

        if (!regionFound) {
            QMessageBox::critical(this, "Ошибка", QString("Регион '%1' не найден").arg(regionFilter));
            return;
        }
    }

    context.column = column;
    doOperation(&context, CALCULATE_AND_DRAW, nullptr, &metrics.min, &metrics.max, &metrics.median);

    if (context.error) {
        QString errorMsg;
        switch (context.error) {
        case 1: errorMsg = "Ошибка загрузки данных"; break;
        case 2: errorMsg = "Ошибка вычисления метрик"; break;
        default: errorMsg = "Неизвестная ошибка"; break;
        }
        QMessageBox::critical(this, "Ошибка", errorMsg);
        return;
    }

    ui->outputMetrics->clearContents();
    ui->outputMetrics->setItem(0, 0, new QTableWidgetItem(QString::number(metrics.min, 'f', 2)));
    ui->outputMetrics->setItem(0, 1, new QTableWidgetItem(QString::number(metrics.max, 'f', 2)));
    ui->outputMetrics->setItem(0, 2, new QTableWidgetItem(QString::number(metrics.median, 'f', 2)));

    QVector<QPointF> points;
    QString yAxisLabel;

    switch (column) {
    case COL_YEAR: yAxisLabel = "Year"; break;
    case COL_NATURAL_GROWTH: yAxisLabel = "Natural Growth"; break;
    case COL_BIRTH_RATE: yAxisLabel = "Birth Rate"; break;
    case COL_DEATH_RATE: yAxisLabel = "Death Rate"; break;
    case COL_DEMOGRAPHIC_WEIGHT: yAxisLabel = "Demographic Weight"; break;
    case COL_URBANIZATION: yAxisLabel = "Urbanization"; break;
    default: yAxisLabel = "Value"; break;
    }

    Node* current = context.dataHead;
    while (current) {
        if (regionFilter.isEmpty() || QString(current->data.region) == regionFilter) {
            float value = 0;
            value = selectValue(current, column, value);
            points.append(QPointF(current->data.year, value));
        }
        current = current->next;
    }

    graphWidget->setAxisLabels("Year", yAxisLabel);
    graphWidget->setData(points, metrics.min, metrics.max, metrics.median);

    QString title = QString("Данные для %1 (колонка %2)").arg(regionFilter.isEmpty() ? "всех регионов" : "региона '" + regionFilter + "'").arg(column);
    graphWidget->setTitle(title);
}

void MainWindow::filterDataByYear(int minYear, int maxYear) {
    if (!context.dataHead) return;

    QVector<QPointF> filteredPoints;
    QString regionFilter = ui->region->currentText();
    if (regionFilter == "Все регионы") {
        regionFilter = "";
    }
    int column = ui->numberOfCol->currentData().toInt();

    Node* current = context.dataHead;
    while (current) {
        if (current->data.year >= minYear &&
            current->data.year <= maxYear &&
            (regionFilter.isEmpty() || QString(current->data.region) == regionFilter)) {

            float value = 0;
            value = selectValue(current, column, value);
            filteredPoints.append(QPointF(current->data.year, value));
        }
        current = current->next;
    }

    if (!filteredPoints.isEmpty()) {
        graphWidget->setData(filteredPoints, metrics.min, metrics.max, metrics.median);
    }
}

void MainWindow::onApplyFilterClicked() {
    int minYear = ui->minYear->currentData().toInt();
    int maxYear = ui->maxYear->currentData().toInt();

    if (minYear > maxYear) {
        QMessageBox::warning(this, "Ошибка", "Минимальный год не может быть больше максимального");
        return;
    }

    context.column = ui->numberOfCol->currentText().toInt();
    doOperation(&context, CALCULATE, nullptr, &metrics.min, &metrics.max, &metrics.median);

    filterDataByYear(minYear, maxYear);

    ui->outputMetrics->setItem(0, 0, new QTableWidgetItem(QString::number(metrics.min, 'f', 2)));
    ui->outputMetrics->setItem(0, 1, new QTableWidgetItem(QString::number(metrics.max, 'f', 2)));
    ui->outputMetrics->setItem(0, 2, new QTableWidgetItem(QString::number(metrics.median, 'f', 2)));

    QString title = QString("Данные за %1-%2 годы").arg(minYear).arg(maxYear);
    if (!ui->region->currentText().isEmpty()) {
        title += QString(" для региона '%1'").arg(ui->region->currentText());
    }
    graphWidget->setTitle(title);
}

QStringList MainWindow::getAvailableRegions() const {
    QStringList regions;
    Node* current = context.dataHead;
    while (current) {
        QString region = current->data.region;
        if (!regions.contains(region)) {
            regions.append(region);
        }
        current = current->next;
    }
    return regions;
}

QVector<int> MainWindow::getAvailableYears() const {
    QVector<int> years;
    Node* current = context.dataHead;
    while (current) {
        int year = current->data.year;
        if (!years.contains(year)) {
            years.append(year);
        }
        current = current->next;
    }
    std::sort(years.begin(), years.end());
    return years;
}

void MainWindow::setupComboBoxes() {

    ui->region->clear();
    ui->numberOfCol->clear();
    ui->minYear->clear();
    ui->maxYear->clear();

    ui->region->addItem("Все регионы");
    ui->region->addItems(getAvailableRegions());

    ui->numberOfCol->addItem("Год", COL_YEAR);
    ui->numberOfCol->addItem("Естественный прирост", COL_NATURAL_GROWTH);
    ui->numberOfCol->addItem("Рождаемость", COL_BIRTH_RATE);
    ui->numberOfCol->addItem("Смертность", COL_DEATH_RATE);
    ui->numberOfCol->addItem("Демография", COL_DEMOGRAPHIC_WEIGHT);
    ui->numberOfCol->addItem("Урбанизация", COL_URBANIZATION);

    QVector<int> years = getAvailableYears();
    for (int year : years) {
        ui->minYear->addItem(QString::number(year), year);
        ui->maxYear->addItem(QString::number(year), year);
    }

    if (!years.isEmpty()) {
        ui->minYear->setCurrentIndex(0);
        ui->maxYear->setCurrentIndex(years.size() - 1);
    }
    ui->numberOfCol->setCurrentIndex(0);
}

MainWindow::~MainWindow() {
    doOperation(&context, FREE);
    delete ui;
}
