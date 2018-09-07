TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bubble.cpp \
    createfile.cpp \
    insertion.cpp \
    merge.cpp \
    sort.cpp \
    run.cpp

HEADERS += \
    algorithm.h \
    bubble.h \
    createfile.h \
    insertion.h \
    merge.h \
    sort.h \
    run.h
