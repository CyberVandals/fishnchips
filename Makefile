#############################################################################
# Makefile for building: FishMain
# Generated by qmake (3.0) (Qt 5.5.1)
# Project:  FishMain.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt5/bin/qmake -o Makefile FishMain.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_MULTIMEDIA_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -Iinc -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtMultimedia -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtNetwork -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64
QMAKE         = /usr/lib/x86_64-linux-gnu/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = FishMain1.0.0
DISTDIR = /home/gigi/Courses/cs383/fishnchips/.tmp/FishMain1.0.0
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS) -L/usr/X11R6/lib64 -lQt5Widgets -lQt5Multimedia -lQt5Gui -lQt5Network -lQt5Core -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/chaeunkim/ck_main.cpp \
		src/chaeunkim/ck_mainwindow.cpp \
		src/chaeunkim/ck_button.cpp \
		src/chaeunkim/ck_pausebutton.cpp \
		src/gigiyoung/gy_abstract.cpp \
		src/gigiyoung/gy_autotest.cpp \
		src/gigiyoung/gy_banana.cpp \
		src/gigiyoung/gy_exit.cpp \
		src/gigiyoung/gy_objecthandler.cpp \
		src/gigiyoung/gy_platform.cpp \
		src/gigiyoung/gy_shark.cpp \
		src/gigiyoung/gy_steam.cpp \
		src/henry/hh_main_player.cpp \
		src/henry/hh_health.cpp \
		src/henry/hh_health_bar.cpp \
		src/koffi/kk_gamelevel.cpp \
		src/koffi/kk_gamescene.cpp \
		src/koffi/kk_scenemanager.cpp \
		src/matthew/mm_soundmanager.cpp \
		src/wei/wz_graphics.cpp \
		src/chaeunkim/ck_pausescreen.cpp \
		src/henry/hh_oxygen.cpp qrc_images.cpp \
		qrc_sounds.cpp \
		qrc_levels.cpp \
		moc_ck_mainwindow.cpp \
		moc_ck_button.cpp \
		moc_ck_pausebutton.cpp \
		moc_gy_autotest.cpp \
		moc_gy_object.cpp \
		moc_gy_abstract.cpp \
		moc_hh_main_player.cpp \
		moc_hh_oxygen.cpp
OBJECTS       = ck_main.o \
		ck_mainwindow.o \
		ck_button.o \
		ck_pausebutton.o \
		gy_abstract.o \
		gy_autotest.o \
		gy_banana.o \
		gy_exit.o \
		gy_objecthandler.o \
		gy_platform.o \
		gy_shark.o \
		gy_steam.o \
		hh_main_player.o \
		hh_health.o \
		hh_health_bar.o \
		kk_gamelevel.o \
		kk_gamescene.o \
		kk_scenemanager.o \
		mm_soundmanager.o \
		wz_graphics.o \
		ck_pausescreen.o \
		hh_oxygen.o \
		qrc_images.o \
		qrc_sounds.o \
		qrc_levels.o \
		moc_ck_mainwindow.o \
		moc_ck_button.o \
		moc_ck_pausebutton.o \
		moc_gy_autotest.o \
		moc_gy_object.o \
		moc_gy_abstract.o \
		moc_hh_main_player.o \
		moc_hh_oxygen.o
DIST          = /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		FishMain.pro inc/ck_mainwindow.h \
		inc/chaeunkim/ck_button.h \
		inc/chaeunkim/ck_pausebutton.h \
		inc/gy_autotest.h \
		inc/gy_object.h \
		inc/gy_objecthandler.h \
		inc/gigiyoung/gy_abstract.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/kk_scenemanager.h \
		inc/koffi/kk_config.h \
		inc/koffi/kk_gamelevel.h \
		inc/koffi/kk_gamescene.h \
		inc/koffi/kk_scene.h \
		inc/wz_graphics.h \
		inc/chaeunkim/ck_pausescreen.h \
		inc/henry/hh_oxygen.h \
		inc/mm_soundmanager.h \
		inc/koffi/gamecontroller.h \
		inc/koffi/kk_levelitem.h src/chaeunkim/ck_main.cpp \
		src/chaeunkim/ck_mainwindow.cpp \
		src/chaeunkim/ck_button.cpp \
		src/chaeunkim/ck_pausebutton.cpp \
		src/gigiyoung/gy_abstract.cpp \
		src/gigiyoung/gy_autotest.cpp \
		src/gigiyoung/gy_banana.cpp \
		src/gigiyoung/gy_exit.cpp \
		src/gigiyoung/gy_objecthandler.cpp \
		src/gigiyoung/gy_platform.cpp \
		src/gigiyoung/gy_shark.cpp \
		src/gigiyoung/gy_steam.cpp \
		src/henry/hh_main_player.cpp \
		src/henry/hh_health.cpp \
		src/henry/hh_health_bar.cpp \
		src/koffi/kk_gamelevel.cpp \
		src/koffi/kk_gamescene.cpp \
		src/koffi/kk_scenemanager.cpp \
		src/matthew/mm_soundmanager.cpp \
		src/wei/wz_graphics.cpp \
		src/chaeunkim/ck_pausescreen.cpp \
		src/henry/hh_oxygen.cpp
