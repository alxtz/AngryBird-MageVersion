#ifndef STICK_H
#define STICK_H


#include <QObject>
#include "../AbsClasses/GameItem.h"

class Stick : public GameItem
{
    Q_OBJECT

    public:
        Stick(b2World * inputWorld);

    public slots:
        void updatePos ();
};

#endif // STICK_H
