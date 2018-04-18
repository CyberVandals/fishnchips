#include "inc/koffi/kk_levelitem.h"

LevelItem::LevelItem()
{

}

void LevelItem::setPosition(int x, int y)
{
    x_pos = x;
    y_pos = y;
}

void LevelItem::setTitle(QString title)
{
    _title = title;
}

int LevelItem::x()
{
    return x_pos;
}

int LevelItem::y()
{
    return y_pos;
}

QString LevelItem::title()
{
    return _title;
}
