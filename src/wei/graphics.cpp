#include "graphics.h"

void Graphics::LoadMainPlayer(Main_player *player)
{
    player->setPixmap(QPixmap(":/Object_image/monkey.png"));

}

void Graphics::LoadShark(Shark *shark)
{
    shark->setPixmap(QPixmap(":/Object_image/blue_shark.png"));

}

void Graphics::LoadBanana(Banana *banana)
{
    banana->setPixmap(QPixmap(":/Object_image/banana.png"));

}
Platform
void Graphics::LoadPlatform(Platform *Platform)
{
   // Platform->setPixmap(QPixmap(":/Object_image/platform.png"));

}

void Graphics::LoadSteam(Steam *steam)
{
    // steam->setPixmap(QPixmap(":/Object_image/steam.png"));
}
