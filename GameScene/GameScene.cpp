#include <QBrush>
#include <QImage>
#include <QDebug>
#include <QObject>
#include "./Birds/RedBird.h"
#include "./RandomItems/Ground.h"
#include "./RandomItems/Stick.h"
#include "./AbsClasses/GameItem.h"
#include "GameScene.h"

GameScene::GameScene()
{
    setBackgroundBrush(QBrush(QImage("./GameData/DefaultResources/Images/background.png")));

    setSceneRect ( 0 , 0 , 1200 , 600 );

    //設定timer60
    timer60 = new QTimer();
    timer60->setTimerType(Qt::PreciseTimer);
    timer60->start(5); //1/60秒

    //設定物理世界的更新頻率
    connect(timer60 , SIGNAL(timeout()) , this , SLOT(updateWorld()));

    //設定彈弓
    singleshot = new Singleshot();
    addItem(singleshot);

    //設定gameEngine
    gameEngine = new GameEngine();
    addItem(gameEngine);
    gameEngine->setFlag(QGraphicsItem::ItemIsFocusable);
    gameEngine->setFocus ();
    gameEngine->grabKeyboard ();
    gameEngine->grabMouse ();

    connect(gameEngine , SIGNAL(getPullPos(int , int)) , singleshot , SLOT(pull(int , int)) );
    connect (gameEngine , SIGNAL(release())  , singleshot , SLOT(release()) );
    connect (gameEngine , SIGNAL(release())  , this , SLOT(releaseBird()) );

    //設定一個向量，在物理世界裡會使用的重力
    int gravityFactor = 10;
    gravity = new b2Vec2( 0.0f , -9.8f * gravityFactor );

    //設定物理世界，使用自定義的重力
    physicWorld = new b2World( * gravity );

    //新增一隻鳥
    AbsBird * redBird = new RedBird(physicWorld);
    focusedBird = redBird;
    addItem(redBird);
    connect(gameEngine , SIGNAL(getPullPos(int , int)) , redBird , SLOT(setPullPos(int , int)) );
    //connect(timer60 , SIGNAL(timeout()) , redBird , SLOT(updatePos()));


    //新增一個地板
    GameItem * ground = new Ground(physicWorld);
    addItem(ground);

    //新增一個棍子
    GameItem * stick = new Stick(physicWorld);
    addItem(stick);
    connect(timer60 , SIGNAL(timeout()) , stick , SLOT(updatePos()));

}

void GameScene::updateWorld()
{
    physicWorld->Step(0.005f , 10 , 10);
}

void GameScene::releaseBird()
{
    connect(timer60 , SIGNAL(timeout()) , focusedBird , SLOT(updatePos()));
    focusedBird->releaseBird(singleshot->forceX , singleshot->forceY);
}
