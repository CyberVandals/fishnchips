#include "../../inc/chaeunkim/ck_pausebutton.h"
#include <QPushButton>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QIcon>


PauseButton::PauseButton(QString path, QPushButton *parent)
    : AbstractButton(parent)
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

void PauseButton::mousePressEvent(QMouseEvent *)
{
    emit clicked();
}


