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

    player_scene = scene;

    setFocus();

    player_health = new HealthBar(scene);
    player_oxygen = new Oxygen(scene);

    right_collision = false;
    left_collision = false;
    top_collision = false;
    bottom_collision = false;


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
    QPointF current_pos = scenePos();
    QPointF down_pos = QPointF(current_pos.x(), current_pos.y()+60);
    QPointF up_pos = QPointF(this->pos().x(), this->boundingRect().top()+10);
    QPointF right_pos = QPointF(current_pos.x()+30, current_pos.y());
    QPointF left_pos = QPointF(current_pos.x()-5, current_pos.y());



    qreal x_pos = current_pos.x();
    qreal y_pos = current_pos.y();
    //experi end
    if( event->key() == Qt::Key_Left && (this->pos().x()) > (this->scene()->sceneRect().left()))
    {
        if(collidingItems(Qt::IntersectsItemShape).isEmpty())
        {
          setPos(x()-10,y());
          if(!collidingItems(Qt::IntersectsItemShape).isEmpty())
          {
              this->left_collision = true;
              qDebug() << "hit platform down";
          }
          this->right_collision = false;
        }
        else
        {
            if(!collidingItems(Qt::IntersectsItemShape).isEmpty())
            {
                if(this->left_collision == false)
                {
                    setPos(x()-10,y());
                    this->right_collision = false;
                }
            }
        }



    }
        //move left


    else if( event->key() == Qt::Key_Right && (this->pos().x()+(boundingRect().right()-boundingRect().left())) < (this->scene()->sceneRect().right()))
    {
        if(collidingItems(Qt::IntersectsItemShape).isEmpty())
        {
          setPos(x()+10,y());
          if(!collidingItems(Qt::IntersectsItemShape).isEmpty())
          {
              this->right_collision = true;
              qDebug() << "hit platform down";
          }
          this->left_collision = false;
        }
        else
        {
            if(!collidingItems(Qt::IntersectsItemShape).isEmpty())
            {
                if(this->right_collision == false)
                {
                    setPos(x()+10,y());
                    this->left_collision = false;
                }
            }
        }


        //move right
    }

    else if( event->key() == Qt::Key_Up && (this->pos().y()) > (this->scene()->sceneRect().top()))
    {
        if(collidingItems(Qt::IntersectsItemShape).isEmpty())
        {
          setPos(x(),y()-10);
          if(!collidingItems(Qt::IntersectsItemShape).isEmpty())
          {
              this->top_collision = true;
              qDebug() << "hit platform up";
          }
          this->bottom_collision = false;
        }
        else
        {
            if(!collidingItems(Qt::IntersectsItemShape).isEmpty())
            {
                if(this->top_collision == false)
                {
                    setPos(x(),y()-10);
                    this->bottom_collision = false;
                }

            }
        }

    }

     /*
        if(collidingItems(Qt::IntersectsItemShape).isEmpty() && this->top_collision == false)
        {
            qDebug() << "good";
            this->setPos(x(), y()-10);
            this->bottom_collision = false;
        }
            else{
            while(!collidingItems(Qt::IntersectsItemShape).isEmpty()){this->setPos(x(), y()+1);}
            qDebug() << "bad";
            this->top_collision=true;
            this->bottom_collision = false;
        }
        //move up
    */


    else if( event->key() == Qt::Key_Down && (this->pos().y()+(boundingRect().bottom()-boundingRect().top())) < (this->scene()->sceneRect().bottom()))
    {
        if(collidingItems(Qt::IntersectsItemShape).isEmpty())
        {
          setPos(x(),y()+10);
          if(!collidingItems(Qt::IntersectsItemShape).isEmpty())
          {
              this->bottom_collision = true;
              qDebug() << "hit platform down";
          }
          this->top_collision = false;
        }
        else
        {
            if(!collidingItems(Qt::IntersectsItemShape).isEmpty())
            {
                if(this->bottom_collision == false)
                {
                    setPos(x(),y()+10);
                    this->top_collision = false;
                }
            }
        }


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
            QTimer::singleShot(0,player_scene->parent(), SLOT(displayGameover()));
            //this->setPos(scene()->sceneRect().bottom(), scene()->sceneRect().bottom()-50);
            //QGraphicsScene *current_scene = scene();
            //player_health = new HealthBar(current_scene);
        }
        recover_timer->start(1000);
    }

    else if(shark_collision()==0)//door
    {
        this->setPos(scene()->sceneRect().bottom(), scene()->sceneRect().bottom()-50);
    }

    if(this->pos().y()+(boundingRect().bottom()-boundingRect().top()) < (this->scene()->sceneRect().bottom()))
    {
    //if(shark_collision()!=2)
        //setPos(x(), y()+1);
    }
}
