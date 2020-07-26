#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include "game.h"
#include "graphics.h"
#include <QTimer>

extern Game *game;
extern Graphics *graphics;

Player::Player(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    isDead = false;
    deathTimer = new QTimer();
    connect(deathTimer, SIGNAL(timeout()),this,SLOT(revive()));
}

void Player::keyPressEvent(QKeyEvent *event){
    if (!isDead){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
           setPos(x()-20, y());
    }
    else if (event->key()==Qt::Key_Right){
        if (pos().x()+50<800)
           setPos(x()+20,y());
    }
    else if (event->key()==Qt::Key_Space){
        if (!game->player_bullet_exists){
            game->player_bullet_exists = true;
            Bullet *bullet = new Bullet(true);
            bullet->setBrush(Qt::green);
            bullet->setPos(x()+16.5, y()-6);
            scene()->addItem(bullet);
        }
        }
    }
}

void Player::deathAnimation(){
    isDead = true;
    setPixmap(graphics->player_death_pixmap);
    deathTimer->start(700);
}

void Player::revive(){
    setPixmap(graphics->player_pixmap);
    deathTimer->stop();
    isDead = false;
}
