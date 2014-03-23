#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T18:37:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = assignment_1
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    ball.cpp \
    coordinate.cpp \
    configuration.cpp

HEADERS  += dialog.h \
    ball.h \
    coordinate.h \
    configuration.h

FORMS    += dialog.ui

OTHER_FILES += \
    .config
