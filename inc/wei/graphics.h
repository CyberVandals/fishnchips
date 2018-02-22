#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QGraphicsPixmapItem>
#include "Main_player.h"
#include "gy_object.h"
class Graphics : public QMainWindow
{
    Q_OBJECT

public:
    void LoadMainPlayer(Main_player *player);
    void Graphics::LoadShark(Shark *shark);
    void Graphics::LoadBanana(Banana *banana);
    void Graphics::LoadPlatform(Platform *Platform);
};

#endif // GRAPHICS_H
