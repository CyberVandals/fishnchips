#include <QEvent>
#include <QKeyEvent>
#include <QObject>
#include <QCoreApplication>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include "../../inc/gy_autotest.h"

// add main player
//AutoTest::AutoTest(QObject *main_window, QGraphicsItem *object): 
AutoTest::AutoTest(QGraphicsScene *main_window, QGraphicsItem *object): 
    QObject() 
{
    list_pos = 0;
    dest = QPoint(-1,-1);

    this->object = object; 
    receiver = main_window;
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(simulate_key()));
    timer->start(50);
}

bool AutoTest::change_scene(QObject *main_window) {
    if( main_window != NULL ) {
        receiver = main_window;
        return true;
    }
    return false;
}

void AutoTest::add_point(QPoint point) {
    points.append(point);
/*
    if( points == NULL ) {
        points = new <QPoint>QList();
    }
    points->append(p);
*/
}

void AutoTest::add_path(QList<QPoint> points) {
    points.append(points);
/*
    if( this->points == NULL ) {
        this->points = new <QPoint>QList();
    }
    (this->points)->append( (const QList<QPoint> *) points);
*/
}


void AutoTest::simulate_keypress() {
    int x = object->x();
    int y = object->y();

    // init if self.points isn't empty
    if( (dest.x() == -1 && dest.y() == -1) && points.size() > 0 )
        dest == (points.at(list_pos));

    // wrap-around list if index is beyond array
    //if( list_pos >= points.size() )
    //    list_pos = 0;

    // move towards dest

    // up or down
    if( y != dest.y() ) {
        if( y < dest.y() )
            object->setPos(x, y+10);
        else if( y > dest.y() )
            object->setPos(x, y-10);
            
    }
        
    // left or right
    if( x != dest.x() ) {
        if( x < dest.x() )
            object->setPos(x+10, y);
        else if( x > dest.x() )
            object->setPos(x-10, y);
    }

   
     
    // testing, just use up key
    QKeyEvent event(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
    QCoreApplication::sendEvent(receiver, &event);
    //QCoreApplication::sendEvent(scene(), &event);
}

