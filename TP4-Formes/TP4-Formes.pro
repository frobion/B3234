QT += core
QT -= gui

CONFIG += c++11

TARGET = TP4-Formes
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp\
    draw.cpp \
    form.cpp \
    convexpolygone.cpp \
    union.cpp \
    segment.cpp \
    rectangle.cpp \
    commandlineinterface.cpp \
    point.cpp \
    intersection.cpp \
    test.cpp

HEADERS += draw.h \
    form.h \
    convexpolygone.h \
    union.h \
    segment.h \
    rectangle.h \
    commandlineinterface.h \
    point.h \
    intersection.h \
    test.h
