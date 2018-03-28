/* gy_banana.cpp - Implementation file for banana objects 
 * By Gigi Young
 */

#include <QList>
#include <QDebug>
#include <typeinfo>
#include "../../inc/gy_object.h"




Banana::Banana(QGraphicsItem *parent): AbstractObject(parent) {
    init();
    setPos(DEFAULT_POS_X, DEFAULT_POS_Y);
    timer->start(UPDATE_MS);
}

Banana::Banana(int x, int y, QGraphicsItem *parent): 
    AbstractObject(parent) 
{
    init();
    setPos(x, y);
    timer->start(UPDATE_MS);
}

void Banana::init() {

    thrown = false;
    picked_up = false;

    // #define these later
    vel.x = 30;
    vel.y = 0;

    timer = new QTimer(this);
    graphics = new Graphics();
    sound = new SoundManager();

    graphics->load_banana(
        DEFAULT_BANANA_WIDTH, DEFAULT_BANANA_HEIGHT, this);
    connect( timer, SIGNAL(timeout()), this, SLOT(status()) );
}

void Banana::pause() {
    if(timer != NULL)
        timer->stop();
}

void Banana::resume() {
    if(timer != NULL)
        timer->start();
}

void Banana::status() {
    if(!picked_up) {
        QList<QGraphicsItem *> items = 
            collidingItems(Qt::IntersectsItemShape);

        //qDebug() << "in Banana::check_player()\n";
        for( int i = 0; i < items.size() ; i++ ) {
            // player picked up banana 
            if(typeid(*(items[i])) == typeid(Main_player)) {
               // make player parent of banana
               this->setParentItem(items[i]); 
               // sets banana position relative to parent's coord system
               setPos(0,0);

               pickup();
            }
        }
    }
}


void Banana::move() {
    QList<QGraphicsItem *> items = 
        collidingItems(Qt::IntersectsItemShape);

    // move banana
    setPos(x()+vel.x, y());

    // check collisions
    for( int i = 0; i < items.size() ; i++ ) {

        // if collision with platform, deallocate banana
        if( typeid( *(items[i]) ) == typeid(Platform) ) {
            // splat sound effect

            scene()->removeItem(this);
            timer->stop();
            disconnect( timer, SIGNAL(timeout()), this, SLOT(move()) );
            // deallocate
            //delete this;
        }
        // if collision with shark, deallocate banana and set shark
        // paralysis timer 
        else if( typeid( *(items[i]) ) == typeid(Shark) ) {
            Shark *shark = (Shark *)items[i];
            // splat sound effect

            shark->stun();

            scene()->removeItem(this);
            timer->stop();
            disconnect( timer, SIGNAL(timeout()), this, SLOT(move()) );
            // deallocate
            //delete this;
        }
    }



    // update position
    setPos( x()+vel.x, y()+vel.y );

}

// 0 for left, 1 for right
void Banana::chuck(int direction) {
    thrown = true;

    if(direction == LEFT) 
        vel.x = -vel.x;
    
    // connect to new method
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );
    timer->start(UPDATE_MS);
    
//    return thrown;
}

void Banana::pickup() {
    picked_up = true;

    // disconnect timer from method
    timer->stop();
    disconnect( timer, SIGNAL(timeout()), this, SLOT(status()) );

}

void Banana::eat() {

}

