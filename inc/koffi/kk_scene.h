#ifndef SCENE_H
#define SCENE_H

#endif // SCENE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPixmap>

class Scene
{
public:
    void GameScene();
    virtual void loadScene();
    virtual void addGameObject(QGraphicsItem* gameObject, QPixmap imagePath, int scaledWidth, int scaledHeight);
    virtual void removeGameObject(QGraphicsItem* gameObject);
protected:
    virtual void generateLevel();
};
