/* gy_shark.c - Implementation file for shark object
 * By Gigi Young
 */

#include <typeinfo>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QList>
#include <QDebug>
#include "../../inc/gigiyoung/gy_object.h"

using namespace std;

void Shark::init() {
    stun_duration = 0;
    cooked = false;

    //setBoundingRegionGranularity(1);
    setActive(false);

    // create timer for move slot
    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );
    timer->start(UPDATE_MS);
}

// Default constructor 
Shark::Shark(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
//Shark::Shark(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // init size and position
    setRect( DEFAULT_POS_X, DEFAULT_POS_Y, DEFAULT_SHARK_WIDTH,
             DEFAULT_SHARK_HEIGHT );

    //QRectF( DEFAULT_POS_X, DEFAULT_POS_Y, DEFAULT_SHARK_WIDTH,
    //         DEFAULT_SHARK_HEIGHT );
    // init velocity
    vel.x = DEFAULT_VEL_X;
    vel.y = DEFAULT_VEL_Y;    

    init();
}


// Constructor with position 
Shark::Shark(int pos_x, int pos_y,
    QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
//    QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // init size and position
    setRect( pos_x, pos_y, DEFAULT_SHARK_WIDTH, DEFAULT_SHARK_HEIGHT );
    //QRectF( pos_x, pos_y, DEFAULT_SHARK_WIDTH, DEFAULT_SHARK_HEIGHT );

    // init velocity
    vel.x = DEFAULT_VEL_X;
    vel.y = DEFAULT_VEL_Y;    

    init();
} 

// Constructor with position and velocity 
Shark::Shark(int pos_x, int pos_y, int vel_x, int vel_y,
    QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
//    QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // init size and position
    setRect( pos_x, pos_y, DEFAULT_SHARK_WIDTH, DEFAULT_SHARK_HEIGHT );
    //QRectF( pos_x, pos_y, DEFAULT_SHARK_WIDTH, DEFAULT_SHARK_HEIGHT );

    // init velocity
    vel.x = vel_x;
    vel.y = vel_y;    

    init();
}

// Constructor with all arguments
Shark::Shark(int width, int height, int pos_x, int pos_y, int vel_x, int vel_y,
    QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
//    QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // init size and position
    setRect( pos_x, pos_y, width, height );
    //QRectF( pos_x, pos_y, width, height );

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

bool Shark::cook() {
    // "cook" shark

    // change public slot

    return (cooked = true);
}

void Shark::move() {
    //qDebug() << "Shark is moving\n";
    int scene_right, scene_left, scene_top, scene_bottom;
    scene_right = scene()->sceneRect().right();
    scene_left = scene()->sceneRect().left();
    scene_top = scene()->sceneRect().top();
    scene_bottom = scene()->sceneRect().bottom();

    // stunned, decrement
    if( stun_duration > 0 ) {
        stun_duration--;
        return;
    }

    QList<QGraphicsItem *> colliding_items = 
        collidingItems(Qt::IntersectsItemShape);

    qDebug() << scene()->sceneRect().left() << ", "
             << scene()->sceneRect().right();
    qDebug() << "Shark is at " << x() << ", " << y(); 
    qDebug() << "Shark's velocity is " << vel.x << ", " << vel.y; 

    // if left or right edges of scene, reverse x velocity
    if ( (x() >= ( scene_right-boundingRect().width() ) && vel.x > 0) || 
         (x() <= scene_left && vel.x < 0) ) 
    {
        vel.x = -vel.x;
    }
    // if top or bottom edges of scene, reverse x velocity
    else if ( (y() <= scene_top && vel.y < 0) || 
         (y() >= ( scene_bottom-boundingRect().height() ) && vel.y > 0) ) 
    {
        vel.y = -vel.y;
    }



    // if collision with platform, invert x velocity
    //for( int i = 0; i < colliding_items.size() ; i++ ) {
    //    if( typeid( *(colliding_items[i]) ) == typeid(Platform) )
    //        vel.x = -vel.x; 
    //}

    // update position
    setPos( x()+vel.x, y()+vel.y );
}

void Shark::status() {
    qDebug() << "I am a shark. I am now chum.";

}
