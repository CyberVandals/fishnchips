#include <QEvent>
#include <QKeyEvent>
#include <QObject>
#include <QCoreApplication>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

#include "../../inc/gy_autotest.h"
#include "../../inc/gy_object.h"
#include "../../inc/hh_main_player.h"

class Main_player;

// add main player
//AutoTest::AutoTest(QObject *main_window, QGraphicsItem *object): 
AutoTest::AutoTest(QGraphicsScene *scene, QGraphicsItem *object): 
    QObject() 
{
    // init 
    this->object = object; 
    receiver = scene;
    timer = new QTimer(this);

    list_pos = 0;
    dest = QPoint(-1,-1);

    // add test points
    add_point(QPoint(500,0));
    add_point(QPoint(500,500));
    add_point(QPoint(0,500));

    // if no player object passed, then create a demo level
    if(object == 0)
        create_demo();

    connect(timer, SIGNAL(timeout()), this, SLOT(simulate_keypress()));
    timer->start(200);
}

bool AutoTest::change_scene(QGraphicsScene *scene) {
    if( scene != NULL ) {
        receiver = scene;
        return true;
    }
    return false;
}

void AutoTest::create_demo() {
    Main_player *player;
    Shark *shark1, *shark2, *shark3, *shark4, *shark5;
    Platform *plat1, *plat2, plat3;
    Banana *bana1;
    Steam *steam1;
    Exit *exit;

    player = new Main_player(receiver);
 
    shark1 = new Shark();

}

void AutoTest::restart_scene() {
    clear_scene();
    create_demo();
}

void AutoTest::clear_scene() {

}


void AutoTest::add_point(QPoint point) {
    points.append(point);
}

/*
void AutoTest::add_path(QList<QPoint> points) {
    QPoint *ptr = points;

    while( *ptr != NULL ) {
        this->points.append(*ptr++);
    }

    if( this->points == NULL ) {
        this->points = new <QPoint>QList();
    }
    (this->points)->append( (const QList<QPoint> *) points);
}
*/


void AutoTest::simulate_keypress() {
    //QKeyEvent key_event;
    int x = object->x();
    int y = object->y();

    //qDebug() << "simulate_keypress()";

    // init if self.points isn't empty
    if( (dest.x() == -1 && dest.y() == -1) && points.size() > 0 )
        dest = (points.at(list_pos));

    // wrap-around list if index is beyond array
    //if( list_pos >= points.size() )
    //    list_pos = 0;

    // move towards dest

    // left or right
    if( x != dest.x() ) {
        if( x < dest.x() ) {
            //object->setPos(x+10, y);
            QKeyEvent event(QEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);
            QCoreApplication::sendEvent(receiver, &event);
        }
        else if( x > dest.x() ) {
            //object->setPos(x-10, y);
            QKeyEvent event(QEvent::KeyPress, Qt::Key_Left, Qt::NoModifier);
            QCoreApplication::sendEvent(receiver, &event);
        }
    }

   // up or down
    if( y != dest.y() ) {
        if( y < dest.y() ) {
            //object->setPos(x, y+10);
            QKeyEvent event(QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);
            QCoreApplication::sendEvent(receiver, &event);
        }
        else if( y > dest.y() ) {
            //object->setPos(x, y-10);
            QKeyEvent event(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
            QCoreApplication::sendEvent(receiver, &event);
        }
            
    }
        
    if( (x < dest.x()+5 && x > dest.x()-5) && 
        (y < dest.y()+5 && y > dest.y()-5) &&
        list_pos < points.size()-1 )
    {
        list_pos++;
        dest = points.at(list_pos);
    }

   
     
    // testing, just use up key
    //QKeyEvent event(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
    //QCoreApplication::sendEvent(receiver, &event);
    //QCoreApplication::sendEvent(scene(), &event);
}

