QT       += core gui multimedia

CONFIG += c++11
DESTDIR = $$PWD/bin

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerDefense
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \   
    audioplayer.cpp \    
    endwindow.cpp \
    startwindow.cpp


HEADERS  += mainwindow.h \
    audioplayer.h \  
    endwindow.h \
    startwindow.h

FORMS    += mainwindow.ui \  
    endwindow.ui \
    startwindow.ui

RESOURCES += \
    resource.qrc


DISTFILES +=
