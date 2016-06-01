#ifndef GAMESCENE_H
#define GAMESCENE_H


#include <Box2D/Box2D.h>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <cstring>
#include "./AbsClasses/AbsBird.h"
#include "Singleshot.h"
#include "GameEngine.h"
#include "CollisionListener.h"

using namespace std;

class GameScene : public QGraphicsScene
{
    Q_OBJECT

    public:
        GameScene();

        void setupStage();

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

        CollisionListener * collisionListener;

        string stage;

        //設定一個vector，貯存在physicWorld裡面的所有物體
};


#endif // GAMESCENE_H
