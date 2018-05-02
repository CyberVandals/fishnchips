#include "../../inc/chaeunkim/ck_abstract_button.h"
#include <QPushButton>
#include <QBrush>
#include <QIcon>

AbstractButton::AbstractButton( QPushButton *parent )
    : QPushButton(parent)
{
    new_height = DEFAULT_BTN_HEIGHT;
    new_width = DEFAULT_BTN_WIDTH;
}

void AbstractButton::hover_enter( QHoverEvent * ) {
    if(new_height!=DEFAULT_BTN_HEIGHT){
    new_width = this->width() + 5;
    new_height = this->height() + 5;
    this->setIconSize(QSize(new_width,new_height));
    }
}

void AbstractButton::hover_leave( QHoverEvent * ) {
    new_width = this->width() - 5;
    new_height = this->height() - 5;
    this->setIconSize(QSize(new_width,new_height));
}

void AbstractButton::hover_move( QHoverEvent * ) {
    new_width = this->width() + 5;
    new_height = this->height() + 5;
    this->setIconSize(QSize(new_width,new_height));
}

void AbstractButton::mousePressEvent( QMouseEvent * ) {
    emit clicked();
}

bool AbstractButton::event( QEvent *event ) {
    switch( event->type() ) {
        case QEvent::HoverEnter:
            hover_enter(static_cast<QHoverEvent*>(event));
            return true;
            break;
        case QEvent::HoverLeave:
            hover_leave(static_cast<QHoverEvent*>(event));
            return true;
            break;
        case QEvent::HoverMove:
            hover_move(static_cast<QHoverEvent*>(event));
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
