#ifndef GAMESCENE_H
#define GAMESCENE_H

#endif // GAMESCENE_H

#include <QGraphicsScene>
#include <QString>

#include "kk_scene.h"

class GameScene: public Scene
{
public:
    GameScene(QGraphicsScene *scene);
    void addGameObject(QGraphicsItem* gameObject, QString imagePath, int scaledWidth, int scaledHeight) override;
    void addGameObject(QGraphicsItem* gameObject) override;
    void removeGameObject(QGraphicsItem* gameObject) override;
    void setBackground(QString imagePath);
    void setFocus(QGraphicsItem* gameObject);
private:
    QGraphicsScene *gameScene;
};
