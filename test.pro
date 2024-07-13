TEMPLATE = app
CONFIG += console c++17
CONFIG += app_bundle
CONFIG += qt

QT += sql

SOURCES += \
        scooter-test.cpp \
        scooter_management.cpp

HEADERS += \
    scooter_management.h
