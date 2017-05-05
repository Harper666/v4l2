#-------------------------------------------------
#
# Project created by QtCreator 2017-04-26T18:57:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CFLAGS   = -std=c99
QMAKE_CXXFLAGS = -std=c++0x

TARGET = v4l2
TEMPLATE = app

#LIBS += /usr/local/lib/*.so
#INCLUDEPATH = /usr/local/include

#LIBS += /usr/local/arm/opencv-2.4.13/share/lib/*.so
#INCLUDEPATH = /usr/local/arm/opencv-2.4.13/static/include

SOURCES += main.cpp\
        dialog.cpp \
    v4l2_init.cpp

HEADERS  += dialog.h \
    v4l2_init.h

FORMS    += dialog.ui
