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
    src/igrica1.cpp \
    src/igrica2.cpp \
    src/igrica3.cpp \
    src/lopta.cpp \
    src/main.cpp \
    src/bolt.cpp \
    common/src/tank.cpp \
    common/src/projectile.cpp \
    common/src/invadertank.cpp

HEADERS += \
    headers/bolt.hpp \
    headers/igrica1.hpp \
    headers/igrica2.hpp \
    headers/igrica3.hpp \
    headers/lopta.hpp \
    common/headers/tank.h \
    common/headers/projectile.h \
    common/headers/invadertank.h

FORMS += \
    forms/bolt.ui \
    forms/igrica1.ui \
    forms/igrica2.ui \
    forms/igrica3.ui

RESOURCES += \
    bolt.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
