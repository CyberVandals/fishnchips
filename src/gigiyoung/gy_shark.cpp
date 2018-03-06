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
    stunned = 0;
    cooked = false;
 
//    setPixmap(QPixmap("../../resources/images/blue_shark.png").scaled(10,10));
    //setPixmap(QPixmap(":/images/blue_shark.png").scaled(10,10));

    //setPixmap(QPixmap(":/images/blue_shark.png"));

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
    //qDebug() << "Shark is moving\n";
    int scene_right, scene_left, scene_top, scene_bottom;
    scene_right = scene()->sceneRect().right();
    scene_left = scene()->sceneRect().left();
    scene_top = scene()->sceneRect().top();
    scene_bottom = scene()->sceneRect().bottom();

    

    // stunned, decrement
    if( stunned > 0 ) {
        stunned--;
        return;
    }

    QList<QGraphicsItem *> items = 
        collidingItems(Qt::IntersectsItemShape);

    //qDebug() << scene()->sceneRect().left() << ", "
    //         << scene()->sceneRect().right();
    //qDebug() << "Shark is at " << x() << ", " << y(); 
    //qDebug() << "Shark's velocity is " << vel.x << ", " << vel.y; 

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



    for( int i = 0; i < items.size() ; i++ ) {
        // if collision with platform, invert x velocity
        if( typeid(*(items[i])) == typeid(Platform) )
            vel.x = -vel.x; 

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
