TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += widgets gui
OBJECTS_DIR = obj

SOURCES += \
        src/qt/main_qt.cpp \
        src/qt/mainWindow.cpp \
        src/qt/extensions/mainView.cpp \
        src/qt/extensions/sideBar.cpp \
        src/qt/extensions/components/mainView/Board_qt.cpp \
        src/qt/extensions/components/mainView/Tile_qt.cpp \
        src/qt/extensions/components/mainView/Lobby.cpp \
        src/qt/extensions/components/sideBar/Controllers.cpp \
        src/qt/extensions/components/sideBar/Dice_qt.cpp \
        src/qt/extensions/components/sideBar/Players.cpp \
        src/qt/extensions/components/sideBar/Player_qt.cpp \
        src/core/Board.cpp \
        src/core/Dice.cpp \
        src/core/Game.cpp \
        src/core/Gare.cpp \
        src/core/Inventory.cpp \
        src/core/Player.cpp \
        src/core/Property.cpp \
    src/core/Tile.cpp \

HEADERS += \
        src/qt/mainWindow.h \
        src/qt/extensions/mainView.h \
        src/qt/extensions/sideBar.h \
        src/qt/extensions/components/mainView/Board_qt.h \
        src/qt/extensions/components/mainView/Tile_qt.h \
        src/qt/extensions/components/mainView/Lobby.h \        
        src/qt/extensions/components/sideBar/Controllers.h \
        src/qt/extensions/components/sideBar/Dice_qt.h \
        src/qt/extensions/components/sideBar/Players.h \
        src/qt/extensions/components/sideBar/Player_qt.h \
        src/core/Board.h \
        src/core/Dice.h \
        src/core/Game.h \
        src/core/Gare.h \
        src/core/Inventory.h \
        src/core/Player.h \
        src/core/Property.h \
    src/core/Tile.h \


DISTFILES += \
    README.md \
    img/Univopoly_Board.png \
    img/Univopoly_noshadow.png \
    img/pions.png \
    img/buy.png \
    img/roll_dice.png 

INCLUDEPATH += src/core src/qt