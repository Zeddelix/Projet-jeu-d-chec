QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cavalier.cpp \
        dame.cpp \
        fenetreconnexion.cpp \
        fou.cpp \
        main.cpp \
        partie.cpp \
        piece.cpp \
        pion.cpp \
        roi.cpp \
        tour.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    cavalier.h \
    dame.h \
    fenetreconnexion.h \
    fou.h \
    partie.h \
    piece.h \
    pion.h \
    roi.h \
    tour.h

QT += widgets

DISTFILES += \
    CavalierBlanc.png \
    CavalierNoir.png \
    DameBlanc.png \
    DameNoir.png \
    FouBlanc.png \
    FouNoir.png \
    PionBlanc.png \
    PionNoir.png \
    RoiBlanc.png \
    RoiNoir.png \
    TourBlanc.png \
    TourNoir.png
