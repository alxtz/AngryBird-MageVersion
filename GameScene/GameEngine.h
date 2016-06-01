#ifndef GAMEENGINE_H
#define GAMEENGINE_H


#include <QObject>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>

class GameEngine : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        GameEngine();

        void keyPressEvent (QKeyEvent * event);
        void keyReleaseEvent (QKeyEvent * event);

        void mousePressEvent      (QGraphicsSceneMouseEvent * event);
        void mouseReleaseEvent (QGraphicsSceneMouseEvent * event);
        void mouseMoveEvent     (QGraphicsSceneMouseEvent * event);

    signals:
        void getPullPos(int x , int y);
        void release();

    private:
        bool leftButtonPressed;

};

#endif // GAMEENGINE_H
