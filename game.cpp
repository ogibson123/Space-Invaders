#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include "lives.h"
#include "game.h"
#include "alien.h"
#include "graphics.h"
#include <QGraphicsView>
#include <QTimer>

extern Graphics *graphics;
Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 700);
    setScene(scene);
    setBackgroundBrush(Qt::black);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 700);



    //player initialization
    player = new Player();
    player_bullet_exists = false;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setPixmap(graphics->player_pixmap);
    player->setFocus();
    player->setPos(400, 600);
    scene->addItem(player);

    //enemies initialization
    int xpos = 125;
    int ypos = 100;
    int x = 0;
    for(int j = 0; j<5; j++){
        for(int i = 0; i<11; i++){
            Alien *enemy = new Alien();
            if(j == 0){
                enemy->animation1 = graphics->alien_pixmap3;
                enemy->animation2 = graphics->alien_pixmap4;
                enemy->setPixmap(graphics->alien_pixmap3);
            }
            else if(j==1 || j==2){
                enemy->animation1 = graphics->alien_pixmap1;
                enemy->animation2 = graphics->alien_pixmap2;
                enemy->setPixmap(graphics->alien_pixmap1);
            }
            else{
                enemy->animation1 = graphics->alien_pixmap6;
                enemy->animation2 = graphics->alien_pixmap5;
                enemy->setPixmap(graphics->alien_pixmap6);
            }
            enemy->setPos(xpos, ypos);
            enemy->moving_right = true;
            enemy->right_limit = xpos+85;
            enemy->left_limit = xpos-85;
            xpos+=50;
            scene->addItem(enemy);
            enemy->id = x;
            aliens[x] = enemy;
            x++;
        }
        ypos+=50;
        xpos=125;
    }
    alienBullets = 0;
    score = new Score();
    scene -> addItem(score);
    lives = new Lives();
    lives -> setPos(lives->x(), lives->y()+25);
    scene->addItem(lives);
    show();
}


