#ifndef HH_HEALTH_BAR_H
#define HH_HEALTH_BAR_H
#include <QGraphicsRectItem>
#include <QList>
#include <QLinkedList>
#include <QWidget>

#include "henry/hh_health.h"

class HealthBar: public QGraphicsRectItem
{
public:
    void add_health();
    void decrease_health();
    void renew_health();
    HealthBar();
private:
QLinkedList<Health *> health_list;

};

#endif // HH_HEALTH_BAR_H
