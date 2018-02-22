#include "../../inc/henry/hh_main_player.h"

Main_player::Main_player(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    setRect(0,0, 50, 50);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    has_banana = false;

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(sink()));
    timer->start(50);


}

void Main_player::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_Left && (this->boundingRect().left()) < (this->scene()->sceneRect().left()))
    {
     this->setPos(x()-10, y());
        //move left
    }
else if( event->key() == Qt::Key_Right && (this->boundingRect().right()) < (this->scene()->sceneRect().right()))
    {
        this->setPos(x()+10, y());

        //move right
    }
else if( event->key() == Qt::Key_Up && (this->boundingRect().top()) < (this->scene()->sceneRect().top()))
    {
        this->setPos(x(), y()-10);

        //move up
    }
else if( event->key() == Qt::Key_Down && (this->boundingRect().bottom()) < (this->scene()->sceneRect().bottom()))
    {
       this->setPos(x(), y()+10);

        //move down
    }
}

void Main_player::sink()
{
    setPos(x(), y()+1);
}
