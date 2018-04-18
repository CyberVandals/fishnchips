#ifndef LEVELITEM_H
#define LEVELITEM_H

#endif // LEVELITEM_H


#include "gy_object.h"

#include <QString>

class ObjectHandler;

class LevelItem {
public:
    LevelItem();
    void setPosition(int x, int y);
    void setTitle(QString title);
    int x();
    int y();
    QString title();

private:
    int x_pos, y_pos;
    QString _title;
};
