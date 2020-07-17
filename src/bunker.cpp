#include "bunker.h"
#include "graphics.h"

extern Graphics *graphics;

Bunker::Bunker(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    damageTaken = 0;
    damageSprites[0] = graphics->bunker2_pixmap;
    damageSprites[1] = graphics->bunker3_pixmap;
    damageSprites[2] = graphics->bunker4_pixmap;
}
