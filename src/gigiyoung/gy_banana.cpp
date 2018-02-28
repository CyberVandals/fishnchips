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


void Banana::init() {

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
}

Banana::Banana(int pos_x, int pos_y, QGraphicsItem *parent): 
    QObject(), QGraphicsPixmapItem(parent) 
{
    setPos( pos_x, pos_y );
    init();
}

void Banana::status() {
    //qDebug() << "in Banana::check_player()\n";
}


void Banana::move() {
    QList<QGraphicsItem *> colliding_items = 
        collidingItems(Qt::IntersectsItemShape);

    //qDebug() << "in BananaProjectile::move()\n";

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

bool Banana::chuck(int direction) {
    return false;
}

bool Banana::pickup() {
    return false;
}

bool Banana::eat() {
    return false;
}
