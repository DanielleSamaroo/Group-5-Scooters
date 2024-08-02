QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    account_management.cpp \
    main.cpp \
    mainwindow.cpp \
    myscooters.cpp \
    rentscooter.cpp \
    scooter_management.cpp \
    settingswindow.cpp

HEADERS += \
    account_management.h \
    mainwindow.h \
    myscooters.h \
    rentscooter.h \
    scooter_management.h \
    settingswindow.h

FORMS += \
    mainwindow.ui \
    myscooters.ui \
    rentscooter.ui \
    scooter_management.ui \
    settingswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
