/*********************************
 * gy_autotest.cpp
 *
 * Gigi Young
 ********************************/


#include <QEvent>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QDebug>
#include <QList>

#include "../../inc/gy_autotest.h"
#include "../../inc/gy_objecthandler.h"
#include "../../inc/gy_object.h"
#include "../../inc/hh_main_player.h"
#include "../../inc/kk_scenemanager.h"

AutoTest::AutoTest(QGraphicsScene *scene, SceneManager *sm, 
    QGraphicsItem *object): QObject() 
{
    // init 
    this->object = object; 
    this->scene = scene;
    this->scene_manager = sm;
    timer = new QTimer(this);
    obj_handler = new ObjectHandler(scene);

    list_pos = 0;
    dest = QPoint(-1,-1);

    // add test points
    add_point(QPoint(800,600));
    add_point(QPoint(800,410));
    add_point(QPoint(400,410));
    add_point(QPoint(400,310));
    add_point(QPoint(700,310));
    add_point(QPoint(700,80));
    add_point(QPoint(70,80));
    add_point(QPoint(800,600));


    // if no player object passed, then create a demo level
    if(object == 0 && sm == 0)
        create_stress_level();

    else {
        connect(timer, SIGNAL(timeout()), this, SLOT(simulate_keypress()));
        timer->start(75);
    }
}

bool AutoTest::change_scene(QGraphicsScene *scene) {
    if( scene != NULL ) {
        this->scene = scene;
        return true;
    }
    return false;
}

void AutoTest::create_stress_level() {
    //static MainPlayer *player;

    player = new MainPlayer(scene,sm);
    scene->addItem(player);
    scene->setFocusItem(player);

    obj_handler->add_shark(30,30,5,5);
    obj_handler->add_shark(30,30,6,4);
    obj_handler->add_shark(30,30,7,3);
    obj_handler->add_shark(50,30,11,0);
    obj_handler->add_shark(50,30,8,-2);
    obj_handler->add_shark(50,30,9,-1);
    obj_handler->add_shark(50,30,10,1);
    obj_handler->add_shark(100,30,4,7);
    obj_handler->add_shark(100,30,3,6);
    obj_handler->add_shark(100,30,2,7);
    obj_handler->add_shark(100,500,10,0);
    obj_handler->add_shark(300,30,10,1);
    obj_handler->add_shark(300,30,11,0);
    obj_handler->add_shark(300,30,10,0);
    obj_handler->add_shark(300,30,8,3);
    obj_handler->add_shark(300,30,10,3);
    obj_handler->add_shark(500,300,4,6);
    obj_handler->add_shark(500,300,6,6);
    obj_handler->add_shark(500,300,5,6);
    obj_handler->add_shark(500,300,8,6);
    obj_handler->add_shark(500,300,8,4);
    obj_handler->add_shark(600,100,10,4);
    obj_handler->add_shark(600,100,9,3);
    obj_handler->add_shark(600,300,8,4);
    obj_handler->add_shark(600,300,9,5);
    obj_handler->add_shark(600,300,10,5);
    obj_handler->add_shark(600,300,2,10);

    obj_handler->add_platform(0,150,600);
    obj_handler->add_platform(200,300,1000);
    obj_handler->add_platform(0,450,600);
    obj_handler->add_platform(0,600,500);
    obj_handler->add_platform(650,600,600);

    obj_handler->add_banana(100,200);
    obj_handler->add_banana(100,350);
    obj_handler->add_banana(100,500);
    obj_handler->add_banana(100,650);
    obj_handler->add_banana(200,200);
    obj_handler->add_banana(200,350);
    obj_handler->add_banana(200,500);
    obj_handler->add_banana(200,650);
    obj_handler->add_banana(300,200);
    obj_handler->add_banana(300,350);
    obj_handler->add_banana(300,500);
    obj_handler->add_banana(300,650);
    obj_handler->add_banana(400,200);
    obj_handler->add_banana(400,350);
    obj_handler->add_banana(400,500);
    obj_handler->add_banana(400,650);
    obj_handler->add_banana(500,200);
    obj_handler->add_banana(500,350);
    obj_handler->add_banana(500,500);
    obj_handler->add_banana(500,650);
    obj_handler->add_banana(600,200);
    obj_handler->add_banana(600,350);
    obj_handler->add_banana(600,500);
    obj_handler->add_banana(600,650);


    obj_handler->add_steam(500, 200);
    obj_handler->add_steam(300, 100);
    obj_handler->add_steam(600, 600);

    obj_handler->add_exit();

}

void AutoTest::restart_scene() {
    clear_scene();
    create_stress_level();
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
    QList<QGraphicsItem *> items = object->collidingItems(
                                       Qt::IntersectsItemShape);
    int x = object->x();
    int y = object->y();
    

    // init if self.points isn't empty
    if( (dest.x() == -1 && dest.y() == -1) && points.size() > 0 )
        dest = (points.at(list_pos));

    // wrap-around list if index is beyond array
    if( list_pos >= points.size() )
        list_pos = 0;

    // check for banana
    if( object->childItems().size() > 0 ) {
        QKeyEvent event(QEvent::KeyPress, Qt::Key_E, Qt::NoModifier);
        QCoreApplication::sendEvent(scene, &event);
    } 
    // check for exit
    for( int i = 0; i < items.size(); i++ ) {
        if( typeid(*(items[i])) == typeid(Exit) ) {
            if( list_pos < points.size() - 1 )
                list_pos++;
            else
                list_pos = 0;
            dest = points.at(list_pos);
 
        }
    }

    // move towards dest
    // left or right
    if( x != dest.x() ) {
        if( x < dest.x()-5 ) {
            //object->setPos(x+10, y);
            QKeyEvent event(QEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);
            QCoreApplication::sendEvent(scene, &event);
        }
        else if( x > dest.x()+5 ) {
            //object->setPos(x-10, y);
            QKeyEvent event(QEvent::KeyPress, Qt::Key_Left, Qt::NoModifier);
            QCoreApplication::sendEvent(scene, &event);
        }
    }

   // up or down
    if( y != dest.y() ) {
        if( y < dest.y()-5 ) {
            //object->setPos(x, y+10);
            QKeyEvent event(QEvent::KeyPress, Qt::Key_Down, Qt::NoModifier);
            QCoreApplication::sendEvent(scene, &event);
        }
        else if( y > dest.y()+5 ) {
            //object->setPos(x, y-10);
            QKeyEvent event(QEvent::KeyPress, Qt::Key_Up, Qt::NoModifier);
            QCoreApplication::sendEvent(scene, &event);
        }
            
    }
        
    if( (x < dest.x()+10 && x > dest.x()-10) && 
        (y < dest.y()+10 && y > dest.y()-10) &&
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

