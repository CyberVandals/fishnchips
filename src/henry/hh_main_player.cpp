#include "../../inc/hh_main_player.h"
#include "../../inc/henry/hh_health_bar.h"

//#include "../../inc/gy_object.h"
#include <QDebug>
#include <typeinfo>
Main_player::Main_player(QGraphicsScene * scene,QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    player_pic = new Graphics();
    player_pic->load_mainplayer(50,50, this);
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
    sink_collision = false;

    banana = NULL;
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


    if(event->key() == Qt::Key_Z)
    {


            if(this->has_banana == true)
             {
                this->banana->chuck(LEFT);
                this->banana->set_thrown(true);
                this->has_banana = false;
                qDebug() << "i threw my banana!!!!!!!!!!!!!!!";
                this->banana = NULL;
             }

    }
    else if(event->key() == Qt::Key_X)
    {


            if(this->has_banana == true)
             {
                this->banana->chuck(RIGHT);
                this->banana->set_thrown(true);
                this->has_banana = false;
                qDebug() << "i threw my banana!!!!!!!!!!!!!!!";
                this->banana = NULL;
             }

    }

    else if( event->key() == Qt::Key_Left && (this->pos().x()) > (this->scene()->sceneRect().left()))
    {

        if(collidingItems(Qt::IntersectsItemShape).isEmpty())
        {
          setPos(x()-10,y());
          if(!collidingItems(Qt::IntersectsItemShape).isEmpty())
          {
              if(this->platform_collision()) this->left_collision = true;
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
              if(this->platform_collision()) this->right_collision = true;
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
          this->sink_collision = false;
          if(!collidingItems(Qt::IntersectsItemShape).isEmpty())
          {
              if(this->platform_collision()) this->top_collision = true;
              //qDebug() << "hit platform up";
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
                    this->sink_collision = false;
                    this->bottom_collision = false;
                }

            }
        }

    }

    else if( event->key() == Qt::Key_Down && (this->pos().y()+(boundingRect().bottom()-boundingRect().top())) < (this->scene()->sceneRect().bottom()))
    {

       if(collidingItems(Qt::IntersectsItemShape).isEmpty())
        {
          setPos(x(),y()+10);
          if(!collidingItems(Qt::IntersectsItemShape).isEmpty())
          {
              if(this->platform_collision()) this->bottom_collision = true;
              //this->sink_collision = true;
              //qDebug() << "hit platform down";
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

        else if(typeid(*(collision_item[i])) == typeid(Banana) && this->has_banana == false)
        {
            if(this->banana == NULL)
            {
                this->banana = (Banana*)collision_item[i];

                if(this->banana->thrown() == true) this->banana = NULL;

                else qDebug() << "i have a banana!!!!!!!!!!!!!!!!!!!!!!";
            }
            return 69;
        }

        else if(typeid(*(collision_item[i])) == typeid(Exit))
        {
          return 0;
          qDebug() << "Level Finished";
        }
        else if(typeid(*(collision_item[i])) == typeid(Steam) && (this->shield == false))
        {
            Steam * steam = (Steam*)collision_item[i];
            if(steam->active() == true) return 2;
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
    if(player_oxygen->value() == 0)
    {
        QTimer::singleShot(0,player_scene->parent(), SLOT(display_gameover()));
    }
    if(shark_collision()==1 || shark_collision() == 2)
    {

        shield = true;
        if(player_health->decrease_health() == 0)
        {
            QTimer::singleShot(0,player_scene->parent(), SLOT(display_gameover()));
        }
        recover_timer->start(1000);
    }

    else if(shark_collision()==0)//door
    {
        this->setPos(scene()->sceneRect().bottom(), scene()->sceneRect().bottom()-50);
    }

    else if(shark_collision()==69)
    {
        if(this->banana!=NULL)this->has_banana = true;
    }

    if(this->pos().y()+(boundingRect().bottom()-boundingRect().top()) < (this->scene()->sceneRect().bottom()))
    {
    if(this->collidingItems(Qt::IntersectsItemShape).isEmpty() && this->sink_collision == false)
    {
        setPos(x(),y()+1);
        if(!this->collidingItems(Qt::IntersectsItemShape).isEmpty()) this->sink_collision = true;

    }
    else if(!this->collidingItems(Qt::IntersectsItemShape).isEmpty())
    {
        if(this->bottom_collision == false)
        {
            setPos(x(), y()+1);
            if(!this->collidingItems(Qt::IntersectsItemShape).isEmpty()) this->sink_collision = true;
        }
    }
    }
}
