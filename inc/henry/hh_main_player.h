#ifndef HH_MAIN_PLAYER_H
#define HH_MAIN_PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QWidget>
#include <QObject>
#include <QGraphicsRectItem>

class Main_player: public QObject, public QGraphicsRectItem
{
Q_OBJECT
private:


public:
    Main_player();
    void keyPressEvent(QKeyEvent * event);
};

#endif // HH_MAIN_PLAYER_H
