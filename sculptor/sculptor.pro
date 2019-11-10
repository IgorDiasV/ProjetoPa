#-------------------------------------------------
#
# Project created by QtCreator 2019-11-01T19:53:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sculptor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        abrirprojeto.cpp \
        cutbox.cpp \
        cutellipsoid.cpp \
        cutsphere.cpp \
        cutvoxel.cpp \
        figurageometrica.cpp \
        main.cpp \
        mainwindow.cpp \
    plotter.cpp \
        putbox.cpp \
        putellipsoid.cpp \
        putsphere.cpp \
        putvoxel.cpp \
        sculptor.cpp \
    definirsculptor.cpp

HEADERS += \
        abrirprojeto.h \
        classes.h \
        cutbox.h \
        cutellipsoid.h \
        cutsphere.h \
        cutvoxel.h \
        figurageometrica.h \
        mainwindow.h \
    plotter.h \
        putbox.h \
        putellipsoid.h \
        putsphere.h \
        putvoxel.h \
        sculptor.h \
    definirsculptor.h

FORMS += \
        mainwindow.ui \
    definirsculptor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    sculptor.pro.user
