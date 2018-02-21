/* gy_exit.c - Implementation file for exit (door)
 * By Gigi Young
 */

#include "../../inc/gigiyoung/gy_object.h"

void Exit::init() {

    // create timer for move slot
    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(status()) );
    timer->start(UPDATE_MS);
}

// Default constructor 
Exit::Exit(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){

    // init size and position
    setRect( DEFAULT_POS_X, DEFAULT_POS_Y, DEFAULT_EXIT_WIDTH,
             DEFAULT_EXIT_HEIGHT );
    init();
}


// Constructor with position 
Exit::Exit(int pos_x, int pos_y,
    QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{

    // init size and position
    setRect( pos_x, pos_y, DEFAULT_EXIT_WIDTH, DEFAULT_EXIT_HEIGHT );

    init();
} 

// Constructor with position and velocity 
Exit::Exit(int width, int height, int pos_x, int pos_y,
    QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{

    // init size and position
    setRect( pos_x, pos_y, width, height );

    init();
}

void Exit::status() {

}
