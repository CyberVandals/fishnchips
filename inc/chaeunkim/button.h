#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>

class Button : public QPushButton
{
public:
    Button(QString txt, QPushButton * parent = NULL);

    /*void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();
*/
};

#endif // BUTTON_H
