#include "../../inc/henry/hh_main_player.h"

Main_player::Main_player()
{
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    setRect(width/2 + 25, height, 50, 50);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();


}

void Main_player::keyPressEvent(QKeyEvent *event)
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
