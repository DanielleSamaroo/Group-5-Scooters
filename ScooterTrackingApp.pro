QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    account_management.cpp \
    main.cpp \
    mainwindow.cpp \
    rentscooter.cpp \
    scooter_management.cpp

HEADERS += \
    account_management.h \
    mainwindow.h \
    rentscooter.h \
    scooter_management.h

FORMS += \
    mainwindow.ui \
    rentscooter.ui \
    scooter_management.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
