#ifndef AUTOTEST_H
#define AUTOTEST_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QPoint>
#include <QList>

class AutoTest: public QObject {
    Q_OBJECT

public:
    AutoTest(QGraphicsScene *scene, QGraphicsItem *object=0); 
    bool change_scene(QGraphicsScene *scene);
    void create_demo();
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
    QGraphicsScene *receiver;

};


#endif /* AUTOTEST_H */
