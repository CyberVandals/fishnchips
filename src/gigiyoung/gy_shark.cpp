/* gy_shark.c - Implementation file for shark object
 * By Gigi Young
 */

#include <typeinfo>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QList>
#include <QDebug>
#include "../../inc/gy_object.h"
//#include "../../inc/wz_graphics.h"

using namespace std;

void Shark::init() {
    sound_count = 0;
    stunned = 0;
    cooked = false;
 
    //setPixmap(QPixmap(":/images/blue_shark.png").scaled(10,10));
    //setPixmap(QPixmap(":/images/blue_shark.png"));

    sound = new SoundManager();
    graphics = new Graphics();

    // create timer for move slot
    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );
    timer->start(UPDATE_MS);
}

// Default constructor 
Shark::Shark(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPos( DEFAULT_POS_X, DEFAULT_POS_Y );

    vel.x = DEFAULT_VEL_X;
    vel.y = DEFAULT_VEL_Y;    

    init();
    graphics->load_shark(DEFAULT_SHARK_WIDTH, DEFAULT_SHARK_HEIGHT, this);
}


// Constructor with position 
Shark::Shark(int pos_x, int pos_y,
    QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPos( pos_x, pos_y );

    vel.x = DEFAULT_VEL_X;
    vel.y = DEFAULT_VEL_Y;    

    init();
    graphics->load_shark(DEFAULT_SHARK_WIDTH, DEFAULT_SHARK_HEIGHT, this);
} 

// Constructor with position and velocity 
Shark::Shark(int pos_x, int pos_y, int vel_x, int vel_y,
    QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPos( pos_x, pos_y );

    vel.x = vel_x;
    vel.y = vel_y;    

    init();
    graphics->load_shark(DEFAULT_SHARK_WIDTH, DEFAULT_SHARK_HEIGHT, this);
}

// Constructor with position and velocity 
Shark::Shark(int width, int height, int pos_x, int pos_y, int vel_x, int vel_y,
    QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPos( pos_x, pos_y );

    vel.x = vel_x;
    vel.y = vel_y;    

    init();
    graphics->load_shark(width, height, this);
}


bool Shark::stun(int time) {
    if( time > 0 ) 
        stunned = time;
        //return true;
    
    //return false;
    return stunned > 0;
}

bool Shark::cook() {
    // "cook" shark

    // change public slot

    return cooked = true;
}

void Shark::move() {
    static const int X_BUFFER = 50;
    static const int Y_BUFFER = 8;
    //qDebug() << "Shark is moving\n";
    static int scene_right = scene()->sceneRect().right();
    static int scene_left = scene()->sceneRect().left(); 
    static int scene_top = scene()->sceneRect().top();
    static int scene_bottom = scene()->sceneRect().bottom();
    int shark_right, shark_left, shark_top, shark_bottom;


    // stunned, decrement
    if( stunned > 0 ) {
        stunned--;
        return;
    }
    if(sound_count > 0) {
        sound_count--;
    }
 
    // calculate
    shark_right = x() + this->boundingRect().width();
    shark_left = x(); //this->boundingRect().left();
    shark_top = y(); //this->boundingRect().top();
    shark_bottom = y() + this->boundingRect().height();

    //qDebug() << scene()->sceneRect().left() << ", "
    //         << scene()->sceneRect().right();
    //qDebug() << "Shark is at " << x() << ", " << y(); 
    //qDebug() << "Shark's velocity is " << vel.x << ", " << vel.y; 

    QList<QGraphicsItem *> items = 
        //collidingItems(Qt::IntersectsItemBoundingRect);
        collidingItems(Qt::IntersectsItemShape);

    // if left or right edges of scene, reverse x velocity
    if ( (shark_left <= scene_left && vel.x < 0) || 
         (shark_right >= scene_right && vel.x > 0) ) 
    {
        vel.x = -vel.x;
    }
    // if top or bottom edges of scene, reverse x velocity
    else if ( (shark_top <= scene_top && vel.y < 0) || 
         (shark_bottom >= scene_bottom && vel.y > 0) ) 
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
/*
            if( (y() >= plat_bottom) && (y() <= plat_top) ) {
                if( vel.y > 0 || vel.y < 0)
                    vel.y = -vel.y;
            }

            if( (shark_right >= plat_left && 
                 shark_right <= plat_left + BUFFER &&
                 shark_left < plat_left && vel.x > 0) ||
                (shark_left <= plat_right && 
                 shark_left >= plat_right - BUFFER && 
                 shark_right > plat_right &&  vel.x < 0) ) 

this one kind works
            if( (shark_right >= plat_left && 
                 shark_left < plat_left && vel.x > 0) ||
                (shark_left <= plat_right && 
                 shark_right > plat_right &&  vel.x < 0) ) 
*/
            if( ((shark_right >= plat_left && 
                 shark_right <= plat_left + X_BUFFER) && vel.x > 0) ||
                ((shark_left <= plat_right && 
                 shark_left >= plat_right - X_BUFFER) &&  vel.x < 0) ) 
            {
                vel.x = -vel.x;
            }

            if( (shark_bottom >= plat_top && 
                 shark_top < plat_top && vel.y > 0) || 
                (shark_top <= plat_bottom && 
                 shark_bottom > plat_bottom && vel.y < 0) )

/*
            if( (shark_bottom >= plat_top - Y_BUFFER && 
                 shark_bottom <= plat_top + Y_BUFFER && vel.y > 0) || 
                (shark_top <= plat_bottom + Y_BUFFER && 
                 shark_top >= plat_bottom - Y_BUFFER && vel.y < 0) )
*/
            {
                vel.y = -vel.y;
            }
            

        }
        if( typeid(*(items[i])) == typeid(Main_player) ) {
            if(sound_count == 0) {
                sound->playChomp();
                sound_count = PLAYER_IMMUNE_DURATION;
            }
        }

        // if collision with thrown banana, stun shark
        if( typeid(*(items[i])) == typeid(Banana) ) {
            Banana *banana = (Banana *)items[i];

            if( banana->is_thrown() )
                stun(); 
        }
    }

    // update position
    setPos( x()+vel.x, y()+vel.y );
}

void Shark::status() {
    qDebug() << "I am a shark. I am now chum.";

}
