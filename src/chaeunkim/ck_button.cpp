#include "../../inc/chaeunkim/ck_button.h"
#include <QPushButton>
#include <QBrush>
#include <QIcon>

MainButton::MainButton( QString path, QPushButton *parent )
    : AbstractButton(parent)
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

void MainButton::mousePressEvent( QMouseEvent * ) {
    emit clicked();
}
