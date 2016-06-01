#include <fstream>
#include <iostream>
#include <QBrush>
#include <QImage>
#include <QDebug>
#include <QObject>
#include "./Birds/RedBird.h"
#include "./RandomItems/Ground.h"
#include "./RandomItems/Stick_Vtl.h"
#include "./RandomItems/Stick_Hrz.h"
#include "./RandomItems/Stick2_Hrz.h"
#include "./RandomItems/Stick2_Vtl.h"
#include "./RandomItems/Block_Vtl.h"
#include "./Pigs/Pig1.h"
#include "./AbsClasses/GameItem.h"
#include "GameScene.h"

using namespace std;

GameScene::GameScene()
{
    //基本設定
    setBackgroundBrush(QBrush(QImage("./GameData/DefaultResources/Images/background.png")));
    setSceneRect ( 0 , 0 , 1200 , 600 );

    //設定哪一關
    stage = "Stage1";

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

    //int pos1 = 600;
    //新增一個棍子
    //GameItem * stick = new Stick(physicWorld , 600 ,400);
    //addItem(stick);
    //connect(timer60 , SIGNAL(timeout()) , stick , SLOT(updatePos()));

    //新增一個棍子
    //GameItem * stick1 = new Stick(physicWorld, 645 , 400);
    //addItem(stick1);
    //connect(timer60 , SIGNAL(timeout()) , stick1 , SLOT(updatePos()));

    //新增一個棍子
    //GameItem * stick3 = new Stick_Hrz(physicWorld, 600 , 390);
    //addItem(stick3);
    //connect(timer60 , SIGNAL(timeout()) , stick3 , SLOT(updatePos()));

    //新增一個Block
    //GameItem * block1 = new Block_Vtl(physicWorld, 600 , 360);
    //addItem(block1);
    //connect(timer60 , SIGNAL(timeout()) , block1 , SLOT(updatePos()));

    setupStage ();
}

void GameScene::setupStage()
{
    ifstream inFile;
    string stagePath;
    stagePath = "./GameData/Stages/" + stage + "/setup.txt";
    inFile.open (stagePath);

    for(int i=0; i<=999; i++)
    {
        int objectType;
        int x , y;
        if(inFile>>objectType)
        {
            cout<<"第"<<i+1<<"個物體的type為"<<objectType<<endl;
            inFile>>x;
            inFile>>y;

            switch(objectType)
            {
                case 0:
                {
                    //0代表產生一個垂直的stick
                    GameItem * stick_vtl = new Stick_Vtl(physicWorld, x , y);
                    addItem(stick_vtl);
                    connect(timer60 , SIGNAL(timeout()) , stick_vtl , SLOT(updatePos()));
                    break;
                }
                case 1:
                {
                    //1代表產生一個水平的stick
                    GameItem * stick_hrz = new Stick_Hrz(physicWorld, x , y);
                    addItem(stick_hrz);
                    connect(timer60 , SIGNAL(timeout()) , stick_hrz , SLOT(updatePos()));
                    break;
                }
                case 3:
                {
                    //3代表產生一個水平的長stick
                    GameItem * stick2_hrz = new Stick2_Hrz(physicWorld, x , y);
                    addItem(stick2_hrz);
                    connect(timer60 , SIGNAL(timeout()) , stick2_hrz , SLOT(updatePos()));
                    break;
                }
                case 4:
                {
                    //4代表產生一隻垂直的長stick
                    GameItem * stick2_vtl = new Stick2_Vtl(physicWorld, x , y);
                    addItem(stick2_vtl);
                    connect(timer60 , SIGNAL(timeout()) , stick2_vtl , SLOT(updatePos()));
                    break;
                }
                case 10:
                {
                    //10代表產生一隻pig1
                    GameItem * pig1 = new Pig1(physicWorld, x , y);
                    addItem(pig1);
                    connect(timer60 , SIGNAL(timeout()) , pig1 , SLOT(updatePos()));
                    break;
                }
            }
        }
        else
        {
            cout<<"讀檔結束"<<endl;
            return;
        }
    }

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
