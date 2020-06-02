#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Player: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
  public:
    Player(QGraphicsItem * parent=0);
    bool isDead;
    QTimer *deathTimer;
    void deathAnimation();
    void keyPressEvent(QKeyEvent *event);
  public slots:
    void revive();
};

#endif // PLAYER_H
