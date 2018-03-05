#include "../../inc/hh_main_player.h"
#include "../../inc/henry/hh_health_bar.h"

#include "../../inc/gy_object.h"
#include <QDebug>
#include <typeinfo>
Main_player::Main_player(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    setRect(0,0, 50, 50);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    player_health = new HealthBar();
    this->scene()->addItem(player_health);

    has_banana = false;
    //health = 5;//change this to constant

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(sink()));
    timer->start(50);


}

void Main_player::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_Left && (this->pos().x()) > (this->scene()->sceneRect().left()))
    {
        this->setPos(x()-10, y());
        if(shark_collision())
        {
            this->player_health->decrease_health();
        }

        //move left
    }

    else if( event->key() == Qt::Key_Right && (this->pos().x()+(boundingRect().right()-boundingRect().left())) < (this->scene()->sceneRect().right()))
    {
        this->setPos(x()+10, y());
        if(shark_collision())
        {
            this->player_health->decrease_health();
        }

        //move right
    }

    else if( event->key() == Qt::Key_Up && (this->pos().y()) > (this->scene()->sceneRect().top()))
    {
        this->setPos(x(), y()-10);
        if(shark_collision())
        {
            this->player_health->decrease_health();
        }
        //move up
    }

    else if( event->key() == Qt::Key_Down && (this->pos().y()+(boundingRect().bottom()-boundingRect().top())) < (this->scene()->sceneRect().bottom()))
    {
        this->setPos(x(), y()+10);
        if(shark_collision())
        {
            this->player_health->decrease_health();
        }
        //move down
    }
}

bool Main_player::shark_collision()
{
    collision_item = collidingItems(Qt::IntersectsItemShape);

    for( int i = 0; i < collision_item.size() ; i++ ) {

        if( typeid(*(collision_item[i])) == typeid(Shark) )
        {
            qDebug() << "hit a shark";
            return true;
        }
        else if(typeid(*(collision_item[i])) == typeid(Exit))
        {
          qDebug() << "Level Finished";
        }
    }
}


void Main_player::sink()
{
      setPos(x(), y()+1);
}
