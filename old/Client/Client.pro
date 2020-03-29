#-------------------------------------------------
#
# Project created by QtCreator 2016-07-05T15:11:06
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += /usr/lib/libcrypto++.a

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        client.cpp \
    logindialog.cpp \
    sslclient.cpp \
    mycrypt.cpp \
    myserver.cpp \
    myclient.cpp \
    chatwindow.cpp

HEADERS  += client.h \
    logindialog.h \
    sslclient.h \
    mycrypt.h \
    myserver.h \
    myclient.h \
    chatwindow.h

FORMS    += client.ui \
    logindialog.ui \
    chatwindow.ui
