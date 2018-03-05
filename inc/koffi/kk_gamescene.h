#ifndef GAMESCENE_H
#define GAMESCENE_H

#endif // GAMESCENE_H

#include <QGraphicsScene>

#include "kk_scene.h"
#include "kk_gamescene.h"

class GameScene: public Scene,
{
public:
    GameScene(QGraphicsScene *scene);
    void addGameObject(QGraphicsItem* gameObject, QPixmap imagePath, int scaledWidth, int scaledWidth);
    void removeGameObject(QGraphicsItem* gameObject);
private:
    QGraphicsScene *gameScene;
};
