      #ifndef UFO_H
#define UFO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class UFO: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
    public:
        UFO(QGraphicsItem *parent=0);
        int moveTime;
        bool movedOnce;
        bool isMoving;
        QTimer *moveTimer;
        QTimer *deathTimer;
        QTimer *timer;
        void deathAnimation();
        void stopTimer();
    public slots:
        void triggerMove();
        void move();
        void setBack();
};
#endif // UFO_H
