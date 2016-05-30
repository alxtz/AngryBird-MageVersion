#ifndef GAMESCENE_H
#define GAMESCENE_H


#include <Box2D/Box2D.h>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QTimer>
#include "./AbsClasses/AbsBird.h"
#include "Singleshot.h"
#include "GameEngine.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT

    public:
        GameScene();

    public slots:
        void updateWorld();
        void releaseBird();

    private:
        Singleshot * singleshot;
        GameEngine * gameEngine;

        b2World * physicWorld;
        b2Vec2 * gravity;

        QTimer * timer60;

        AbsBird * focusedBird;
};


#endif // GAMESCENE_H
