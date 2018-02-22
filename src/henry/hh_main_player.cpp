#include "../../inc/henry/hh_main_player.h"

hh_main_player::hh_main_player()
{

}

void hh_main_player::keyPressEvent(QKeyEvent *event)
{
    if( event->key() == Qt::Key_Left)
    {
     //move left
    }
else if( event->key() == Qt::Key_Right)
    {
     //move right
    }
else if( event->key() == Qt::Key_Up)
    {
//move up
    }
else if( event->key() == Qt::Key_Down)
    {
    //move down
    }
}
