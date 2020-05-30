#include <QTimer>
#include "bullet.h"
#include "graphics.h"
#include "ufo.h"
#include <QGraphicsScene>
#include <QList>
#include <alien.h>
#include <game.h>
#include <stdio.h>

extern Game *game;
extern Graphics *graphics;

Bullet::Bullet(bool shotByPlayer){
    isPlayer = shotByPlayer;
    setRect(0, 0, 6, 23);
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

    void Bullet::move(){
        //if bullet collides with enemy, destroy both
        if(isPlayer){
        QList<QGraphicsItem *> collisions = collidingItems();
        for(int i = 0; i<collisions.size(); i++){
            if(typeid(*(collisions[i])) == typeid(Alien)){
                int alienID = ((Alien*)collisions[i])->id;
                game->aliens[alienID]->setPixmap(graphics->death_pixmap);
                game->aliens[alienID]->deathAnimation();
                game->score->increase();
                scene()->removeItem(this);
                game->player_bullet_exists = false;
                delete this;
                return;
              }
            else if (typeid(*(collisions[i])) == typeid(UFO)){
                ((UFO*)collisions[i])->isMoving = false;
                ((UFO*)collisions[i])->deathAnimation();
                game->player_bullet_exists = false;
                game->score->ufoIncrease();
                delete this;
                return;
            }

            else if (typeid(*(collisions[i])) == typeid(Bullet)){
                scene()->removeItem(collisions[i]);
                scene()->removeItem(this);
                game->player_bullet_exists = false;
                game->alienBullets--;
                delete collisions[i];
                delete this;
                return;
            }
          }
        }

        else{
            QList<QGraphicsItem *> collisions = collidingItems();
            for(int i = 0; i<collisions.size(); i++){
                if(typeid(*(collisions[i])) == typeid(Player)){
                    game->lives->decrease();
                    scene()->removeItem(this);
                    game->alienBullets--;
                    delete this;
                    return;
                }
            }
        }

        //move bullet
        if(isPlayer){
            setPos(x(), y()-23);
            if (pos().y()+rect().height() < 0){
                game->player_bullet_exists = false;
                scene()->removeItem(this);
                delete this;
            }
        }

        else{
            setPos(x(), y()+14);
            if (pos().y()+rect().height() > 700){
                game->alienBullets--;
                scene()->removeItem(this);
                delete this;
            }
        }
    }

