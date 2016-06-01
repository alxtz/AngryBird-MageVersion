#ifndef ITEMDATA_H
#define ITEMDATA_H


#include <string>

using namespace std;

class ItemData
{
    public:
        ItemData();

        string objectType;  //有Bird , Pig , Obstacle

        void * sceneObject; //QGraphicsItem的指標

        void * bodyObject;  //b2Body的指標


};

#endif // ITEMDATA_H
