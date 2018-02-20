/* gy_banana.c - Implementation file for banana objects 
 * By Gigi Young
 */

#include <QObject>
#include <QTimer>
#include <QList>
#include <QGraphicsRectItem>
#include <QDebug>
#include <typeinfo>
#include "../../inc/gigiyoung/gy_object.h"


// Banana
Banana::Banana(QGraphicsItem *parent): 
    QObject(), QGraphicsRectItem(parent) 
{

    setRect( DEFAULT_POS_X, DEFAULT_POS_Y, 
             DEFAULT_PLAT_WIDTH, DEFAULT_PLAT_HEIGHT ); 

    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(check_player()) );
    timer->start(UPDATE_MS);
}

Banana::Banana(int pos_x, int pos_y, QGraphicsItem *parent): 
    QObject(), QGraphicsRectItem(parent) 
{
    setRect( pos_x, pos_y, 
             DEFAULT_PLAT_WIDTH, DEFAULT_PLAT_HEIGHT ); 

    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(check_player()) );
    timer->start(UPDATE_MS);
}

Banana::Banana(int width, int height, int pos_x, int pos_y,
    QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent) 
{
    setRect( pos_x, pos_y, width, height ); 

    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(check_player()) );
    timer->start(UPDATE_MS);
}

void Banana::check_player() {
    qDebug() << "in Banana::check_player()\n";
}


// BananaProjectile

/*
BananaProjectile::BananaProjectile(QGraphicsItem *parent): 
    QObject(), QGraphicsRectItem(parent) 
{
    setRect( DEFAULT_POS_X, DEFAULT_POS_Y, 
             DEFAULT_PLAT_WIDTH, DEFAULT_PLAT_HEIGHT ); 
    
    vel.x = DEFAULT_VEL_X;
    vel.y = DEFAULT_VEL_Y;

    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );
    timer->start(UPDATE_MS);
}

void BananaProjectile::move() {
    QList<QGraphicsItem *> colliding_items = 
        collidingItems(Qt::IntersectsItemShape);

    qDebug() << "in Banana::move()\n";

    for( int i = 0; i < colliding_items.size() ; i++ ) {
        // if collision with platform, deallocate banana
        if( typeid( *(colliding_items[i]) ) == typeid(Platform) ) {

        }
        // if collision with shark, deallocate banana and set shark
        // paralysis timer 
        else if( typeid( *(colliding_items[i]) ) == typeid(Shark) ) {

        }
    }

    // update position
    setPos( x()+vel.x, y()+vel.y );

}
*/
