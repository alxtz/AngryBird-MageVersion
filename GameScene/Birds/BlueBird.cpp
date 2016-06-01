#include <iostream>
#include <QGraphicsScene>
#include "BlueBird.h"

using namespace std;

BlueBird::BlueBird(b2World * inputWorld , int inputX , int inputY)
{
    //基本設定
    setPos(100 , 400);
    inWorld = inputWorld;
    setPixmap(QPixmap("./GameData/DefaultResources/Images/BirdImages/blueBird.png"));
    setTransformOriginPoint(0 , 0);
    health = 3;
    if(inputX!=0 && inputY!=0)
    {
        setPos(inputX , inputY);
    }

    //設定鳥的ItemData
    itemData->objectType =  "Bird";
    itemData->sceneObject = this;
    itemData->bodyObject = physicBody;

    //設定鳥的物體結構
    bodyStruct->type = b2_dynamicBody;
    bodyStruct->position.Set( PixToMeter_x(x()) , PixToMeter_y(y()) );
    bodyStruct->angle = 0 ;

    //設定鳥的物體的定製器

        //設定一種形狀
        b2CircleShape * circleShape = new b2CircleShape();
        circleShape->m_p.Set(15 , -14);
        circleShape->m_radius = 15 ;

    bodyFixture->shape = circleShape ;
    bodyFixture->density = 1;
    bodyFixture->friction = 1.0f ;
    bodyFixture->restitution = 0.75f;
}

void BlueBird::updatePos()
{
    cout<<"blueBird updatePos"<<endl;
    b2Vec2 pos;
    cout<<"即將使用physicBody"<<endl;
    pos = physicBody->GetPosition();
    cout<<"使用完了physicBody"<<endl;
    setPos(MeterToPix_x(pos.x) , MeterToPix_y(pos.y));

    cout<<"set blueBird Pos"<<endl;

    float angle;
    angle = physicBody->GetAngle();
    setRotation(-RadToDeg(angle));

    cout<<"set blueBird angle"<<endl;

    if(health<3)
    {
        setPixmap(QPixmap("./GameData/DefaultResources/Images/BirdImages/blueBirdHurt.png"));
    }
    if(health<=0)
    {
        inWorld->DestroyBody (physicBody);
        scene ()->removeItem (this);
        delete this;
        return;
    }
}

void BlueBird::specialAbility()
{
    emit spawnBlueChild ( x() , y() );
}
