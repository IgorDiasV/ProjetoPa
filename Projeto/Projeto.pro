TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        cutbox.cpp \
        cutvoxel.cpp \
        figurageometrica.cpp \
        main.cpp \
        putbox.cpp \
        putsphere.cpp \
        putvoxel.cpp \
        sculptor.cpp

HEADERS += \
    classes.h \
    cutbox.h \
    cutvoxel.h \
    figurageometrica.h \
    putbox.h \
    putsphere.h \
    putvoxel.h \
    sculptor.h

DISTFILES += \
    Projeto.pro.user
