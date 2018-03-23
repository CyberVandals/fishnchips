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
#include <QGraphicsView>
#include <QList>
#include <typeinfo>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTransform>
#include "henry/hh_health.h"
#include "henry/hh_health_bar.h"
#include "wz_graphics.h"
#include "henry/hh_oxygen.h"


class Graphics;

class Main_player: public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
private:
bool has_banana;
HealthBar *player_health;
Oxygen *player_oxygen;
QList<QGraphicsItem *> collision_item;
QTimer * recover_timer;
QTimer * timer;
bool shield;
Graphics * player_pic;
QGraphicsScene * player_scene;

//Health health;

public:
    Main_player(QGraphicsScene *scene, QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent * event);
    int shark_collision();
    bool platform_collision();

public slots:
    void sink();
    void recover();
};

#endif // HH_MAIN_PLAYER_H
