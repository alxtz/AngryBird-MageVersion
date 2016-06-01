#ifndef SINGLESHOT_H
#define SINGLESHOT_H


#include <QTimer>
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include "GameEngine.h"

class Singleshot : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    friend class GameEngine;

    public:
        Singleshot();

        int forceX;
        int forceY;

    public slots:
        void pull(int x , int y);
        void release();
        void shorten();

    signals:
        void setNewBird();

    private:
        QGraphicsPixmapItem * singleshotPic;

        QGraphicsRectItem * rubberBand1;
        QGraphicsRectItem * rubberBand2;

        int realTransformOriginX1;
        int realTransformOriginY1;

        int realTransformOriginX2;
        int realTransformOriginY2;

        QTimer * shortenTimer;

        bool isShortening;
        bool hasBird;
};


#endif // SINGLESHOT_H
