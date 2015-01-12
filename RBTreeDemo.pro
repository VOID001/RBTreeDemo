#-------------------------------------------------
#
# Project created by QtCreator 2015-01-11T15:04:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RBTreeDemo
TEMPLATE = app


SOURCES += main.cpp\
        rbtreedemowindow.cpp \
    rbnode.cpp \
    rbtree.cpp \
    rblink.cpp

HEADERS  += rbtreedemowindow.h \
    rbnode.h \
    rbtree.h \
    comm.h \
    rblink.h

FORMS    += rbtreedemowindow.ui
