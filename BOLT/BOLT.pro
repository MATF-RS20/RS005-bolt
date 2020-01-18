QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -lglut -lGLU

SOURCES += \
    src/gameover.cpp \
    src/boltprojectile.cpp \
    src/bolttank.cpp \
    src/igrica1.cpp \
    src/igrica2.cpp \
    src/igrica3.cpp \
    src/invader.cpp \
    src/main.cpp \
    src/bolt.cpp \
    src/tank.cpp \
    src/projectile.cpp \
    src/invadertank.cpp \
    src/objekat.cpp

HEADERS += \
    headers/gameover.hpp \
    headers/boltprojectile.hpp \
    headers/bolttank.hpp \
    headers/bolt.hpp \
    headers/igrica1.hpp \
    headers/igrica2.hpp \
    headers/igrica3.hpp \
    headers/invader.h \
    headers/tank.h \
    headers/projectile.h \
    headers/invadertank.h \
    headers/objekat.hpp

FORMS += \
    forms/bolt.ui \
    forms/igrica1.ui \
    forms/igrica2.ui \
    forms/igrica3.ui \
    forms/gameover.ui

RESOURCES += \
    bolt.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/sl1.png
