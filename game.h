#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "lives.h"
#include "alien.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent = 0);
    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Lives *lives;
    bool player_bullet_exists;
    int alienBullets;
    Alien *aliens[55];
};

#endif // GAME_H
