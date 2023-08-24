QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    front/calc/mainwindow.ui \
    front/credit/creditcalc.ui \
    front/deposit/depositcalc.ui \
    front/graphics/drawgraphics.ui

HEADERS += \
    back/calc/mainwindow.h \
    back/credit/creditcalc.h \
    back/deposit/depositcalc.h \
    back/graphics/drawgraphics.h \
    back/polish/polish.h \
    back/polish/stack.h \
    back/polish/tokenize.h \
    back/qcustomplot/qcustomplot.h

SOURCES += \
    back/calc/mainwindow.cpp \
    back/credit/creditcalc.cpp \
    back/deposit/depositcalc.cpp \
    back/graphics/drawgraphics.cpp \
    back/main.cpp \
    back/polish/polish.c \
    back/polish/stack.c \
    back/polish/tokenize.c \
    back/qcustomplot/qcustomplot.cpp