QMAKE_TARGET  = FishMain
DESTDIR       = #avoid trailing-slash linebreak
TARGET        = FishMain


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: FishMain.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		FishMain.pro \
		resources/images/images.qrc \
		resources/images/sounds.qrc \
		resources/levels/levels.qrc \
		/usr/lib/x86_64-linux-gnu/libQt5Widgets.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Multimedia.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Gui.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Network.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Core.prl
	$(QMAKE) -o Makefile FishMain.pro
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimedia.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_multimediawidgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
FishMain.pro:
resources/images/images.qrc:
resources/images/sounds.qrc:
resources/levels/levels.qrc:
/usr/lib/x86_64-linux-gnu/libQt5Widgets.prl:
/usr/lib/x86_64-linux-gnu/libQt5Multimedia.prl:
/usr/lib/x86_64-linux-gnu/libQt5Gui.prl:
/usr/lib/x86_64-linux-gnu/libQt5Network.prl:
/usr/lib/x86_64-linux-gnu/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile FishMain.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents resources/images/images.qrc resources/images/sounds.qrc resources/levels/levels.qrc $(DISTDIR)/
	$(COPY_FILE) --parents inc/ck_mainwindow.h inc/chaeunkim/ck_button.h inc/chaeunkim/ck_pausebutton.h inc/gy_autotest.h inc/gy_object.h inc/gy_objecthandler.h inc/gigiyoung/gy_abstract.h inc/hh_main_player.h inc/henry/hh_health.h inc/henry/hh_health_bar.h inc/kk_scenemanager.h inc/koffi/kk_config.h inc/koffi/kk_gamelevel.h inc/koffi/kk_gamescene.h inc/koffi/kk_scene.h inc/wz_graphics.h inc/chaeunkim/ck_pausescreen.h inc/henry/hh_oxygen.h inc/mm_soundmanager.h inc/koffi/gamecontroller.h inc/koffi/kk_levelitem.h $(DISTDIR)/
	$(COPY_FILE) --parents src/chaeunkim/ck_main.cpp src/chaeunkim/ck_mainwindow.cpp src/chaeunkim/ck_button.cpp src/chaeunkim/ck_pausebutton.cpp src/gigiyoung/gy_abstract.cpp src/gigiyoung/gy_autotest.cpp src/gigiyoung/gy_banana.cpp src/gigiyoung/gy_exit.cpp src/gigiyoung/gy_objecthandler.cpp src/gigiyoung/gy_platform.cpp src/gigiyoung/gy_shark.cpp src/gigiyoung/gy_steam.cpp src/henry/hh_main_player.cpp src/henry/hh_health.cpp src/henry/hh_health_bar.cpp src/koffi/kk_gamelevel.cpp src/koffi/kk_gamescene.cpp src/koffi/kk_scenemanager.cpp src/matthew/mm_soundmanager.cpp src/wei/wz_graphics.cpp src/chaeunkim/ck_pausescreen.cpp src/henry/hh_oxygen.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

compiler_rcc_make_all: qrc_images.cpp qrc_sounds.cpp qrc_levels.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_images.cpp qrc_sounds.cpp qrc_levels.cpp
qrc_images.cpp: resources/images/images.qrc \
		resources/images/replay.png \
		resources/images/door.png \
		resources/images/pause.png \
		resources/images/platform_.png \
		resources/images/continue.png \
		resources/images/monkey.png \
		resources/images/menu_background.jpg \
		resources/images/back_ground.jpg \
		resources/images/play3.png \
		resources/images/GameOverS.png \
		resources/images/stressBtn.png \
		resources/images/steam.png \
		resources/images/demoBtn.png \
		resources/images/quit3.png \
		resources/images/blue_shark.png \
		resources/images/dark_shark.png \
		resources/images/banana.png \
		resources/images/icon_shark.png
	/usr/lib/x86_64-linux-gnu/qt5/bin/rcc -name images resources/images/images.qrc -o qrc_images.cpp

