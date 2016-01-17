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
    intesection.cpp \
    convexpolygone.cpp \
    union.cpp \
    segment.cpp \
    rectangle.cpp \
    commandlineinterface.cpp \
    point.cpp

HEADERS += draw.h \
    form.h \
    intesection.h \
    convexpolygone.h \
    union.h \
    segment.h \
    rectangle.h \
    commandlineinterface.h \
    point.h
