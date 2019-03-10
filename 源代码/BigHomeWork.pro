#-------------------------------------------------
#
# Project created by QtCreator 2017-09-07T11:07:35
#
#-------------------------------------------------

QT       += core gui
QT       += sql xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BigHomeWork
TEMPLATE = app

RC_ICONS = lu.ico

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    logindialog.cpp \
    register.cpp \
    newid.cpp \
    deskchose.cpp \
    order.cpp \
    administrator.cpp \
    watingfor.cpp \
    comment.cpp \
    waiter.cpp \
    cook.cpp \
    waiterdlg.cpp \
    cookdlg.cpp \
    restaurant.cpp \
    onedish.cpp \
    connection.cpp \
    serve.cpp \
    cooking.cpp \
    managercustomer.cpp \
    customer.cpp \
    desk.cpp \
    managerdish.cpp \
    managerdlg.cpp \
    waiterasswss.cpp \
    cookassess.cpp \
    pay.cpp \
    managerwaiter.cpp \
    newworker.cpp \
    mangercook.cpp \
    newcook.cpp

HEADERS += \
        mainwindow.h \
    logindialog.h \
    connection.h \
    register.h \
    newid.h \
    customer.h \
    deskchose.h \
    desk.h \
    order.h \
    administrator.h \
    dish.h \
    watingfor.h \
    comment.h \
    waiter.h \
    cook.h \
    waiterdlg.h \
    cookdlg.h \
    restaurant.h \
    onedish.h \
    serve.h \
    cooking.h \
    managercustomer.h \
    managerdish.h \
    managerdlg.h \
    waiterasswss.h \
    cookassess.h \
    pay.h \
    managerwaiter.h \
    newworker.h \
    mangercook.h \
    newcook.h \
    change.h

FORMS += \
        mainwindow.ui \
    logindialog.ui \
    register.ui \
    newid.ui \
    deskchose.ui \
    order.ui \
    administrator.ui \
    watingfor.ui \
    comment.ui \
    waiterdlg.ui \
    cookdlg.ui \
    serve.ui \
    cooking.ui \
    managercustomer.ui \
    managerdish.ui \
    managerdlg.ui \
    waiterasswss.ui \
    cookassess.ui \
    pay.ui \
    managerwaiter.ui \
    newworker.ui \
    mangercook.ui \
    newcook.ui

RESOURCES += \
    fromlu.qrc
