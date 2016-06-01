#include <QGraphicsScene>
#include "BigBird.h"

BigBird::BigBird(b2World * inputWorld)
{
    //基本設定
    setPos(70 , 370);
    inWorld = inputWorld;
    setPixmap(QPixmap("./GameData/DefaultResources/Images/BirdImages/bigBird.png"));
    setTransformOriginPoint(0 , 0);
    health = 3;

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
        circleShape->m_p.Set(45 , -45);
        circleShape->m_radius = 45 ;

    bodyFixture->shape = circleShape ;
    bodyFixture->density = 1 * 10;
    bodyFixture->friction = 1.0f ;
    bodyFixture->restitution = 0.75f;
}

void BigBird::setPullPos(int x, int y)
{
    setPos (x-45 , y-45);
}

void BigBird::updatePos()
{
    b2Vec2 pos;
    pos = physicBody->GetPosition();
    setPos(MeterToPix_x(pos.x) , MeterToPix_y(pos.y));

    float angle;
    angle = physicBody->GetAngle();
    setRotation(-RadToDeg(angle));

    if(health<3)
    {
        setPixmap(QPixmap("./GameData/DefaultResources/Images/BirdImages/bigBirdHurt.png"));
    }
    if(health<=0)
    {
        inWorld->DestroyBody (physicBody);
        scene ()->removeItem (this);
        delete this;
        return;
    }
}

void BigBird::specialAbility()
{

}
