#ifndef HH_HEALTH_BAR_H
#define HH_HEALTH_BAR_H
#include <QGraphicsRectItem>
#include <QList>
#include <QLinkedList>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "henry/hh_health.h"
//composite pattern

class HealthBar: public QGraphicsRectItem //lineup of Health objects
{
public:
    void add_health(QGraphicsScene *scene); //health management, delete one of the instances of "Health"
    int decrease_health();
    void renew_health();
    HealthBar(QGraphicsScene *);
private://delegation
QLinkedList<Health *> health_list; //health bar is implemented as a linked list for easy management

};

#endif // HH_HEALTH_BAR_H
