#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "lives.h"
#include "alien.h"
#include "ufo.h"

class Game: public QGraphicsView{
    Q_OBJECT
    public:
        Game(QWidget * parent = 0);
        QGraphicsScene *scene;
        Player *player;
        Score *score;
        Lives *lives;
        UFO *ufo;
        bool player_bullet_exists;
        int alienBullets;
        int totalKills;
        Alien *aliens[55];
        void gameOver();
        void spawnEnemies();
    public slots:
        void restart();
    private:
        void initializeGame();
        void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
};

#endif // GAME_H
