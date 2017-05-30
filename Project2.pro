#-------------------------------------------------
#
# Project created by QtCreator 2017-04-27T21:37:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    army.cpp \
    castle.cpp \
    battle.cpp \
    ai.cpp \
    minion.cpp \
    mouserange.cpp \
    rank.cpp \
    rolling.cpp

HEADERS  += mainwindow.h \
    scene.h \
    army.h \
    castle.h \
    battle.h \
    ai.h \
    minion.h \
    mouserange.h \
    rank.h \
    rolling.h

FORMS    += mainwindow.ui

RESOURCES += \
    img/img.qrc

DISTFILES += \
    Rank/Rank.txt
