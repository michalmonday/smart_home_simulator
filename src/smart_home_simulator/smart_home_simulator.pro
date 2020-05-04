#-------------------------------------------------
#
# Project created by QtCreator 2019-11-11T12:48:59
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = smart_home_simulator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    controller_screen.cpp \
    creator.cpp \
    graphics_item.cpp \
    graphics_scene.cpp \
    grid.cpp \
    polygon_creator.cpp \
    press_and_drag_creator.cpp \
    sd_controlscreen.cpp \
    sd_doorbell.cpp \
    sd_light.cpp \
    sd_powersocket.cpp \
    smart_device.cpp \
    smart_device_creator.cpp \
    zoom.cpp \
    actor.cpp \
    actor_player.cpp \
    environment_window.cpp \
    sun_colour.cpp \
    tutorial.cpp \
    sd_speakers.cpp \
    audio.cpp \
    sd_radiator.cpp \
    weather.cpp \
    range_indicator.cpp \
    sd_thermometer.cpp \
    sd_infra_red_sensor.cpp \
    sd_toilet.cpp \
    sd_fan.cpp \
    sd_blinds.cpp

HEADERS += \
        mainwindow.h \
    controller_screen.h \
    creator.h \
    graphics_item.h \
    graphics_scene.h \
    grid.h \
    polygon_creator.h \
    press_and_drag_creator.h \
    sd_controlscreen.h \
    sd_doorbell.h \
    sd_light.h \
    sd_powersocket.h \
    smart_device.h \
    smart_device_creator.h \
    ui_controller_screen.h \
    ui_mainwindow.h \
    zoom.h \
    actor.h \
    actor_player.h \
    environment_window.h \
    sun_colour.h \
    tutorial.h \
    sd_speakers.h \
    audio.h \
    sd_radiator.h \
    weather.h \
    range_indicator.h \
    sd_thermometer.h \
    sd_infra_red_sensor.h \
    sd_toilet.h \
    sd_fan.h \
    sd_blinds.h

FORMS += \
        mainwindow.ui \
    controller_screen.ui \
    environment_window.ui \
    tutorial.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    smart_home_simulator.pro

DISTFILES += \
    smart_home_simulator.pro.user
