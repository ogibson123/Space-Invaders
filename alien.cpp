#include "alien.h"
#include "game.h"
#include "bullet.h"
#include "graphics.h"
#include <QGraphicsScene>
#include <stdlib.h>
#include <QTimer>

extern Game *game;
extern Graphics *graphics;

Alien::Alien(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    timer = new QTimer();
    timer2 = new QTimer();
    random_shot_time = rand()%2000+2000;
    graphic1_active = true;
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(300);
    connect(timer2, SIGNAL(timeout()),this,SLOT(shoot()));
    timer2->start(random_shot_time);
}
    void Alien::shoot(){
        if(game->alienBullets<2){
            Bullet *bullet = new Bullet(false);
            bullet->setBrush(Qt::white);
            bullet->setPos(x()+10, y()+20);
            scene()->addItem(bullet);
            game->alienBullets++;
            random_shot_time = rand()%2000+2000;
        }
    }

    void Alien::deathAnimation(){
        timer->stop();
        timer2->stop();
        setPixmap(graphics->death_pixmap);
        QTimer *timer3 = new QTimer();
        connect(timer3, SIGNAL(timeout()),this,SLOT(remove()));
        timer3->start(250);
    }

    void Alien::stopTimers(){
        timer->stop();
        timer2->stop();
    }

    void Alien::remove(){
        game->aliens[id] = NULL;
        scene()->removeItem(this);
        if(game->totalKills == 55){
            game->totalKills = 0;
            game->lives->increase();
            game->spawnEnemies();
        }
        delete this;
        return;
    }

    void Alien::move(){
        //move enemy side to side
        bool old_move = moving_right;
        moving_right = ((x()<=right_limit && moving_right) || x()<=left_limit);
        if(moving_right!=old_move){
            setPos(x(), y()+30);
        }
        if(moving_right){
            setPos(x()+5, y());
        }
        else{
            setPos(x()-5, y());
        }
        if(graphic1_active){
            setPixmap(animation2);
        }
        else{
            setPixmap(animation1);
        }
        graphic1_active = !graphic1_active;
    }

