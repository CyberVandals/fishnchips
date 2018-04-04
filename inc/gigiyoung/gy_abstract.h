/***********************************
 * gy_abstract.h
 *
 * By Gigi Young
 **********************************/

#ifndef GY_ABSTRACT_H
#define GY_ABSTRACT_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>

//#include "../wz_graphics.h"
//#include "../mm_soundmanager.h"

class Graphics;
class SoundManager;

class AbstractObject: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    AbstractObject(QGraphicsItem *parent = 0);
    virtual void pause() = 0;
    virtual void resume() = 0;

protected:
    virtual void init() = 0;

    QTimer *timer;
    Graphics *graphics;
    SoundManager *sound;
};

#endif /* GY_ABSTRACT_H */
