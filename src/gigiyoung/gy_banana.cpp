/* gy_banana.c - Implementation file for banana objects 
 * By Gigi Young
 */

#include <QObject>
#include <QTimer>
#include <QList>
#include <QGraphicsRectItem>
#include <QDebug>
#include <typeinfo>
#include "../../inc/gy_object.h"
//#include "../../inc/wei/wz_graphics.h"



void Banana::init() {

    thrown = false;

    graphics = new Graphics();

    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(status()) );
    timer->start(UPDATE_MS);
}


// Banana
Banana::Banana(QGraphicsItem *parent): 
    QObject(), QGraphicsPixmapItem(parent) 
{
    setPos( DEFAULT_POS_X, DEFAULT_POS_Y );
    init();
    graphics->load_banana(
        DEFAULT_BANANA_WIDTH, DEFAULT_BANANA_HEIGHT, this);
}

Banana::Banana(int pos_x, int pos_y, QGraphicsItem *parent): 
    QObject(), QGraphicsPixmapItem(parent) 
{


    setPos( pos_x, pos_y );
    init();
    graphics->load_banana(
        DEFAULT_BANANA_WIDTH, DEFAULT_BANANA_HEIGHT, this);
}

Banana::Banana(int width, int height, int pos_x, int pos_y, 
    QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) 
{

    setPos( pos_x, pos_y );
    init();
    graphics->load_banana(width, height, this);
}


void Banana::status() {
    QList<QGraphicsItem *> items = 
        collidingItems(Qt::IntersectsItemShape);

    //qDebug() << "in Banana::check_player()\n";
    for( int i = 0; i < items.size() ; i++ ) {
        // player picked up banana 
        //if( typeid( *(items[i]) ) == typeid(MainPlayer) ) {
            
        //}
    }
}


void Banana::move() {
    QList<QGraphicsItem *> items = 
        collidingItems(Qt::IntersectsItemShape);

    //qDebug() << "in BananaProjectile::move()\n";

    for( int i = 0; i < items.size() ; i++ ) {

        // if collision with platform, deallocate banana
        if( typeid( *(items[i]) ) == typeid(Platform) ) {
            // splat sound effect
            // deallocate
            delete this;
        }
        // if collision with shark, deallocate banana and set shark
        // paralysis timer 
        else if( typeid( *(items[i]) ) == typeid(Shark) ) {
            Shark *shark = (Shark *)items[i];
            // splat sound effect

            shark->stun();

            // deallocate
            delete this;
        }
    }



    // update position
    setPos( x()+vel.x, y()+vel.y );

}

bool Banana::chuck(int direction) {
    thrown = true;

    // disconnect timer from method
    timer->stop();
    disconnect( timer, SIGNAL(timeout()), this, SLOT(status()) );

    // connect to new method
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );
    timer->start(UPDATE_MS);
    
    return thrown;
}

bool Banana::pickup() {
    return false;
}

bool Banana::eat() {
    return false;
}

bool Banana::is_thrown() {
    return thrown > 0;
}
