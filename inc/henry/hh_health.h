#ifndef HH_HEALTH_H
#define HH_HEALTH_H

#include <QGraphicsRectItem>

class Health: public QGraphicsRectItem
{
private:
    int height, width;
    int x_pos, y_pos;
    int ID;
    //Health * next;
public:
    Health(int x, int y, int id, QGraphicsRectItem * parent = 0);




};

#endif // HH_HEALTH_H
