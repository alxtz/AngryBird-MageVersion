#include <QBrush>
#include <QImage>
#include <QDebug>
#include <QObject>
#include "./Birds/RedBird.h"
#include "./RandomItems/Ground.h"
#include "./RandomItems/Stick.h"
#include "./RandomItems/Stick_Hrz.h"
#include "./RandomItems/Block_Vtl.h"
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

    //新增一個碰撞感測器
    collisionListener = new CollisionListener();

    //設定一個向量，在物理世界裡會使用的重力
    int gravityFactor = 10;
    gravity = new b2Vec2( 0.0f , -9.8f * gravityFactor );

    //設定物理世界，使用自定義的重力，與碰撞感測器
    physicWorld = new b2World( * gravity );
    physicWorld->SetContactListener (collisionListener);

    //新增一隻鳥
    AbsBird * redBird = new RedBird(physicWorld);
    focusedBird = redBird;
    addItem(redBird);
    connect(gameEngine , SIGNAL(getPullPos(int , int)) , redBird , SLOT(setPullPos(int , int)) );
    //connect(timer60 , SIGNAL(timeout()) , redBird , SLOT(updatePos()));


    //新增一個地板
    GameItem * ground = new Ground(physicWorld);
    addItem(ground);

    int pos1 = 600;
    //新增一個棍子
    GameItem * stick = new Stick(physicWorld , 600 ,450);
    addItem(stick);
    connect(timer60 , SIGNAL(timeout()) , stick , SLOT(updatePos()));

    //新增一個棍子
    GameItem * stick1 = new Stick(physicWorld, 645 , 450);
    addItem(stick1);
    connect(timer60 , SIGNAL(timeout()) , stick1 , SLOT(updatePos()));

    //新增一個棍子
    GameItem * stick3 = new Stick_Hrz(physicWorld, 600 , 440);
    addItem(stick3);
    connect(timer60 , SIGNAL(timeout()) , stick3 , SLOT(updatePos()));

    int pos2 =  660;
    //新增一個棍子
    GameItem * stick4 = new Stick(physicWorld , pos2 ,450);
    addItem(stick4);
    connect(timer60 , SIGNAL(timeout()) , stick4 , SLOT(updatePos()));

    //新增一個棍子
    GameItem * stick5 = new Stick(physicWorld, pos2+45 , 450);
    addItem(stick5);
    connect(timer60 , SIGNAL(timeout()) , stick5 , SLOT(updatePos()));

    //新增一個棍子
    GameItem * stick6 = new Stick_Hrz(physicWorld, pos2 , 440);
    addItem(stick6);
    connect(timer60 , SIGNAL(timeout()) , stick6 , SLOT(updatePos()));

    int pos3 =  720;
    //新增一個棍子
    GameItem * stick7 = new Stick(physicWorld , pos3 ,450);
    addItem(stick7);
    connect(timer60 , SIGNAL(timeout()) , stick7 , SLOT(updatePos()));

    //新增一個棍子
    GameItem * stick8 = new Stick(physicWorld, pos3+45 , 450);
    addItem(stick8);
    connect(timer60 , SIGNAL(timeout()) , stick8 , SLOT(updatePos()));

    //新增一個棍子
    GameItem * stick9 = new Stick_Hrz(physicWorld, pos3 , 440);
    addItem(stick9);
    connect(timer60 , SIGNAL(timeout()) , stick9 , SLOT(updatePos()));

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
