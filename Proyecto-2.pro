QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    algebralinealnumerica.cpp \
    evaluarpuntodialog.cpp \
    main.cpp \
    mainwindow.cpp \
    matriz.cpp \
    opcionesgrafica.cpp \
    punto.cpp \
    qcustomplot.cpp \
    regresionl.cpp

HEADERS += \
    algebralinealnumerica.h \
    evaluarpuntodialog.h \
    mainwindow.h \
    matriz.h \
    opcionesgrafica.h \
    punto.h \
    qcustomplot.h \
    regresionl.h

FORMS += \
    evaluarpuntodialog.ui \
    mainwindow.ui \
    opcionesgrafica.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
