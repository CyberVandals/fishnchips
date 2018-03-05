#ifndef SCENE_H
#define SCENE_H

#endif // SCENE_H

#include <QGraphicsItem>
#include <QGraphicsScene>

class Scene
{
public:
    GameScene();
    virtual void loadScene();
    void addGameObject(QGraphicsItem* gameObject);
    void removeGameObject(QGraphicsItem* gameObject);
protected:
    virtual void generateLevel();
};