qrc_sounds.cpp: resources/images/sounds.qrc \
		resources/sounds/pickup.mp3 \
		resources/sounds/throw.mp3 \
		resources/sounds/hit.mp3 \
		resources/sounds/die.mp3 \
		resources/sounds/chomp.mp3 \
		resources/sounds/background.mp3 \
		resources/sounds/levelup.mp3 \
		resources/sounds/start.mp3 \
		resources/sounds/steam.mp3 \
		resources/sounds/end.mp3 \
		resources/sounds/bump.mp3 \
		resources/sounds/eat.mp3
	/usr/lib/x86_64-linux-gnu/qt5/bin/rcc -name sounds resources/images/sounds.qrc -o qrc_sounds.cpp

qrc_levels.cpp: resources/levels/levels.qrc \
		resources/levels/level1.txt
	/usr/lib/x86_64-linux-gnu/qt5/bin/rcc -name levels resources/levels/levels.qrc -o qrc_levels.cpp

compiler_moc_header_make_all: moc_ck_mainwindow.cpp moc_ck_button.cpp moc_ck_pausebutton.cpp moc_gy_autotest.cpp moc_gy_object.cpp moc_gy_abstract.cpp moc_hh_main_player.cpp moc_hh_oxygen.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_ck_mainwindow.cpp moc_ck_button.cpp moc_ck_pausebutton.cpp moc_gy_autotest.cpp moc_gy_object.cpp moc_gy_abstract.cpp moc_hh_main_player.cpp moc_hh_oxygen.cpp
moc_ck_mainwindow.cpp: inc/mm_soundmanager.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/wz_graphics.h \
		inc/gy_object.h \
		inc/gigiyoung/gy_abstract.h \
		inc/henry/hh_oxygen.h \
		inc/chaeunkim/ck_button.h \
		inc/chaeunkim/ck_pausebutton.h \
		inc/chaeunkim/ck_pausescreen.h \
		inc/kk_scenemanager.h \
		inc/gy_autotest.h \
		inc/ck_mainwindow.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/gigi/Courses/cs383/fishnchips -I/home/gigi/Courses/cs383/fishnchips/inc -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtMultimedia -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/lib/gcc/x86_64-linux-gnu/5/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include inc/ck_mainwindow.h -o moc_ck_mainwindow.cpp

moc_ck_button.cpp: inc/chaeunkim/ck_button.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/gigi/Courses/cs383/fishnchips -I/home/gigi/Courses/cs383/fishnchips/inc -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtMultimedia -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/lib/gcc/x86_64-linux-gnu/5/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include inc/chaeunkim/ck_button.h -o moc_ck_button.cpp

moc_ck_pausebutton.cpp: inc/chaeunkim/ck_pausebutton.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/gigi/Courses/cs383/fishnchips -I/home/gigi/Courses/cs383/fishnchips/inc -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtMultimedia -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/lib/gcc/x86_64-linux-gnu/5/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include inc/chaeunkim/ck_pausebutton.h -o moc_ck_pausebutton.cpp

moc_gy_autotest.cpp: inc/gy_autotest.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/gigi/Courses/cs383/fishnchips -I/home/gigi/Courses/cs383/fishnchips/inc -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtMultimedia -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/lib/gcc/x86_64-linux-gnu/5/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include inc/gy_autotest.h -o moc_gy_autotest.cpp

moc_gy_object.cpp: inc/wz_graphics.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/henry/hh_oxygen.h \
		inc/gy_object.h \
		inc/mm_soundmanager.h \
		inc/gigiyoung/gy_abstract.h \
		inc/gy_object.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/gigi/Courses/cs383/fishnchips -I/home/gigi/Courses/cs383/fishnchips/inc -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtMultimedia -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/lib/gcc/x86_64-linux-gnu/5/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include inc/gy_object.h -o moc_gy_object.cpp

moc_gy_abstract.cpp: inc/gigiyoung/gy_abstract.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/gigi/Courses/cs383/fishnchips -I/home/gigi/Courses/cs383/fishnchips/inc -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtMultimedia -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/lib/gcc/x86_64-linux-gnu/5/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include inc/gigiyoung/gy_abstract.h -o moc_gy_abstract.cpp

