/******************************* 
 * gy_banana.cpp 
 * 
 * By Gigi Young
 ******************************/

#include <QList>
#include <QPointF>
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

    is_thrown = false;
    is_picked_up = false;

    vel.x = 0;
    vel.y = 0;

    timer = new QTimer(this);
    graphics = new Graphics();
//    graphics = new LoadBanana();
    sound = new SoundManager();

//    graphics->set_width(DEFAULT_BANANA_WIDTH);
//    graphics->set_high(DEFAULT_BANANA_HEIGHT);
//    graphics->load_banana(this);

    graphics->load_banana(
        DEFAULT_BANANA_WIDTH, DEFAULT_BANANA_HEIGHT, this);

    connect(timer, SIGNAL(timeout()), this, SLOT(status()));
}

void Banana::pause() {
    if( timer != NULL )
        timer->stop();
}

void Banana::resume() {
    if( timer != NULL )
        timer->start();
}

// direction - LEFT, RIGHT, UP, DOWN 
void Banana::chuck(int direction) {
    QPointF scene_coord;


    // if banana has player as a parent, throw
    if( parentItem() != NULL ) {
        is_picked_up = false;
        is_thrown = true;

        if( direction == LEFT ) 
            vel.x = -10;
        else if( direction == RIGHT ) 
            vel.x = 10;
        else if( direction == UP ) 
            vel.y = -10;
        else if( direction == DOWN ) 
            vel.y = 10;

//        qDebug() << "throw banana";
        scene_coord = mapToScene(pos());
       
        // become an orphan
        setParentItem(0);
        setPos(scene_coord);

        sound->play_throw();
    
        // connect to new method
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));
        timer->start(UPDATE_MS);
    }
    else if( parentItem() == NULL ) {
//        qDebug() << "banana has no parent";
    }
}


void Banana::eat() {
    if( is_picked_up ) {
        is_picked_up = false;

        // become an orphan
        setParentItem(0);
        setVisible(false);
    }
}

bool Banana::thrown() {
    return is_thrown;
}

void Banana::set_thrown(bool is_thrown) {
    this->is_thrown = is_thrown;
}


void Banana::status() {
    QList<QGraphicsItem *> items = 
        collidingItems(Qt::IntersectsItemShape);

    for( int i = 0; i < items.size() ; i++ ) {
        // player picked up banana 
        if( typeid(*(items[i])) == typeid(MainPlayer) ) {
            if( items[i]->childItems().isEmpty() ) {

                sound->play_pickup();

                // make player parent of banana
                setParentItem(items[i]); 
                // sets banana position relative to parent's coord system
                setPos(0,0);
                is_picked_up = true;

                // disconnect timer from method
                timer->stop();
                disconnect(timer,SIGNAL(timeout()),this,SLOT(status()));

            }
        }
    }
}


void Banana::move() {
    int scene_right = scene()->sceneRect().right();
    int scene_left = scene()->sceneRect().left();
    int scene_top = scene()->sceneRect().top();
    int scene_bottom = scene()->sceneRect().bottom();
    int b_right = x() + this->boundingRect().width();
    int b_left = x();
    int b_top = y();
    int b_bottom = y() + this->boundingRect().height();

    QList<QGraphicsItem *> items = 
        collidingItems(Qt::IntersectsItemShape);

    // move banana
    setPos(x()+vel.x, y()+vel.y);

    // check collisions
    for( int i = 0; i < items.size(); i++ ) {

        // if collision with platform, make banana invisible 
        if( typeid(*(items[i])) == typeid(Platform) ) {
            // splat sound effect
            sound->play_hit();

            setVisible(false);

            timer->stop();
            disconnect(timer, SIGNAL(timeout()), this, SLOT(move()));
        }

        // if collision with shark, make banana invisible and set shark
        // paralysis timer 
        else if( typeid(*(items[i])) == typeid(Shark) ) {
            Shark *shark = (Shark *)items[i];
            // splat sound effect
            sound->play_hit();

            shark->stun();

            setVisible(false);

            timer->stop();
            disconnect(timer, SIGNAL(timeout()), this, SLOT(move()));

        }
    }

    // if banana moves out of bounds, make it invisible
    if( b_left <= scene_left || b_right >= scene_right 
        || b_top <= scene_top || b_bottom >= scene_bottom )
    {
        setVisible(false);
        timer->stop();
        disconnect(timer,SIGNAL(timeout()),this,SLOT(move()));
    } 

}

