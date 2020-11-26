QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    APIs/APIRequest.cpp \
    AddCard/addcard.cpp \
    AddCard/addcardmain.cpp \
    AddCard/addchoices.cpp \
    AddCard/addtext.cpp \
    Cards/Card.cpp \
    Cards/Choices.cpp \
    Cards/Plain.cpp \
    Cards/Text.cpp \
    Cards/Word.cpp \
    main.cpp \
    test.cpp

HEADERS += \
    APIs/APIRequest.h \
    AddCard/addcard.h \
    AddCard/addcardmain.h \
    AddCard/addchoices.h \
    AddCard/addtext.h \
    Cards/Card.h \
    Cards/Cards.h \
    Cards/Choices.h \
    Cards/Plain.h \
    Cards/Text.h \
    Cards/Word.h \
    test.h

FORMS += \
    AddCard/addcard.ui \
    AddCard/addcardmain.ui \
    AddCard/addchoices.ui \
    AddCard/addtext.ui \
    test.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    AddCard/AddCard.pro \
    AddCard/AddCard.pro

DISTFILES += \
    AddCard/.gitignore \
    AddCard/Cards/Cards.exe \
    AddCard/Cards/make.bat \
    Cards/Cards.exe \
    Cards/make.bat
