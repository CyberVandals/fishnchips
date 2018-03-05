#include "../../inc/chaeunkim/ck_button.h"
#include <QPushButton>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QIcon>

Button::Button(QString path, QPushButton *parent) : QPushButton(parent)
{
    QPixmap pixmap(path);
    QIcon ButtonIcon(pixmap);
    this->setIcon(ButtonIcon);
    this->setFixedSize(150,100);
    this->setIconSize(QSize(150,100));
    this->setStyleSheet("QPushButton{background: transparent;}");
    // allow tracking mouse for mouse hovering effect
    setMouseTracking(true);
    setAttribute(Qt::WA_Hover);


}

void Button::hoverEnter(QHoverEvent *)
{
    int newW = this->width() + 5;
    int newH = this->height() + 5;
    this->setIconSize(QSize(newW,newH));

}

void Button::hoverLeave(QHoverEvent *)
{
    int newW = this->width() - 5;
    int newH = this->height() - 5;
    this->setIconSize(QSize(newW,newH));
}

void Button::hoverMove(QHoverEvent *)
{
    int newW = this->width() + 5;
    int newH = this->height() + 5;
    this->setIconSize(QSize(newW,newH));

}
void Button::mousePressEvent(QMouseEvent *)
{
    emit clicked();
}
bool Button::event(QEvent *event)
{
    switch(event->type())
    {
    case QEvent::HoverEnter:
        hoverEnter(static_cast<QHoverEvent*>(event));
        return true;
        break;
    case QEvent::HoverLeave:
        hoverLeave(static_cast<QHoverEvent*>(event));
        return true;
        break;
    case QEvent::HoverMove:
        hoverMove(static_cast<QHoverEvent*>(event));
        return true;
        break;
    case QEvent::MouseButtonPress:
        mousePressEvent(static_cast<QMouseEvent*>(event));
        return true;
        break;
    default:
        break;
    }
    return QWidget::event(event);
}
