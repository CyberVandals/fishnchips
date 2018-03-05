#ifndef HH_MAIN_PLAYER_H
#define HH_MAIN_PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QWidget>
#include <QObject>
#include <QGraphicsRectItem>
#include <QDesktopWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsItem>
#include <QList>
#include <typeinfo>
#include "henry/hh_health.h"
#include "henry/hh_health_bar.h"

class Main_player: public QObject, public QGraphicsRectItem
{
Q_OBJECT
private:
bool has_banana;
HealthBar *player_health;
QList<QGraphicsItem *> collision_item;

//Health health;

public:
    Main_player(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent * event);
    bool shark_collision();
public slots:
    void sink();
};

#endif // HH_MAIN_PLAYER_H
