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
    segment.cpp \
    rectangle.cpp \
    commandlineinterface.cpp \
    point.cpp \
    ensemble.cpp

HEADERS += draw.h \
    form.h \
    convexpolygone.h \
    segment.h \
    rectangle.h \
    commandlineinterface.h \
    point.h \
    config.h \
    ensemble.h
