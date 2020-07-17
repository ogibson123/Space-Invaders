#ifndef BUNKER_H
#define BUNKER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Bunker: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
    public:
        Bunker(QGraphicsItem *parent=0);
        int damageTaken;
        QPixmap damageSprites[3];
};
#endif // BUNKER_H
