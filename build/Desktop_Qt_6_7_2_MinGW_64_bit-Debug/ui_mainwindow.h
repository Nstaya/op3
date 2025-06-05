/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *loadData;
    QTextBrowser *fileName;
    QLabel *label_3;
    QLabel *label_5;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *selectFile;
    QPushButton *calculateAndDraw;
    QLabel *label_4;
    QTableWidget *outputMetrics;
    QLabel *label_6;
    QWidget *graphWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *applyFilterYears;
    QComboBox *region;
    QComboBox *numberOfCol;
    QComboBox *minYear;
    QComboBox *maxYear;
    QLabel *label_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1205, 875);
        QPalette palette;
        QBrush brush(QColor(118, 79, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(200, 252, 191, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(227, 253, 223, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(100, 126, 95, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(133, 168, 127, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        QBrush brush6(QColor(117, 78, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        QBrush brush8(QColor(215, 164, 45, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush8);
        QBrush brush9(QColor(202, 154, 42, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush9);
        QBrush brush10(QColor(131, 100, 28, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush10);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush11(QColor(255, 255, 220, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush11);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
        QBrush brush12(QColor(0, 0, 0, 127));
        brush12.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush11);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
        QBrush brush13(QColor(100, 126, 95, 127));
        brush13.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush2);
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        loadData = new QPushButton(centralwidget);
        loadData->setObjectName("loadData");
        loadData->setGeometry(QRect(30, 270, 151, 41));
        fileName = new QTextBrowser(centralwidget);
        fileName->setObjectName("fileName");
        fileName->setGeometry(QRect(30, 120, 151, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 180, 141, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(800, 0, 71, 20));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(460, 30, 721, 351));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 141, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 90, 101, 20));
        selectFile = new QPushButton(centralwidget);
        selectFile->setObjectName("selectFile");
        selectFile->setGeometry(QRect(30, 40, 151, 41));
        calculateAndDraw = new QPushButton(centralwidget);
        calculateAndDraw->setObjectName("calculateAndDraw");
        calculateAndDraw->setGeometry(QRect(30, 410, 151, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 320, 171, 21));
        outputMetrics = new QTableWidget(centralwidget);
        outputMetrics->setObjectName("outputMetrics");
        outputMetrics->setGeometry(QRect(680, 410, 321, 61));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(800, 380, 81, 20));
        graphWidget = new QWidget(centralwidget);
        graphWidget->setObjectName("graphWidget");
        graphWidget->setGeometry(QRect(50, 480, 1121, 301));
        graphWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayoutWidget = new QWidget(graphWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 1121, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        applyFilterYears = new QPushButton(centralwidget);
        applyFilterYears->setObjectName("applyFilterYears");
        applyFilterYears->setGeometry(QRect(260, 120, 93, 29));
        region = new QComboBox(centralwidget);
        region->setObjectName("region");
        region->setGeometry(QRect(30, 210, 151, 41));
        numberOfCol = new QComboBox(centralwidget);
        numberOfCol->setObjectName("numberOfCol");
        numberOfCol->setGeometry(QRect(30, 350, 151, 41));
        minYear = new QComboBox(centralwidget);
        minYear->setObjectName("minYear");
        minYear->setGeometry(QRect(200, 70, 101, 31));
        maxYear = new QComboBox(centralwidget);
        maxYear->setObjectName("maxYear");
        maxYear->setGeometry(QRect(310, 70, 91, 31));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(290, 40, 41, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1205, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loadData->setText(QCoreApplication::translate("MainWindow", "Load data", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\265\320\263\320\270\320\276\320\275", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\260\320\271\320\273", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213 \320\262\321\213\320\261\321\200\320\260\320\273\320\270:", nullptr));
        selectFile->setText(QCoreApplication::translate("MainWindow", "Select file", nullptr));
        calculateAndDraw->setText(QCoreApplication::translate("MainWindow", "Calculate and Draw", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \342\204\226 \321\201\321\202\320\276\320\273\320\261\321\206\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        applyFilterYears->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\320\264\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
