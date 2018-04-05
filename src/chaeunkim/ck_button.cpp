#include "../../inc/chaeunkim/ck_button.h"
#include <QPushButton>
#include <QBrush>
#include <QIcon>

Button::Button( QString path, QPushButton *parent )
    : QPushButton(parent)
{
    QPixmap pixmap(path);
    QIcon ButtonIcon(pixmap);
    this->setIcon(ButtonIcon);
    this->setFixedSize(DEFAULT_BTN_WIDTH, DEFAULT_BTN_HEIGHT);
    this->setIconSize(QSize(DEFAULT_BTN_WIDTH, DEFAULT_BTN_HEIGHT));
    this->setStyleSheet("QPushButton{background: transparent;}");
    // allow tracking mouse for mouse hovering effect
    setMouseTracking(true);
    setAttribute(Qt::WA_Hover);
}

void Button::hoverEnter( QHoverEvent * ) {
    new_width = this->width() + 5;
    new_height = this->height() + 5;
    this->setIconSize(QSize(new_width,new_height));
}

void Button::hoverLeave( QHoverEvent * ) {
    new_width = this->width() - 5;
    new_height = this->height() - 5;
    this->setIconSize(QSize(new_width,new_height));
}

void Button::hoverMove( QHoverEvent * ) {
    new_width = this->width() + 5;
    new_height = this->height() + 5;
    this->setIconSize(QSize(new_width,new_height));

}
void Button::mousePressEvent( QMouseEvent * ) {
    emit clicked();
}
bool Button::event( QEvent *event ) {
    switch( event->type() ) {
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
