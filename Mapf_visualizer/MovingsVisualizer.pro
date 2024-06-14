#-------------------------------------------------
#
# Project created by QtCreator 2016-06-28T11:46:35
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MovingsVisualizer
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        mainwindow.cpp \
    agent.cpp \
    settings.cpp

HEADERS  += mainwindow.h \
    agent.h \
    settings.h

FORMS    += mainwindow.ui \
    settings.ui
