QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    httpmanager.cpp \
    main.cpp \
    dashboardwindow.cpp \
    todomodel.cpp

HEADERS += \
    dashboardwindow.h \
    todomodel.h \
    httpmanager.h

FORMS += \
    dashboardwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    PhotoFrame.qrc \
    images.qrc

DISTFILES += \
    19488752_1501993383192064_4566436695561068900_o.jpg \
    37185133_1890616464329752_8201941175058300928_o.jpg \
    37715743_1900109846713747_9207013816389337088_o.jpg \
    39347_101496846575065_5129752_n.jpg \
    418383_316157708442310_1953668505_n.jpg \
    423690_322467191144695_1612927000_n.jpg \
    PhotoFrame/19488752_1501993383192064_4566436695561068900_o.jpg \
    PhotoFrame/37185133_1890616464329752_8201941175058300928_o.jpg \
    PhotoFrame/37715743_1900109846713747_9207013816389337088_o.jpg \
    PhotoFrame/39347_101496846575065_5129752_n.jpg \
    PhotoFrame/418383_316157708442310_1953668505_n.jpg \
    PhotoFrame/423690_322467191144695_1612927000_n.jpg \
    cloudy.png \
    drizzle.png \
    partlysunny.png \
    rainy.png \
    snowy.png \
    sunny.png
