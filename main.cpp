#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include "game.h"
#include "graphics.h"
#include <QGraphicsView>
#include <QTimer>

Game *game;
Graphics *graphics;

int main(int argc, char *argv[]){
   QApplication a(argc, argv);
    graphics = new Graphics();
    while(!graphics->graphics_loaded);
    game = new Game();
    game->show();
    return a.exec();
}
