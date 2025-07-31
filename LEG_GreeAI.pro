QT       += core gui

#nlohmann-json
INCLUDEPATH += $$PWD/lib/json-develop/include

#eSpeak-NG
INCLUDEPATH += $$PWD/lib/espeak-ng/src/include
LIBS += -L"$$PWD/lib" -lespeak-ng

win32 {
    QMAKE_POST_LINK += $$quote(cmd /c copy /Y $$PWD/lib/libespeak-ng.dll $$OUT_PWD$$escape_expand(\n\t))
    QMAKE_POST_LINK += $$quote(cmd /c xcopy /E /Y $$PWD/lib/espeak-ng/espeak-ng-data $$OUT_PWD/espeak-ng-data$$escape_expand(\n\t))
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/addword.cpp \
    src/cardsui.cpp \
    src/main.cpp \
    src/leg.cpp \
    src/processingCards.cpp \

HEADERS += \
    src/SR.h \
    src/addword.h \
    src/cards.h \
    src/cardsui.h \
    src/eSpeakNG.h \
    src/leg.h \
    src/processingCards.h

FORMS += \
    src/addword.ui \
    src/cardsui.ui \
    src/leg.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
