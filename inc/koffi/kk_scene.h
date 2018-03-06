#ifndef SCENE_H
#define SCENE_H

#endif // SCENE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QString>

class Scene
{
public:
    void GameScene();
//    virtual void loadScene();
    virtual void addGameObject(QGraphicsItem* gameObject, QString imagePath, int scaledWidth, int scaledHeight) = 0;
    virtual void addGameObject(QGraphicsItem* gameObject) = 0;
    virtual void removeGameObject(QGraphicsItem* gameObject) = 0;
protected:
//    virtual void generateLevel();
};
