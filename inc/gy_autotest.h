/*********************************
 * gy_autotest.h
 *
 * By Gigi Young
 ********************************/

#ifndef AUTOTEST_H
#define AUTOTEST_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QPoint>
#include <QList>
#include <QGraphicsView>

//#include "kk_scenemanager.h"

class ObjectHandler;
class SceneManager;

class AutoTest: public QObject {
    Q_OBJECT

public:
    //AutoTest(QGraphicsScene *scene, SceneManager *sm=0, QGraphicsItem *object=0); 
    AutoTest(QGraphicsScene *scene, QGraphicsItem *object=0, SceneManager *sm=0); 
    bool change_scene(QGraphicsScene *scene);
    void create_stress_level();
    void restart_scene();
    void clear_scene();
    void add_point(QPoint point);
//    void add_path(QPoint* points);

public slots:
    void simulate_keypress();

private:
    int list_pos;
    QPoint dest;
    QList<QPoint> points;
 
    QGraphicsItem *object;
    QTimer *timer;
    //QObject *receiver;
    QGraphicsScene *scene;
    ObjectHandler *obj_handler;

};


#endif /* AUTOTEST_H */