moc_hh_main_player.cpp: inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/wz_graphics.h \
		inc/hh_main_player.h \
		inc/henry/hh_oxygen.h \
		inc/gy_object.h \
		inc/mm_soundmanager.h \
		inc/gigiyoung/gy_abstract.h \
		inc/hh_main_player.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/gigi/Courses/cs383/fishnchips -I/home/gigi/Courses/cs383/fishnchips/inc -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtMultimedia -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/lib/gcc/x86_64-linux-gnu/5/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include inc/hh_main_player.h -o moc_hh_main_player.cpp

moc_hh_oxygen.cpp: inc/henry/hh_oxygen.h
	/usr/lib/x86_64-linux-gnu/qt5/bin/moc $(DEFINES) -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 -I/home/gigi/Courses/cs383/fishnchips -I/home/gigi/Courses/cs383/fishnchips/inc -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtMultimedia -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/lib/gcc/x86_64-linux-gnu/5/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/5/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include inc/henry/hh_oxygen.h -o moc_hh_oxygen.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_header_clean 

####### Compile

ck_main.o: src/chaeunkim/ck_main.cpp inc/ck_mainwindow.h \
		inc/mm_soundmanager.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/wz_graphics.h \
		inc/gy_object.h \
		inc/gigiyoung/gy_abstract.h \
		inc/henry/hh_oxygen.h \
		inc/chaeunkim/ck_button.h \
		inc/chaeunkim/ck_pausebutton.h \
		inc/chaeunkim/ck_pausescreen.h \
		inc/kk_scenemanager.h \
		inc/gy_autotest.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ck_main.o src/chaeunkim/ck_main.cpp

ck_mainwindow.o: src/chaeunkim/ck_mainwindow.cpp inc/ck_mainwindow.h \
		inc/mm_soundmanager.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/wz_graphics.h \
		inc/gy_object.h \
		inc/gigiyoung/gy_abstract.h \
		inc/henry/hh_oxygen.h \
		inc/chaeunkim/ck_button.h \
		inc/chaeunkim/ck_pausebutton.h \
		inc/chaeunkim/ck_pausescreen.h \
		inc/kk_scenemanager.h \
		inc/gy_autotest.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ck_mainwindow.o src/chaeunkim/ck_mainwindow.cpp

ck_button.o: src/chaeunkim/ck_button.cpp inc/chaeunkim/ck_button.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ck_button.o src/chaeunkim/ck_button.cpp

ck_pausebutton.o: src/chaeunkim/ck_pausebutton.cpp inc/chaeunkim/ck_pausebutton.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ck_pausebutton.o src/chaeunkim/ck_pausebutton.cpp

gy_abstract.o: src/gigiyoung/gy_abstract.cpp inc/gigiyoung/gy_abstract.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gy_abstract.o src/gigiyoung/gy_abstract.cpp

gy_autotest.o: src/gigiyoung/gy_autotest.cpp inc/gy_autotest.h \
		inc/gy_objecthandler.h \
		inc/gy_object.h \
		inc/wz_graphics.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/henry/hh_oxygen.h \
		inc/mm_soundmanager.h \
		inc/gigiyoung/gy_abstract.h \
		inc/kk_scenemanager.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gy_autotest.o src/gigiyoung/gy_autotest.cpp

gy_banana.o: src/gigiyoung/gy_banana.cpp inc/gy_object.h \
		inc/wz_graphics.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/henry/hh_oxygen.h \
		inc/mm_soundmanager.h \
		inc/gigiyoung/gy_abstract.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gy_banana.o src/gigiyoung/gy_banana.cpp

gy_exit.o: src/gigiyoung/gy_exit.cpp inc/gy_object.h \
		inc/wz_graphics.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/henry/hh_oxygen.h \
		inc/mm_soundmanager.h \
		inc/gigiyoung/gy_abstract.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gy_exit.o src/gigiyoung/gy_exit.cpp

gy_objecthandler.o: src/gigiyoung/gy_objecthandler.cpp inc/gy_objecthandler.h \
		inc/gy_object.h \
		inc/wz_graphics.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/henry/hh_oxygen.h \
		inc/mm_soundmanager.h \
		inc/gigiyoung/gy_abstract.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gy_objecthandler.o src/gigiyoung/gy_objecthandler.cpp

gy_platform.o: src/gigiyoung/gy_platform.cpp inc/gy_object.h \
		inc/wz_graphics.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/henry/hh_oxygen.h \
		inc/mm_soundmanager.h \
		inc/gigiyoung/gy_abstract.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gy_platform.o src/gigiyoung/gy_platform.cpp

