#include "../../inc/hh_main_player.h"
#include "../../inc/henry/hh_health_bar.h"

#include <QDebug>
#include <typeinfo>

LoadMainPlayer * LoadMainPlayer::instance=NULL;
LoadMainPlayer * player_pic = LoadMainPlayer::get_instance();

MainPlayer::MainPlayer(QGraphicsScene * scene,QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //player_pic = new Graphics();
    //player_pic->load_mainplayer(50,50, this,false,true);
    //start
    player_pic->set_high(50);
    player_pic->set_width(50);
    player_pic->set_direction(false);
    player_pic->load_main_player(this);
    //end
    setPos(scene->sceneRect().bottom(), scene->sceneRect().bottom()-50);
    setFlag(QGraphicsItem::ItemIsFocusable);

    player_scene = scene;


    setFocus();

    player_health = new HealthBar(scene);
    player_oxygen = new Oxygen(scene);
    scene_manager = new SceneManager(scene);

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

void MainPlayer::keyPressEvent(QKeyEvent *event)
{


    if(event->key() == Qt::Key_Z)
    {


            if(this->has_banana == true)
             {
                this->banana->chuck(LEFT);
                this->banana->set_thrown(true);
                this->has_banana = false;
                //qDebug() << "i threw my banana!!!!!!!!!!!!!!!";
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
                //qDebug() << "i threw my banana!!!!!!!!!!!!!!!";
                this->banana = NULL;
             }

    }

    else if(event->key() == Qt::Key_E && this->has_banana == true)
    {
       QGraphicsScene * scene = this->scene();
        this->player_health->add_health(scene);
       this->banana->eat();
       this->banana = NULL;
       this->has_banana = false;
    }


    else if( event->key() == Qt::Key_Left && (this->pos().x()) > (this->scene()->sceneRect().left()))
    {
        //this->player_pic->load_mainplayer(50,50, this,true,false);
        player_pic->set_direction(true);
          player_pic->load_main_player(this);

        int list_length = collidingItems(Qt::IntersectsItemBoundingRect).length();

        if(list_length == 0 || list_length == 1)
        {
            if(list_length == 1 && this->has_banana == true) {setPos(x()-10,y()); }
            else if(list_length == 0 && left_collision == false) setPos(x()-10,y());
            else if(list_length == 1 && left_collision == false) setPos(x()-10,y());

            if(collidingItems(Qt::IntersectsItemBoundingRect).length() > list_length)
          {
              if(this->platform_collision()) this->left_collision = true;
              //qDebug() << "hit platform down";
          }
          this->right_collision = false;
        }
        else
        {
            if(list_length > 1)
            {
                if(this->left_collision == false)
                {
                    setPos(x()-10,y());
                    this->right_collision = false;
                    if(collidingItems(Qt::IntersectsItemBoundingRect).length() > list_length) this->left_collision = true;
                }
            }
        }



    }
        //move left


    else if( event->key() == Qt::Key_Right && (this->pos().x()+(boundingRect().right()-boundingRect().left())) < (this->scene()->sceneRect().right()))
    {
        //this->player_pic->load_mainplayer(50,50, this,false,true);
        player_pic->set_direction(false);
        player_pic->load_main_player(this);

        int list_length = collidingItems(Qt::IntersectsItemBoundingRect).length();

        if(list_length == 0 || list_length == 1)
        {
           if(list_length == 1 && this->has_banana == true)setPos(x()+10,y());
           else if(list_length == 0 && this->right_collision == false)setPos(x()+10,y());
           else if(list_length == 1 && this->right_collision == false) setPos(x()+10,y());

           if(collidingItems(Qt::IntersectsItemBoundingRect).length() > list_length)
          {
              if(this->platform_collision()) this->right_collision = true;
              //qDebug() << "hit platform down";
          }
          this->left_collision = false;
        }
        else
        {
            if(list_length > 1)
            {
                if(this->right_collision == false)
                {
                    setPos(x()+10,y());
                    this->left_collision = false;
                    if(collidingItems(Qt::IntersectsItemBoundingRect).length() > list_length) this->right_collision = true;
                }
            }
        }


        //move right
    }

    else if( event->key() == Qt::Key_Up && (this->pos().y()) > (this->scene()->sceneRect().top()))
    {

        int list_length = collidingItems(Qt::IntersectsItemBoundingRect).length();

        if(list_length == 0 || list_length == 1)
        {
          if(list_length == 1 && this->has_banana == true){setPos(x(),y()-10);}
          else if(list_length == 0 && this->top_collision == false){setPos(x(),y()-10);}
          else if(list_length == 1 && this->top_collision == false) {setPos(x(),y()-10);}
          //qDebug() << "here";
          this->sink_collision = false;
          if(collidingItems(Qt::IntersectsItemBoundingRect).length() > list_length)
          {
              if(this->platform_collision()) {this->top_collision = true; this->bottom_collision = false;}
              //qDebug() << "hit platform up";
          }
          this->bottom_collision = false;
        }
        else
        {
            if(list_length > 1)
            {
                if(this->top_collision == false)
                {
                    setPos(x(),y()-10);
                    //qDebug() << "or here";
                    this->sink_collision = false;
                    this->bottom_collision = false;
                    if(collidingItems(Qt::IntersectsItemBoundingRect).length() > list_length) this->top_collision = true;
                }

            }
        }

    }

    else if( event->key() == Qt::Key_Down && (this->pos().y()+(boundingRect().bottom()-boundingRect().top())) < (this->scene()->sceneRect().bottom()))
    {

        int list_length = collidingItems(Qt::IntersectsItemBoundingRect).length();

        if(list_length == 0 || list_length == 1)
        {
          if(list_length == 1 && this->has_banana == true){setPos(x(),y()+10);}
          else if(list_length == 0 && this->bottom_collision == false){setPos(x(),y()+10);}
          else if(list_length == 1 && this->bottom_collision == false) {setPos(x(),y()+10);}
          //qDebug() << "here";
          if(collidingItems(Qt::IntersectsItemBoundingRect).length() > list_length)
          {
              if(this->platform_collision()) {this->bottom_collision = true; this->top_collision = false;}
              //qDebug() << "hit platform up";
          }
          this->top_collision = false;
        }
        else
        {
            if(list_length > 1)
            {
                if(this->bottom_collision == false)
                {
                    setPos(x(),y()+10);
                    //qDebug() << "or here";
                    this->sink_collision = false;
                    this->top_collision = false;
                    if(collidingItems(Qt::IntersectsItemBoundingRect).length() > list_length) this->bottom_collision = true;
                }

            }
        }
        //move down
    }
}

int MainPlayer::shark_collision()
{
    collision_item = collidingItems(Qt::IntersectsItemShape);

    for( int i = 0; i < collision_item.size() ; i++ ) {

        if( (typeid(*(collision_item[i])) == typeid(Shark)) && (this->shield == false))
        {
            return 1;
        }

        else if(typeid(*(collision_item[i])) == typeid(Banana) && this->has_banana == false)
        {
            if(this->banana == NULL)
            {
                this->banana = (Banana*)collision_item[i];

                if(this->banana->thrown() == true) this->banana = NULL;

                //else qDebug() << "i have a banana!!!!!!!!!!!!!!!!!!!!!!";
            }
            return 3;
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

bool MainPlayer::platform_collision()
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

void MainPlayer::recover()
{
    shield = false;
}


void MainPlayer::sink()
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
            //delete this;
            QTimer::singleShot(0,player_scene->parent(), SLOT(display_gameover()));
            //this->scene()->removeItem(this);
        }
        else recover_timer->start(1000);
    }

    else if(shark_collision()==0)//door
    {
        this->setPos(scene()->sceneRect().bottom(), scene()->sceneRect().bottom()-50);
        this->scene_manager->next_level();
    }

    else if(shark_collision()==3)
    {
        if(this->banana!=NULL)this->has_banana = true;
    }

    if(this->pos().y()+(boundingRect().bottom()-boundingRect().top()) < (this->scene()->sceneRect().bottom()))
    {
    if(this->collidingItems(Qt::IntersectsItemShape).isEmpty() && this->sink_collision == false)
    {
        //setPos(x(),y()+1);
        //if(!this->collidingItems(Qt::IntersectsItemShape).isEmpty()) this->sink_collision = true;

    }
    else if(!this->collidingItems(Qt::IntersectsItemShape).isEmpty())
    {
        if(this->bottom_collision == false)
        {
            //setPos(x(), y()+1);
            //if(!this->collidingItems(Qt::IntersectsItemShape).isEmpty()) this->sink_collision = true;
        }
    }
    }
}
