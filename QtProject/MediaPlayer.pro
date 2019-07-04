#-------------------------------------------------
#
# Project created by QtCreator 2017-05-10T15:52:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MediaPlayer
TEMPLATE = app

LIBS += -lfftw3f -ljack -lsndfile -lGL

#INCLUDEPATH += /usr/include


SOURCES += main.cpp\
        mainwindow.cpp \
    jack.cpp \
    dspsystem.cpp \
    controlvolume.cpp \
    oscillator.cpp \
    doscillator.cpp \
    utils.cpp \
    vectoroperations.cpp \
    simplefilter.cpp \
    megafilter.cpp \
    doublefilter.cpp

HEADERS  += mainwindow.h \
            jack.h \
            processor.h \
            dspsystem.h \
    controlvolume.h \
    oscillator.h \
    constants.h \
    doscillator.h \
    utils.h \
    vectoroperations.h \
    simplefilter.h \
    megafilter.h \
    doublefilter.h

FORMS    += mainwindow.ui
