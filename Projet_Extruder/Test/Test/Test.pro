#-------------------------------------------------
#
# Project created by QtCreator 2016-06-02T23:49:23
#
#-------------------------------------------------

QT       += core gui
QT += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glview.cpp

HEADERS  += mainwindow.h \
    glview.h

FORMS    += mainwindow.ui
