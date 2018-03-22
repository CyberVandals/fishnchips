#include "../../inc/wz_graphics.h"
#include "../../inc/gy_object.h"

Graphics::Graphics()
{
    //
}

void Graphics::load_mainplayer(Main_player *main_player)
{
    main_player->setPixmap(QPixmap(":/images/monkey.png"));
}

void Graphics::load_mainplayer(int width, int heigh, Main_player *main_player)
{
    QPixmap pixmap(":/images/monkey.png");
    pixmap = pixmap.scaled(width,heigh,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    main_player->setPixmap(pixmap);

}

void Graphics::load_shark(Shark *shark)
{
    shark->setPixmap(QPixmap(":/images/blue_shark.png"));

}



void Graphics::load_shark(int width,int heigh,Shark *shark)
{
    //shark->setPixmap(QPixmap(":/blue_shark.png"));
    QPixmap pixmap(":/images/blue_shark.png");
    pixmap = pixmap.scaled(width,heigh,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    shark->setPixmap(pixmap);
    
}
void Graphics::load_banana(Banana *banana)
{
     banana->setPixmap(QPixmap(":/images/banana.png"));
}

void Graphics:: load_banana(int width,int heigh,Banana *banana)
{
    QPixmap pixmap(":/images/banana.png");
    pixmap = pixmap.scaled(width,heigh,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    banana->setPixmap(pixmap);
}

void Graphics::load_platform(Platform *platform)
{
    platform->setPixmap(QPixmap(":/images/platform_.png"));
}


void Graphics:: load_platform(int width,int heigh,Platform *platform)
{
    QPixmap pixmap(":/images/platform_.png");
    pixmap = pixmap.scaled(width,heigh,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    platform->setPixmap(pixmap);
    
}

void Graphics::load_steam(Steam *steam)
{
    steam->setPixmap(QPixmap(":/images/steam_.png"));
}


void Graphics:: load_steam(int width,int heigh,Steam *steam)
{
    QPixmap pixmap(":/images/steam_.png");
    pixmap = pixmap.scaled(width,heigh,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    steam->setPixmap(pixmap);
}

void Graphics::load_exit_door(Exit *exit_door)
{
     exit_door->setPixmap(QPixmap(":/images/door.png"));
}

void Graphics::load_exit_door(int width, int heigh, Exit *exit_door)
{
    QPixmap pixmap(":/images/door.png");
    pixmap = pixmap.scaled(width,heigh,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    exit_door->setPixmap(pixmap);
}
