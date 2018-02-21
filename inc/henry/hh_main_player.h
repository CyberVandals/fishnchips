#ifndef HH_MAIN_PLAYER_H
#define HH_MAIN_PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QWidget>

class hh_main_player
{
private:
    float x_pos, y_pos;

public:
    hh_main_player();
    void keyPressEvent(QKeyEvent * event);
};

#endif // HH_MAIN_PLAYER_H
