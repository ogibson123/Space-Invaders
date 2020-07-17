#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Button:public QObject, public QGraphicsRectItem{
    Q_OBJECT
    public:
        Button(QString name, QGraphicsItem *parent=NULL);
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        QGraphicsTextItem *text;
    signals:
        void clicked();
};

#endif // BUTTON_H
