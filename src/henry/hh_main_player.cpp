#include "../../inc/hh_main_player.h"
#include "../../inc/henry/hh_health_bar.h"

#include "../../inc/gy_object.h"
#include <QDebug>
#include <typeinfo>
Main_player::Main_player(QGraphicsScene * scene,QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    player_pic = new Graphics();
    player_pic->load_mainplayer(50,50, this);
    //setPixmap(QPixmap());
    setPos(scene->sceneRect().bottom(), scene->sceneRect().bottom()-50);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    player_health = new HealthBar(scene);

    has_banana = false;
    shield = false;


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(sink()));
    timer->start(50);

    recover_timer = new QTimer(this);
    connect(recover_timer, SIGNAL(timeout()), this, SLOT(recover()));


}

void Main_player::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_Left && (this->pos().x()) > (this->scene()->sceneRect().left()))
    {
        this->setPos(x()-10, y());


        //move left
    }

    else if( event->key() == Qt::Key_Right && (this->pos().x()+(boundingRect().right()-boundingRect().left())) < (this->scene()->sceneRect().right()))
    {
        this->setPos(x()+10, y());

        //move right
    }

    else if( event->key() == Qt::Key_Up && (this->pos().y()) > (this->scene()->sceneRect().top()))
    {
        this->setPos(x(), y()-10);

        //move up
    }

    else if( event->key() == Qt::Key_Down && (this->pos().y()+(boundingRect().bottom()-boundingRect().top())) < (this->scene()->sceneRect().bottom()))
    {
        this->setPos(x(), y()+10);

        //move down
    }
}

bool Main_player::shark_collision()
{
    collision_item = collidingItems(Qt::IntersectsItemShape);

    for( int i = 0; i < collision_item.size() ; i++ ) {

        if( (typeid(*(collision_item[i])) == typeid(Shark)) && (this->shield == false))
        {

            qDebug() << "hit a shark";
            //shield = true;
            return true;
        }


        else if(typeid(*(collision_item[i])) == typeid(Exit))
        {
          qDebug() << "Level Finished";
        }
    }
return false;
}

void Main_player::recover()
{
    shield = false;
}


void Main_player::sink()
{
    if(shark_collision()==true)
    {

        shield = true;
        player_health->decrease_health();
        recover_timer->start(1000);
    }

    if(this->pos().y()+(boundingRect().bottom()-boundingRect().top()) < (this->scene()->sceneRect().bottom()))
    {
    setPos(x(), y()+1);
    }
}
