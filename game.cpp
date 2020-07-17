#include <QApplication>
#include <QGraphicsScene>
#include "bunker.h"
#include "button.h"
#include "player.h"
#include "lives.h"
#include "game.h"
#include "alien.h"
#include "graphics.h"
#include "ufo.h"
#include <QGraphicsView>

extern Graphics *graphics;
Game::Game(QWidget *parent){

    //initialize the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 700);
    setScene(scene);
    setBackgroundBrush(Qt::black);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 700);

    //initialize rest of the game
    initializeGame();

    show();
}

void Game::spawnEnemies(){
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
}

void Game::gameOver(){
    for(int j = 0; j<55; j++){
        if(!aliens[j]==NULL){
            aliens[j]->stopTimers();
        }
    }
    ufo->stopTimer();
    drawPanel(0, 0, 800, 700, Qt::black, 0.65);
    drawPanel(255, 200, 325, 100, Qt::red,0.9);
    QGraphicsTextItem* message = new QGraphicsTextItem(QString("GAME OVER"));
    message->setPos(373,220);
    scene->addItem(message);
    Button *quit = new Button(QString("Quit"));
    quit->setPos(440, 255);
    scene->addItem(quit);
    connect(quit, SIGNAL(clicked()),this,SLOT(close()));
    Button *retry = new Button(QString("Retry"));
    retry->setPos(300, 255);
    scene->addItem(retry);
    connect(retry, SIGNAL(clicked()),this, SLOT(restart()));
}

void Game::restart(){
    scene->clear();
    initializeGame();
}

void Game::initializeGame(){
    //player initialization
    player = new Player();
    player_bullet_exists = false;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setPixmap(graphics->player_pixmap);
    player->setFocus();
    player->setPos(400, 600);
    totalKills = 0;
    scene->addItem(player);

    spawnEnemies();

    ufo = new UFO();
    ufo->setPixmap(graphics->ufo_pixmap);
    ufo->setPos(-50, 50);
    scene->addItem(ufo);

    //bunkers initialization
    int bunkerXPos = 100;
    int bunkerYPos = 525;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<6; j++){
            Bunker *bunker = new Bunker();
            bunker->setPixmap(graphics->bunker1_pixmap);
            switch(j){
                case 0:
                    bunker->setPos(bunkerXPos, bunkerYPos);
                break;
                case 1:
                    bunker->setPos(bunkerXPos, bunkerYPos-25);
                break;
                case 2:
                    bunker->setPos(bunkerXPos+25, bunkerYPos-25);
                break;
                case 3:
                    bunker->setPos(bunkerXPos+50, bunkerYPos-25);
                break;
                case 4:
                    bunker->setPos(bunkerXPos+75, bunkerYPos-25);
                break;
                case 5:
                    bunker->setPos(bunkerXPos+75, bunkerYPos);
                break;
            }
            scene->addItem(bunker);
        }
        bunkerXPos+=175;
    }

    alienBullets = 0;
    score = new Score();
    scene -> addItem(score);
    lives = new Lives();
    lives -> setPos(lives->x(), lives->y()+25);
    scene->addItem(lives);
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    QGraphicsRectItem *panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}


