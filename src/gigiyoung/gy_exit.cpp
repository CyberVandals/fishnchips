/* gy_exit.c - Implementation file for exit (door)
 * By Gigi Young
 */

#include "../../inc/gy_object.h"
//#include "../../inc/gigiyoung/gy_abstract.h"

/*

// Default constructor 
Exit::Exit(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //setPixmap(QPixmap(":/images/door.png"));

    //graphics->load_

    // init size and position
    setPos( DEFAULT_EXIT_POS_X, DEFAULT_EXIT_POS_Y );
    //setRect( DEFAULT_POS_X, DEFAULT_POS_Y, DEFAULT_EXIT_WIDTH,
    //         DEFAULT_EXIT_HEIGHT );
    init();
    graphics->load_exit_door(DEFAULT_EXIT_WIDTH, DEFAULT_EXIT_HEIGHT, this);
}


// Constructor with position 
Exit::Exit(int pos_x, int pos_y,
    QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    //setPixmap(QPixmap(":/images/door.png"));

    // init size and position
    setPos( pos_x, pos_y );

    init();
    graphics->load_exit_door(DEFAULT_EXIT_WIDTH, DEFAULT_EXIT_HEIGHT, this);
} 

// Constructor with position and velocity 
Exit::Exit(int width, int height, int pos_x, int pos_y,
    QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    //setPixmap(QPixmap(":/images/door.png").scaled(width,height));

    // init size and position
    //setPos( pos_x, pos_y, width, height );
    setPos( pos_x, pos_y );

    init();
    graphics->load_exit_door(width, height, this);
}
*/
Exit::Exit(QGraphicsItem *parent): AbstractObject(parent) {
    init();
    setPos(DEFAULT_EXIT_POS_X, DEFAULT_EXIT_POS_Y); 
    timer->start(UPDATE_MS);
}


Exit::Exit(int x, int y, QGraphicsItem *parent):
    AbstractObject(parent)
{
    init();
    setPos(x, y); 
    timer->start(UPDATE_MS);
}


void Exit::init() {
    timer = new QTimer(this);
    graphics = new Graphics(); 
    sound = new SoundManager();

    //setPos(x, y); 
    //graphics->load_exit_door(
    //    DEFAULT_EXIT_WIDTH, DEFAULT_EXIT_HEIGHT, this);
    graphics->load_exit_door(
        DEFAULT_EXIT_WIDTH, DEFAULT_EXIT_HEIGHT, this);

    connect( timer, SIGNAL(timeout()), this, SLOT(status()) );
 
/*
    graphics = new Graphics();
    // create timer for move slot
    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(status()) );
    timer->start(UPDATE_MS);
*/
}

void Exit::pause() {
    if(timer != NULL)
        timer->stop();
}

void Exit::resume() {
    if(timer != NULL)
        timer->start();
}

void Exit::status() {

}
