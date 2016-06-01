#include <iostream>
#include "AbsClasses/ItemData.h"
#include "AbsClasses/AbsBird.h"
#include "CollisionListener.h"

using namespace std;

CollisionListener::CollisionListener()
{
    //可以等物體都放置好再開啟碰撞監控的功能
}

void CollisionListener::BeginContact(b2Contact *contact)
{
    //得知了物體碰撞，現在要過濾出碰撞的物體是否是我們想要的

    b2Fixture * contactItemA = contact->GetFixtureA ();
    b2Fixture * contactItemB = contact->GetFixtureB ();

    ItemData * itemDataA = (ItemData * )contactItemA->GetBody ()->GetUserData ();
    ItemData * itemDataB = (ItemData * )contactItemB->GetBody ()->GetUserData ();

    string objectTypeA = itemDataA->objectType;
    string objectTypeB = itemDataB->objectType;

    if( (objectTypeA=="Bird" && objectTypeB=="Stick") || (objectTypeB=="Bird" && objectTypeA=="Stick") )
    {
        if(objectTypeA=="Bird")
        {
            cout<<"扣血"<<endl;
            AbsBird * collideBird = (AbsBird * )itemDataA->sceneObject;
            collideBird->health--;
        }
        else
        {
            cout<<"扣血"<<endl;
            AbsBird * collideBird = (AbsBird * )itemDataB->sceneObject;
            collideBird->health--;
        }
    }

}

void CollisionListener::EndContact(b2Contact *contact)
{
    //cout<<"物體離開"<<endl;
}

void CollisionListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{

}

void CollisionListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{

}
