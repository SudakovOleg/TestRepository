#-------------------------------------------------
#
# Project created by QtCreator 2016-08-31T14:58:19
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_myunittest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_myunittest.cpp \
    myclass.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    myclass.h
