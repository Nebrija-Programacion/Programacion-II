TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    worker.cpp \
    doctor.cpp \
    policeman.cpp

HEADERS += \
    worker.h \
    doctor.h \
    policeman.h
