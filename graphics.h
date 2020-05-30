#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Graphics{
public:
    Graphics();
    QPixmap alien_pixmap1;
    QPixmap alien_pixmap2;
    QPixmap alien_pixmap3;
    QPixmap alien_pixmap4;
    QPixmap alien_pixmap5;
    QPixmap alien_pixmap6;
    QPixmap player_pixmap;
    QPixmap death_pixmap;
    QPixmap ufo_pixmap;
    QPixmap ufo_death_pixmap;
    bool graphics_loaded = false;
};

#endif // GRAPHICS_H
