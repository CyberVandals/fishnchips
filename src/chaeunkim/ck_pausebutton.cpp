#include "../../inc/chaeunkim/ck_pausebutton.h"
#include <QPushButton>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QIcon>


PauseButton::PauseButton(QString path, QPushButton *parent) : QPushButton(parent)
{
    QPixmap pixmap(path);
    QIcon ButtonIcon(pixmap);
    this->setIcon(ButtonIcon);
    this->setFixedSize(50,50);
    this->setIconSize(QSize(50,50));
    this->setStyleSheet("QPushButton{background: transparent;}");

    // allow tracking mouse for mouse hovering effect
    setMouseTracking(true);
    setAttribute(Qt::WA_Hover);


}

void PauseButton::hoverEnter(QHoverEvent *)
{
    int newW = this->width() + 1;
    int newH = this->height() + 1;
    this->setIconSize(QSize(newW,newH));

}

void PauseButton::hoverLeave(QHoverEvent *)
{
    int newW = this->width() - 1;
    int newH = this->height() - 1;
    this->setIconSize(QSize(newW,newH));
}

void PauseButton::hoverMove(QHoverEvent *)
{
    int newW = this->width() + 1;
    int newH = this->height() + 1;
    this->setIconSize(QSize(newW,newH));

}
void PauseButton::mousePressEvent(QMouseEvent *)
{
    emit clicked();
}
bool PauseButton::event(QEvent *event)
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


