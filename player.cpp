#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include "game.h"

extern Game *game;

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if(pos().x() > 0)
           setPos(x()-20, y());
    }
    else if (event->key()==Qt::Key_Right){
        if(pos().x()+50<800)
           setPos(x()+20,y());
    }
    else if (event->key()==Qt::Key_Space){
        if(!game->player_bullet_exists){
            game->player_bullet_exists = true;
            Bullet *bullet = new Bullet(true);
            bullet->setBrush(Qt::green);
            bullet->setPos(x()+16.5, y()-6);
            scene()->addItem(bullet);
        }
    }
}
