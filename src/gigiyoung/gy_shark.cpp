/********************************* 
 * gy_shark.cpp
 * 
 * By Gigi Young
 ********************************/

#include <typeinfo>
#include <QList>
#include <QDebug>
#include "../../inc/gy_object.h"

Shark::Shark(QGraphicsItem *parent): AbstractObject(parent) {
    init();

    setPos(DEFAULT_POS_X, DEFAULT_POS_Y);
    vel.x = DEFAULT_VEL_X;
    vel.y = DEFAULT_VEL_Y;    

    set_image();   
    timer->start(UPDATE_MS);
}


Shark::Shark(int x, int y, QGraphicsItem *parent): 
    AbstractObject(parent)
{
    init();

    setPos(x, y);
    vel.x = DEFAULT_VEL_X;
    vel.y = DEFAULT_VEL_Y;    

    set_image();   
    timer->start(UPDATE_MS);
} 

Shark::Shark(int x, int y, int vel_x, int vel_y,
    QGraphicsItem *parent): AbstractObject(parent)
{
    init();

    setPos(x, y);
    vel.x = vel_x;
    vel.y = vel_y;    
    
    set_image();   
    timer->start(UPDATE_MS);
}

void Shark::init() {
    sound_count = 0;
    stun_duration = 0;
    is_cooked = false;
 
    timer = new QTimer(this);
    graphics = new Graphics();
    sound = new SoundManager();

    // create timer for move slot
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Shark::set_image() {
    // facing right 
    if( vel.x > 0 ) {
        graphics->load_shark(
            DEFAULT_SHARK_WIDTH, DEFAULT_SHARK_HEIGHT, this,
            false, true);
    }
    // facing left
    else {
        graphics->load_shark(
            DEFAULT_SHARK_WIDTH, DEFAULT_SHARK_HEIGHT, this,
            true, false);
    }
}

void Shark::pause() {
    if( timer != NULL )
        timer->stop();
}

void Shark::resume() {
    if( timer != NULL )
        timer->start();
}

void Shark::stun(int time) {
    if( time > 0 ) 
        stun_duration = time;
}

bool Shark::cooked() {
    // "cook" shark

    // change public slot

    return is_cooked;
}

void Shark::move() {
/*
    static const int X_BUFFER = 50;
    static int scene_right = scene()->sceneRect().right();
    static int scene_left = scene()->sceneRect().left(); 
    static int scene_top = scene()->sceneRect().top();
    static int scene_bottom = scene()->sceneRect().bottom();
    static int shark_right, shark_left, shark_top, shark_bottom;
*/

    const int X_BUFFER = 50;
    int scene_right = scene()->sceneRect().right();
    int scene_left = scene()->sceneRect().left(); 
    int scene_top = scene()->sceneRect().top();
    int scene_bottom = scene()->sceneRect().bottom();
    int shark_right, shark_left, shark_top, shark_bottom;


    // stunned, decrement
    if( stun_duration > 0 ) {
        stun_duration--;
        return;
    }

    // decrement timer for sound - same as player immunity duration
    if( sound_count > 0 ) {
        sound_count--;
    }
 
    // calculate
    shark_right = x() + this->boundingRect().width();
    shark_left = x(); 
    shark_top = y(); 
    shark_bottom = y() + this->boundingRect().height();

    QList<QGraphicsItem *> items = 
        collidingItems(Qt::IntersectsItemShape);

    // if left or right edges of scene, reverse x velocity
    if ( (shark_left <= scene_left && vel.x < 0) 
         || (shark_right >= scene_right && vel.x > 0) ) 
    {
        vel.x = -vel.x;
        set_image();
        //graphics->shark_flip(this,true,false);
    }
    // if top or bottom edges of scene, reverse x velocity
    else if ( (shark_top <= scene_top && vel.y < 0) 
              || (shark_bottom >= scene_bottom && vel.y > 0) ) 
    {
        vel.y = -vel.y;
    }



    for( int i = 0; i < items.size() ; i++ ) {
        // if collision with platform, invert x velocity
        if( typeid(*(items[i])) == typeid(Platform) ) {
            int plat_right, plat_left, plat_top, plat_bottom;
            QGraphicsItem *platform = items[i];

            // platforms will only be oriented horizontally
            // get platform positions
            plat_right = platform->x() + platform->boundingRect().width();
            plat_left = platform->x(); 
            plat_top = platform->y(); 
            plat_bottom = platform->y() + 
                          platform->boundingRect().height();

            if( ((shark_right >= plat_left 
                && shark_right <= plat_left + X_BUFFER) && vel.x > 0) 
                || ((shark_left <= plat_right 
                && shark_left >= plat_right - X_BUFFER) &&  vel.x < 0) ) 
            {
                vel.x = -vel.x;
                set_image();
                //graphics->shark_flip(this,true,false);
            }

            if( (shark_bottom >= plat_top 
                && shark_top < plat_top && vel.y > 0) 
                || (shark_top <= plat_bottom 
                && shark_bottom > plat_bottom && vel.y < 0) )
            {
                vel.y = -vel.y;
            }
        }
        else if( typeid(*(items[i])) == typeid(Main_player) ) {
            if( sound_count == 0 ) {
                sound->play_chomp();
                sound_count = PLAYER_IMMUNE_DURATION;
            }
        }
/*
        // if collision with thrown banana, stun shark
        else if( typeid(*(items[i])) == typeid(Banana) ) {
            Banana *banana = (Banana *)items[i];

            if( banana->thrown() )
                stun(); 
        }
*/
        else if( typeid(*(items[i])) == typeid(Steam) ) {
            //is_cooked = true;

            //disconnect(timer,SIGNAL(timeout()),this,SLOT(move()));
            //connect(timer,SIGNAL(timeout()),this,SLOT(cooked_status()));
            
        }
    }

    // update position
    setPos(x()+vel.x, y()+vel.y);
}

void Shark::cooked_status() {
    //qDebug() << "I am a shark. I am now chum.";
    
}
