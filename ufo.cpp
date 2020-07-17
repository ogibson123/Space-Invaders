#include "ufo.h"
#include "game.h"
#include "graphics.h"
#include <QGraphicsScene>
#include <QTimer>

extern Game *game;
extern Graphics *graphics;

UFO::UFO(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    movedOnce = false;
    isMoving = false;
    timer = new QTimer();
    moveTime = rand()%10000+20000;
    connect(timer, SIGNAL(timeout()),this,SLOT(triggerMove()));
    deathTimer = new QTimer();
    connect(deathTimer, SIGNAL(timeout()),this,SLOT(setBack()));
    timer->start(moveTime);
}

    void UFO::triggerMove(){
        setPixmap(graphics->ufo_pixmap);
        if(!movedOnce){
            moveTimer = new QTimer();
            connect(moveTimer, SIGNAL(timeout()),this,SLOT(move()));
        }
        isMoving = true;
        moveTimer->start(50);
        movedOnce = true;
    }

    void UFO::move(){
        if(isMoving){
            setPos(x()+6, y());
        }
        if(x()>800){
            moveTimer->stop();
            setPos(-50, 50);
        }
    }

    void UFO::deathAnimation(){
        setPixmap(graphics->ufo_death_pixmap);
        deathTimer->start(250);
    }

    void UFO::stopTimer(){
        isMoving = false;
        delete timer;
        if(movedOnce){
            delete moveTimer;
        }
    }

    void UFO::setBack(){
        setPos(-50, 50);
        setPixmap(graphics->ufo_pixmap);
        deathTimer->stop();
    }
