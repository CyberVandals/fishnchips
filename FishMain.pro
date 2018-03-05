#-------------------------------------------------
#
# Project created by QtCreator 2018-02-20T17:04:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FishMain
TEMPLATE = app

INCLUDEPATH += inc/ \
 #       src/chaeunkim \
 #       src/gigiyoung \
  #      src/henry \
   #     src/koffi \
    #    src/wei \

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
        src/chaeunkim/main.cpp \
        src/chaeunkim/mainwindow.cpp \
        src/chaeunkim/button.cpp \
#	src/chaeunkim/scenemanager.cpp\
        src/chaeunkim/pausebutton.cpp\
        src/gigiyoung/gy_banana.cpp \
        src/gigiyoung/gy_exit.cpp \
        src/gigiyoung/gy_platform.cpp \
        src/gigiyoung/gy_shark.cpp \
        src/gigiyoung/gy_steam.cpp \
        src/henry/hh_main_player.cpp \
#        src/henry/hh_health.cpp
        src/wei/graphics.cpp \
    src/henry/hh_health.cpp \
    src/henry/hh_health_bar.cpp \
    src/chaeunkim/ck_button.cpp \
    src/chaeunkim/ck_main.cpp \
    src/chaeunkim/ck_mainwindow.cpp \
    src/chaeunkim/ck_pausebutton.cpp \
    src/matthew/soundmanager.cpp    \
    src/koffi/kk_scenemanager   \
    src/koffi/kk_gamelevel.cpp  \
    src/koffi/kk_gamescene.cpp  \


HEADERS  += \
        inc/chaeunkim/button.h \
        inc/chaeunkim/mainwindow.h \
	inc/chaeunkim/pausebutton.h\
#	inc/chaeunkim/scenemanager.h\
        inc/gigiyoung/gy_object.h \
        inc/henry/hh_main_player.h \
#        inc/henry/hh_health.h
        inc/wei/graphics.h \
    inc/henry/hh_health.h \
    inc/henry/hh_health_bar.h \
    inc/chaeunkim/ck_button.h \
    inc/chaeunkim/ck_pausebutton.h \
    inc/matthew/soundmanager.h \
    inc/wei/wz_graphics.h \
    inc/ck_mainwindow.h \
#        config/constants.h
    inc/kk_scenemanager.h   \
    inc/koffi/kk_gamelevel.h    \
    inc/koffi/kk_gamescen.h \
    inc/koffi/kk_scene.h    \
    inc/koffi/config.h  \


RESOURCES += \
        resources/images/images.qrc
