#include "../../inc/wz_graphics.h"
#include "../../inc/gy_object.h"

/*Graphics::Graphics()
{
//
}

void Graphics::load_mainplayer(MainPlayer *main_player){
    main_player->setPixmap(QPixmap(":/images/monkey.png"));
}

void Graphics::load_mainplayer(int width, int heigh, MainPlayer *main_player, bool left_, bool right_){
    //QPixmap pixmap(":/images/monkey.png");
    //pixmap = pixmap.scaled(width,heigh,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    //main_player->setPixmap(pixmap);
    QPixmap pixmap;
    if (right_){
        pixmap.load(":/images/monkey.png");
    }
    else if(left_){
        pixmap.load(":/images/monkey_left.png");
    }
    pixmap = pixmap.scaled(width,heigh,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    main_player->setPixmap(pixmap);
}

void Graphics::load_shark(Shark *shark){
    shark->setPixmap(QPixmap(":/images/blue_shark.png"));

}

void Graphics::load_shark(int width,int heigh,Shark *shark, bool left_, bool right_){
    //shark->setPixmap(QPixmap(":/blue_shark.png"));
    QPixmap pixmap;
    if (right_){
        pixmap.load(":/images/blue_shark.png");
    }
    else if(left_){
        pixmap.load(":/images/blue_shark_left.png");
    }
    pixmap = pixmap.scaled(width,heigh,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    shark->setPixmap(pixmap);

}
*/
/*void Graphics :: shark_flip(Shark *shark, bool horizontal , bool vertical)
{
QImage image(":/images/blue_shark.png");
QImage mirroredImage = image.mirrored(horizontal, vertical);
QPixmap pixmap = QPixmap::fromImage(mirroredImage);
shark->setPixmap(pixmap);
}
*/
/*
void Graphics::load_banana(Banana *banana){
    banana->setPixmap(QPixmap(":/images/banana.png"));
}

void Graphics:: load_banana(int width,int heigh,Banana *banana){
    QPixmap pixmap(":/images/banana.png");
    pixmap = pixmap.scaled(width,heigh,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    banana->setPixmap(pixmap);
}

void Graphics::load_platform(Platform *platform){
    platform->setPixmap(QPixmap(":/images/platform_.png"));
}


void Graphics:: load_platform(int width,int heigh,Platform *platform){
    QPixmap pixmap(":/images/platform_.png");
    pixmap = pixmap.scaled(width,heigh,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    platform->setPixmap(pixmap);

}

void Graphics::load_steam(Steam *steam){
    steam->setPixmap(QPixmap(":/images/steam_.png"));
}


void Graphics:: load_steam(int width,int heigh,Steam *steam){
    QPixmap pixmap(":/images/steam_.png");
    pixmap = pixmap.scaled(width,heigh,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    steam->setPixmap(pixmap);
}

void Graphics::load_exit_door(Exit *exit_door){
    exit_door->setPixmap(QPixmap(":/images/door.png"));
}

void Graphics::load_exit_door(int width, int heigh, Exit *exit_door){
    QPixmap pixmap(":/images/door.png");
    pixmap = pixmap.scaled(width,heigh,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    exit_door->setPixmap(pixmap);
}

*/
void LoadMainPlayer::load_main_player(MainPlayer *main_player)
{
    QPixmap pixmap;
    if (!PathName::left){
        pixmap.load(PathName::monkey_path);
    }
    else if(PathName::left){
        pixmap.load(PathName::left_monkey_path);
    }
    pixmap = pixmap.scaled(PathName::width,PathName::high,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    main_player->setPixmap(pixmap);
}

void LoadShark::load_shark(Shark *shark)
{
    QPixmap pixmap;
    if (!PathName::left){
        pixmap.load(PathName::shark_path);
    }
    else if(PathName::left){
        pixmap.load(PathName::left_shark_path);
    }
    pixmap = pixmap.scaled(PathName::width,PathName::high,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    shark->setPixmap(pixmap);
}


void LoadSteam::load_steam(Steam *steam)
{
    QPixmap pixmap(path->steam_path);
    pixmap = pixmap.scaled(path->width,path->high,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    steam->setPixmap(pixmap);
}

void LoadBanana::load_banana(Banana *banana)
{
    QPixmap pixmap(banana_path);
    pixmap = pixmap.scaled(width,high,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    banana->setPixmap(pixmap);
}


void LoadExit::load_exit(Exit *exit_door)
{
    QPixmap pixmap(exit_path);
    pixmap = pixmap.scaled(width,high,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    exit_door->setPixmap(pixmap);
}

void LoadPlatform::load_platform(Platform *plat)
{
    QPixmap pixmap(platform_path);
    pixmap = pixmap.scaled(width,high,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    plat->setPixmap(pixmap);

}
