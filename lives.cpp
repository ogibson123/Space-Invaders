#include "lives.h"
#include <QFont>

Lives::Lives(QGraphicsItem *parent): QGraphicsTextItem(parent){
    lives = 3;
    setPlainText(QString("Lives: ") + QString::number(lives));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 16));
}

void Lives::decrease(){
    lives--;
    setPlainText(QString("Lives: ") + QString::number(lives));
}

int Lives::getLives(){
    return lives;
}
