#-------------------------------------------------
#
# Project created by QtCreator 2016-07-05T15:10:25
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app

DESTDIR = $$PWD

LIBS += /usr/lib/libcrypto++.a

SOURCES += main.cpp\
        server.cpp \
    myserver.cpp \
    myclient.cpp \
    mytask.cpp \
    clientarray.cpp \
    mycrypt.cpp

HEADERS  += server.h \
    myserver.h \
    myclient.h \
    mytask.h \
    clientarray.h \
    mycrypt.h \
    clientslist.h

FORMS    += server.ui

DISTFILES += \
    cert.crt \
    cert.key
