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
#include "gy_object.h"
#include "kk_scenemanager.h"


class LoadMainPlayer;
class Banana;
class Graphics;

class MainPlayer: public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
private:
Banana * banana;
HealthBar *player_health;
Oxygen *player_oxygen;
QList<QGraphicsItem *> collision_item;
QTimer * recover_timer;
QTimer * timer;
//Graphics * player_pic;
QGraphicsScene * player_scene;
SceneManager * scene_manager;
bool left_collision;
bool right_collision;
bool top_collision;
bool bottom_collision;
bool sink_collision;
bool shield;
bool has_banana;


//Health health;

public:
    MainPlayer(QGraphicsScene *scene, QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent * event);
    int shark_collision();
    bool platform_collision();

public slots:
    void sink();
    void recover();
};

#endif // HH_MAIN_PLAYER_H
