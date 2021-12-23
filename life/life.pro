QT += widgets

TEMPLATE = lib
DEFINES += ATOMLIFE_LIBRARY
CONFIG += c++11

TARGET = life

macx {
    ROOTPATH = $$PWD/../../bin
    APPPATH = $$ROOTPATH/gkf.app/Contents/MacOS
    PLUGINPATH = $$APPPATH/plugin
    DESTDIR = $$PLUGINPATH/$$TARGET
}

win32 {
    ROOTPATH = $$PWD/../../bin
    ROOTPATH ~= s,/,\\,g

    PLUGINPATH = $$ROOTPATH/plugin
    PLUGINPATH ~= s,/,\\,g

    SRC_DIR = $$PWD
    SRC_DIR ~= s,/,\\,g

    DESTDIR = $${PLUGINPATH}\\$${TARGET}
}


INCLUDEPATH += \
    ../framework

SOURCES += \
    atomlife.cpp \

HEADERS += \
    atomlife_global.h \
    atomlife.h \
    icontext.h \
    iplugin.h \
    iwindow.h \
    ilog.h \
    imq.h \
    imessage.h \
    ilife.h \
    istorage.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

