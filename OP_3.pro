QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += \
    include/

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/context.cpp \
    sources/entry_point.cpp \
    sources/graphwidget.cpp \
    sources/iterator.cpp \
    sources/logic.cpp \
    sources/main.cpp \
    sources/mainwindow.cpp \
    sources/memory.cpp \
    sources/utilities.cpp

HEADERS += \
    include/context.hpp \
    include/entry_point.hpp \
    include/graphwidget.hpp \
    include/iterator.hpp \
    include/logic.hpp \
    include/mainwindow.hpp \
    include/memory.hpp \
    include/utilities.hpp

FORMS += \
    ui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
