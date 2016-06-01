#-------------------------------------------------
#
# Project created by QtCreator 2016-05-26T10:00:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AngryBird-MageVersion
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    GameView.cpp \
    GameScene/GameScene.cpp \
    GameScene/Singleshot.cpp \
    GameScene/GameEngine.cpp \
    GameScene/AbsClasses/GameItem.cpp \
    GameScene/AbsClasses/AbsBird.cpp \
    GameScene/Birds/RedBird.cpp \
    GameScene/RandomItems/Ground.cpp \
    GameScene/RandomItems/Stick.cpp \
    GameScene/CollisionListener.cpp \
    GameScene/RandomItems/Stick_Hrz.cpp \
    GameScene/RandomItems/Block_Vtl.cpp

HEADERS  += MainWindow.h \
    GameView.h \
    GameScene/GameScene.h \
    GameScene/Singleshot.h \
    GameScene/GameEngine.h \
    GameScene/AbsClasses/GameItem.h \
    GameScene/AbsClasses/AbsBird.h \
    GameScene/Birds/RedBird.h \
    GameScene/RandomItems/Ground.h \
    GameScene/RandomItems/Stick.h \
    GameScene/CollisionListener.h \
    GameScene/RandomItems/Stick_Hrz.h \
    GameScene/RandomItems/Block_Vtl.h

INCLUDEPATH += /usr/local/lib
LIBS += -L /usr/local/lib/
LIBS += -lBox2D
