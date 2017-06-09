#-------------------------------------------------
#
# Project created by QtCreator 2017-05-12T14:56:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project2
TEMPLATE = app


SOURCES += main.cpp\
    base.cpp \
    mana.cpp \
    basebullet.cpp \
    melee.cpp \
    graphicsview.cpp \
    bluemeleeicon.cpp \
    purplemeleeicon.cpp \
    deck.cpp \
    caster.cpp \
    bluecastericon.cpp \
    purplecastericon.cpp \
    siege.cpp \
    bluesiegeicon.cpp \
    purplesiegeicon.cpp \
    super.cpp \
    bluesupericon.cpp \
    purplesupericon.cpp \
    battleunit.cpp \
    storm.cpp \
    stormicon.cpp \
    button.cpp \
    hero.cpp \
    heroicon.cpp

HEADERS  += \
    base.h \
    mana.h \
    basebullet.h \
    melee.h \
    graphicsview.h \
    bluemeleeicon.h \
    purplemeleeicon.h \
    deck.h \
    caster.h \
    bluecastericon.h \
    purplecastericon.h \
    siege.h \
    bluesiegeicon.h \
    purplesiegeicon.h \
    super.h \
    bluesupericon.h \
    purplesupericon.h \
    battleunit.h \
    storm.h \
    stormicon.h \
    button.h \
    hero.h \
    heroicon.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

DISTFILES += \
    image/storm.gif \
    image/storm.png \
    image/baronicon.jpeg \
    image/baron.png \
    image/tennis.png
