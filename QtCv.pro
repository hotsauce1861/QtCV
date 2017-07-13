#-------------------------------------------------
#
# Project created by QtCreator 2017-05-10T23:26:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 03withqt
TEMPLATE = app

LIBS += -L/usr/opencv/lib/ \
        -lopencv_highgui \
        -lopencv_core \
        -lopencv_imgcodecs \
        -lopencv_calib3d \
        -lopencv_flann \
        -lopencv_photo \
        -lopencv_stitching \
        -lopencv_imgproc \
        -lopencv_photo \
        -lopencv_video \
        -lopencv_videostab \
        -lopencv_videoio \
        -lopencv_features2d

SOURCES += main.cpp \
    inputpicture.cpp \
    mainform.cpp

HEADERS  += \
    inputpicture.hpp \
    mainform.h

RESOURCES += \
    qrc.qrc

FORMS += \
    mainwindow.ui


