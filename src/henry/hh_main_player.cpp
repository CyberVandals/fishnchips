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
    player_oxygen = new Oxygen(scene);

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
    //experi start
    scene();
    //experi end
    if( event->key() == Qt::Key_Left && (this->pos().x()) > (this->scene()->sceneRect().left()))
    {
        //if(platform_collision() == false)
        //if(scene()->itemAt(this->pos().rx(), this->pos().ry()) == 0)
        //{
          this->setPos(x()-10, y());  //
        //}
        //this->setPos(x()-10, y());
        //move left
    }

    else if( event->key() == Qt::Key_Right && (this->pos().x()+(boundingRect().right()-boundingRect().left())) < (this->scene()->sceneRect().right()))
    {
        //if(platform_collision() == false)
        this->setPos(x()+10, y());
        //move right
    }

    else if( event->key() == Qt::Key_Up && (this->pos().y()) > (this->scene()->sceneRect().top()))
    {
        //if(platform_collision() == false)
        //if(scene()->itemAt(QPointF(0, 0)) != Platform)
        this->setPos(x(), y()-10);
        //move up
    }

    else if( event->key() == Qt::Key_Down && (this->pos().y()+(boundingRect().bottom()-boundingRect().top())) < (this->scene()->sceneRect().bottom()))
    {
        //if(platform_collision() == false)
        this->setPos(x(), y()+10);
        //move down
    }
}

int Main_player::shark_collision()
{
    collision_item = collidingItems(Qt::IntersectsItemShape);

    for( int i = 0; i < collision_item.size() ; i++ ) {

        if( (typeid(*(collision_item[i])) == typeid(Shark)) && (this->shield == false))
        {

            qDebug() << "hit a shark";
            //shield = true;
            return 1;
        }


        else if(typeid(*(collision_item[i])) == typeid(Exit))
        {
          return 0;
          qDebug() << "Level Finished";
        }
        else if(typeid(*(collision_item[i])) == typeid(Platform))
        {
            return 2;
        }
    }
    return 3;
}

bool Main_player::platform_collision()
{
    collision_item = collidingItems(Qt::IntersectsItemShape);
    for( int i = 0; i < collision_item.size() ; i++ ) {

        if( typeid(*(collision_item[i])) == typeid(Platform))
        {
            return true;
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
    if(shark_collision()==1)//shark
    {

        shield = true;
        if(player_health->decrease_health() == 0)
        {
            this->setPos(scene()->sceneRect().bottom(), scene()->sceneRect().bottom()-50);
            QGraphicsScene *current_scene = scene();
            player_health = new HealthBar(current_scene);
        }
        recover_timer->start(1000);
    }

    else if(shark_collision()==0)//door
    {
        this->setPos(scene()->sceneRect().bottom(), scene()->sceneRect().bottom()-50);
    }

    if(this->pos().y()+(boundingRect().bottom()-boundingRect().top()) < (this->scene()->sceneRect().bottom()))
    {
    if(shark_collision()!=2)
        setPos(x(), y()+1);
    }
}
