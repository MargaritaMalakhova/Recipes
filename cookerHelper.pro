QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 console
#CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        gui/addproducttofridge.cpp \
        main.cpp \
        gui/mainwindow.cpp \
        model/availablereceiptdto.cpp \
        model/ingredientdto.cpp \
        model/receiptdto.cpp \
        model/userproductsdto.cpp \
        gui/receiptdescription.cpp \
        receiptservice.cpp \
        sqlservice.cpp \
        viewservice.cpp

FORMS += \
    gui/addproducttofridge.ui \
    gui/mainwindow.ui \
    gui/receiptdescription.ui

HEADERS += \
    gui/addproducttofridge.h \
    gui/mainwindow.h \
    model/availablereceiptdto.h \
    model/ingredientdto.h \
    model/receiptdto.h \
    model/userproductsdto.h \
    gui/receiptdescription.h \
    receiptservice.h \
    sqlservice.h \
    viewservice.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Добавить содержимое этого файла в конец файла Qt-проекта (файл с расширением .pro) для корректного отображения
# сообщений компилятора MSVC на русском (произойдет перекодировка в CP 1251)
QMAKE_EXTRA_TARGETS += before_build makefilehook

makefilehook.target = $(MAKEFILE)
makefilehook.depends = .beforebuild

PRE_TARGETDEPS += .beforebuild

before_build.target = .beforebuild
before_build.depends = FORCE
before_build.commands = chcp 1251
