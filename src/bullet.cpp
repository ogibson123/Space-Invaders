#include <QTimer>
#include "bullet.h"
#include "bunker.h"
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
                game->totalKills++;
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

            else if (typeid(*(collisions[i])) == typeid(Bunker)){
                ((Bunker*)collisions[i])->damageTaken++;
                int damage =  ((Bunker*)collisions[i])->damageTaken;
                if(((Bunker*)collisions[i])->damageTaken == 4){
                    scene()->removeItem(collisions[i]);
                }
                else{
                    ((Bunker*)collisions[i])->setPixmap(((Bunker*)collisions[i])->damageSprites[damage-1]);
                }
                game->player_bullet_exists = false;
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
                    if(game->lives->getLives()==0){
                        ((Player*)collisions[i])->setPixmap(graphics->player_death_pixmap);
                        ((Player*)collisions[i])->isDead = true;
                        game->gameOver();
                    }
                    else{
                        ((Player*)collisions[i])->deathAnimation();
                    }
                    return;
                }
                else if (typeid(*(collisions[i])) == typeid(Bunker)){
                    ((Bunker*)collisions[i])->damageTaken++;
                    int damage = ((Bunker*)collisions[i])->damageTaken;
                    if(((Bunker*)collisions[i])->damageTaken == 4){
                        scene()->removeItem(collisions[i]);
                    }
                    else{
                        ((Bunker*)collisions[i])->setPixmap(((Bunker*)collisions[i])->damageSprites[damage-1]);
                    }
                    game->alienBullets--;
                    delete this;
                    return;
                }
            }
        }

        //move bullet upwards if shot by player, else downwards if shot by enemy
        if(isPlayer){
            setPos(x(), y()-23);
            if (pos().y()+rect().height() < 0){
                game->player_bullet_exists = false;
                scene()->removeItem(this);
                delete this;
                return;
            }
        }

        else{
            setPos(x(), y()+14);
            if (pos().y()+rect().height() > 700){
                game->alienBullets--;
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }

