#ifndef GAMEVIEW_H
#define GAMEVIEW_H


#include <QGraphicsView>
#include "./GameScene/GameScene.h"

class GameView : public QGraphicsView
{
    public:
        GameView(QWidget * parent = 0);

        GameScene * gameScene;
};


#endif // GAMEVIEW_H