gy_shark.o: src/gigiyoung/gy_shark.cpp inc/gy_object.h \
		inc/wz_graphics.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/henry/hh_oxygen.h \
		inc/mm_soundmanager.h \
		inc/gigiyoung/gy_abstract.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gy_shark.o src/gigiyoung/gy_shark.cpp

gy_steam.o: src/gigiyoung/gy_steam.cpp inc/gy_object.h \
		inc/wz_graphics.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/henry/hh_oxygen.h \
		inc/mm_soundmanager.h \
		inc/gigiyoung/gy_abstract.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gy_steam.o src/gigiyoung/gy_steam.cpp

hh_main_player.o: src/henry/hh_main_player.cpp inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/wz_graphics.h \
		inc/gy_object.h \
		inc/mm_soundmanager.h \
		inc/gigiyoung/gy_abstract.h \
		inc/henry/hh_oxygen.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o hh_main_player.o src/henry/hh_main_player.cpp

hh_health.o: src/henry/hh_health.cpp inc/henry/hh_health.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o hh_health.o src/henry/hh_health.cpp

hh_health_bar.o: src/henry/hh_health_bar.cpp inc/henry/hh_health_bar.h \
		inc/henry/hh_health.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o hh_health_bar.o src/henry/hh_health_bar.cpp

kk_gamelevel.o: src/koffi/kk_gamelevel.cpp inc/koffi/kk_gamelevel.h \
		inc/koffi/kk_levelitem.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o kk_gamelevel.o src/koffi/kk_gamelevel.cpp

kk_gamescene.o: src/koffi/kk_gamescene.cpp inc/koffi/kk_gamescene.h \
		inc/koffi/kk_scene.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o kk_gamescene.o src/koffi/kk_gamescene.cpp

kk_scenemanager.o: src/koffi/kk_scenemanager.cpp inc/gy_autotest.h \
		inc/gy_objecthandler.h \
		inc/gy_object.h \
		inc/wz_graphics.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/henry/hh_oxygen.h \
		inc/mm_soundmanager.h \
		inc/gigiyoung/gy_abstract.h \
		inc/kk_scenemanager.h \
		inc/koffi/kk_gamelevel.h \
		inc/koffi/kk_levelitem.h \
		inc/koffi/kk_gamescene.h \
		inc/koffi/kk_scene.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o kk_scenemanager.o src/koffi/kk_scenemanager.cpp

mm_soundmanager.o: src/matthew/mm_soundmanager.cpp inc/mm_soundmanager.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/wz_graphics.h \
		inc/gy_object.h \
		inc/gigiyoung/gy_abstract.h \
		inc/henry/hh_oxygen.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mm_soundmanager.o src/matthew/mm_soundmanager.cpp

wz_graphics.o: src/wei/wz_graphics.cpp inc/wz_graphics.h \
		inc/hh_main_player.h \
		inc/henry/hh_health.h \
		inc/henry/hh_health_bar.h \
		inc/henry/hh_oxygen.h \
		inc/gy_object.h \
		inc/mm_soundmanager.h \
		inc/gigiyoung/gy_abstract.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o wz_graphics.o src/wei/wz_graphics.cpp

ck_pausescreen.o: src/chaeunkim/ck_pausescreen.cpp inc/chaeunkim/ck_pausescreen.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ck_pausescreen.o src/chaeunkim/ck_pausescreen.cpp

hh_oxygen.o: src/henry/hh_oxygen.cpp inc/henry/hh_oxygen.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o hh_oxygen.o src/henry/hh_oxygen.cpp

qrc_images.o: qrc_images.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_images.o qrc_images.cpp

qrc_sounds.o: qrc_sounds.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_sounds.o qrc_sounds.cpp

qrc_levels.o: qrc_levels.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_levels.o qrc_levels.cpp

moc_ck_mainwindow.o: moc_ck_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ck_mainwindow.o moc_ck_mainwindow.cpp

moc_ck_button.o: moc_ck_button.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ck_button.o moc_ck_button.cpp

moc_ck_pausebutton.o: moc_ck_pausebutton.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ck_pausebutton.o moc_ck_pausebutton.cpp

moc_gy_autotest.o: moc_gy_autotest.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gy_autotest.o moc_gy_autotest.cpp

moc_gy_object.o: moc_gy_object.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gy_object.o moc_gy_object.cpp

moc_gy_abstract.o: moc_gy_abstract.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_gy_abstract.o moc_gy_abstract.cpp

moc_hh_main_player.o: moc_hh_main_player.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_hh_main_player.o moc_hh_main_player.cpp

moc_hh_oxygen.o: moc_hh_oxygen.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_hh_oxygen.o moc_hh_oxygen.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

