#ifndef HH_HEALTH_BAR_H
#define HH_HEALTH_BAR_H
#include <QGraphicsRectItem>
#include <QList>

#include "../../inc/henry/hh_health.h"

class HealthBar: public QGraphicsRectItem
{
public:
    void add_health();
    void decrease_health();
    void renew_health();
    HealthBar();
private:
Health * tail;

};

#endif // HH_HEALTH_BAR_H
