#-------------------------------------------------
#
# Project created by QtCreator 2017-06-29T17:07:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 30
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    treec.cpp \
    drop.cpp \
    de.cpp \
    push.cpp \
    book.cpp \
    huaji.cpp \
    hb.cpp \
    hat.cpp \
    cd.cpp \
    bzwd.cpp

HEADERS += \
        widget.h \
    treec.h \
    drop.h \
    de.h \
    push.h \
    book.h \
    huaji.h \
    hb.h \
    hat.h \
    cd.h \
    bzwd.h

FORMS += \
        widget.ui \
    treec.ui \
    cd.ui \
    bzwd.ui

RESOURCES += \
    picture.qrc
