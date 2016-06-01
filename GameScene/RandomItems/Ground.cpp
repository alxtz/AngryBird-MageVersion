#include "Ground.h"

Ground::Ground(b2World *inputWorld)
{
    inWorld = inputWorld;

    setPos(0 , 517);

    //基本設定
    bodyStruct->type = b2_staticBody;
    bodyStruct->position.Set( PixToMeter_x(x()) , PixToMeter_y(y()) );
    bodyStruct->angle = 0;
    objectType = "Ground";

    //設定定製器

        //設定一種形狀
        b2Vec2 vertices[4];
        vertices[0].Set(0 , 0);
        vertices[1].Set(0 , -(600-517) );
        vertices[2].Set(1200 , -(600-517) );
        vertices[3].Set(1200 , 0);

        b2PolygonShape * polygonShape = new b2PolygonShape();
        polygonShape->Set(vertices , 4);

    bodyFixture->shape = polygonShape;
    bodyFixture->density = 0 ;
    bodyFixture->friction = 1 ;
    bodyFixture->restitution = 0 ;

    physicBody = inWorld->CreateBody(bodyStruct);
    physicBody->SetUserData (&objectType);
    physicBody->CreateFixture(bodyFixture);
}
