#include "../../inc/wei/graphics.h"
#include "../../inc/gigiyoung/gy_object.h"


/*void Graphics::load_main_player(Main_player *player)
{
    player->setPixmap(QPixmap(":/Object_image/monkey.png"));

}

void Graphics::load_shark(Shark *shark)
{
    shark->setPixmap(QPixmap(":/Object_image/blue_shark.png"));

}*/
void Graphics::load_shark(Shark *shark)
{
    shark->setPixmap(QPixmap(":/images/blue_shark.png"));
    /*QPixmap pixmap(":/steam.png");
    pixmap = pixmap.scaled(width,heigh,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    shark->setPixmap(pixmap);
     */

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
Graphics::Graphics()
{
    //
}

/*
 void Graphics::load_banana(Banana *banana)
{
    banana->setPixmap(QPixmap(":/Object_image/banana.png"));

}

void Graphics::load_platform(Platform *platform)
{
   // Platform->setPixmap(QPixmap(":/Object_image/platform.png"));

}

void Graphics::load_steam(Steam *steam)
{
    // steam->setPixmap(QPixmap(":/Object_image/steam.png"));
}
*/
