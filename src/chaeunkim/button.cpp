#include "button.h"
#include <QPushButton>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QIcon>

Button::Button(QString txt, QPushButton *parent) : QPushButton(parent)
{
    QPixmap pixmap(txt);
    QIcon ButtonIcon(pixmap);
    this->setIcon(ButtonIcon);
    this->setIconSize(pixmap.rect().size());
    this->setStyleSheet("QPushButton {background-color:transparent;}");


}

/*void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    //setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    //setBrush(brush);
}*/
