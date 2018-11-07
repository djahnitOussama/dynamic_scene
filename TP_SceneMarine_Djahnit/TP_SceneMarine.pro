#-------------------------------------------------
#
# Project created by QtCreator 2017-11-30T19:39:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TP_SceneMarine
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# on impose que l'exécutable soit dans le répertoire du projet
# pour éviter la recherche du fichier ini et du dossier /img
DESTDIR= $$_PRO_FILE_PWD_

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    elementG.cpp \
    image.cpp \
    imageR.cpp \
    pageG.cpp \
    imageD.cpp \
    bulles.cpp \
    requin.cpp \
    poissonR.cpp \
    poisson.cpp \
    Monpoisson.cpp

HEADERS += \
        mainwindow.h \
    elementG.h \
    image.h \
    imageR.h \
    pageG.h \
    imageD.h \
    bulles.h \
    requin.h \
    poissonR.h \
    poisson.h \
    Monpoisson.h
