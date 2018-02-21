/* gy_shark.c - Implementation file for shark object
 * By Gigi Young
 */

#include <typeinfo>
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QList>
#include "../../inc/gigiyoung/gy_object.h"

using namespace std;

void Shark::init() {

    stun_duration = 0;

    // create timer for move slot
    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );
    timer->start(UPDATE_MS);
}

// Default constructor 
Shark::Shark(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    // init size and position
    setRect( DEFAULT_POS_X, DEFAULT_POS_Y, DEFAULT_SHARK_WIDTH,
             DEFAULT_SHARK_HEIGHT );

    // init velocity
    vel.x = DEFAULT_VEL_X;
    vel.y = DEFAULT_VEL_Y;    

    init();
}


// Constructor with position 
Shark::Shark(int pos_x, int pos_y,
    QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    // init size and position
    setRect( pos_x, pos_y, DEFAULT_SHARK_WIDTH, DEFAULT_SHARK_HEIGHT );

    // init velocity
    vel.x = DEFAULT_VEL_X;
    vel.y = DEFAULT_VEL_Y;    

    init();
} 

// Constructor with position and velocity 
Shark::Shark(int pos_x, int pos_y, int vel_x, int vel_y,
    QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    // init size and position
    setRect( pos_x, pos_y, DEFAULT_SHARK_WIDTH, DEFAULT_SHARK_HEIGHT );

    // init velocity
    vel.x = vel_x;
    vel.y = vel_y;    

    init();
}

// Constructor with all arguments
Shark::Shark(int width, int height, int pos_x, int pos_y, int vel_x, int vel_y,
    QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    // init size and position
    setRect( pos_x, pos_y, width, height );

    // init velocity
    vel.x = vel_x;
    vel.y = vel_y;    

    init();
}


bool Shark::stun(int time) {
    if( time > 0 ) {
        stun_duration = time;
        return true;
    }
    return false;
}

void Shark::move() {
    QList<QGraphicsItem *> colliding_items = 
        collidingItems(Qt::IntersectsItemShape);

    // if collision with platform, invert x velocity
    for( int i = 0; i < colliding_items.size() ; i++ ) {
        if( typeid( *(colliding_items[i]) ) == typeid(Platform) )
            vel.x = -vel.x; 
    }

    // update position
    setPos( x()+vel.x, y()+vel.y );
}

