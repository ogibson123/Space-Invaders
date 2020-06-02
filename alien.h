#ifndef ALIEN_H
#define ALIEN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Alien: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Alien(QGraphicsItem *parent=0);
    int id;
    QPixmap animation1;
    QPixmap animation2;
    bool moving_right;
    int right_limit;
    int left_limit;
    int random_shot_time;
    bool graphic1_active;
    QTimer *timer;
    QTimer *timer2;
    void deathAnimation();
    void stopTimers();
public slots:
    void shoot();
    void move();
    void remove();
};

#endif // ALIEN_H
