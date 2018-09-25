TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bubble.cpp \
    createfile.cpp \
    insertion.cpp \
    merge.cpp \
    run.cpp \
    sort.cpp \
    adjmatrix.cpp \
    adjlist.cpp \
    bfs.cpp \
    bfsr.cpp \
    dfs.cpp \
    dfsr.cpp \
    astar.cpp \
    dijkstra.cpp

HEADERS += \
    algorithm.h \
    bubble.h \
    createfile.h \
    insertion.h \
    merge.h \
    run.h \
    sort.h \
    sortbehavior.h \
    adjmatrix.h \
    adjlist.h \
    bfs.h \
    bfsr.h \
    dfs.h \
    dfsr.h \
    astar.h \
    dijkstra.h \
    pathbehavior.h
