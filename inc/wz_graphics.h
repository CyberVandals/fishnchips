/********************************
  *Graphics.h                        
  *Wei Zhao              
********************************/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QGraphicsPixmapItem>
#include "hh_main_player.h"
#include "gy_object.h"
#include <QGraphicsPathItem>

class Shark;
class Banana;
class Platform;
class Steam;
class MainPlayer;
class Exit;
class Graphics : public QGraphicsPathItem {
public:
    //void load_mainPlayer(Main_player *player);
    Graphics();
    void load_mainplayer(MainPlayer *main_player);
    void load_mainplayer(int width,int heigh,MainPlayer *main_player, bool left_, bool right_);
    void load_mainplayer();
    void load_shark (int width,int heigh,Shark *shark, bool left, bool righ);
    void load_shark (Shark *shark);
    //void shark_flip(Shark *shark, bool horizontal, bool vertical);
    void load_banana(Banana *banana);
    void load_banana(int width,int heigh,Banana *banana);
    void load_platform(Platform *platform);
    void load_platform(int width,int heigh,Platform *platform);
    void load_steam(Steam *steam);
    void load_steam(int width,int heigh,Steam *steam);
    void load_exit_door(Exit *exit_door);
    void load_exit_door(int width,int heigh,Exit *exit_door);
private:
};


// save all path for all graphics
// values and functions could be resued as supperclass
class PathName {
public:
    //this is for main player defult
    PathName(): left(false), width(50), high(50){}
    QString platform_path=":/images/platform_.png";
    QString shark_path = ":/images/blue_shark.png";
    QString red_shark = ":/images/red_shark.png";
    QString left_red_shark = ":/images/left_red_shark.png";
    QString left_shark_path = ":/images/blue_shark_left.png";
    QString monkey_path = ":/images/monkey.png";
    QString left_monkey_path = ":/images/monkey_left.png";
    QString exit_path = ":/images/door.png";
    QString banana_path = ":/images/banana.png";
    QString steam_path = ":/images/steam_.png";
    void set_direction(bool dire){
        left = dire;
    }
    void set_width(int width_){
        width = width_;
    }
    void set_high(int high_){
        high = high_;
    }
    bool left;
    int width;
    int high;
};

// load main player graphics
// this is a sigleton class, and could be new only once
// could make it as global and could be call anywhere
class LoadMainPlayer: public PathName{
private:
    LoadMainPlayer(){}
    static LoadMainPlayer * instance;
public:
    static LoadMainPlayer *get_instance(){
        if(instance == NULL){
            instance = new LoadMainPlayer();
        }
        return instance;
    }
    void load_main_player(MainPlayer *main_player);
};
/*
// this is a abstract class as a interface of decorator class
class PathName;
class InterShark{
private :
public:
    virtual void load_shark(Shark *shark)=0;
};
// this is a base class
class LoadShark: public PathName, public InterShark{
public:
    LoadShark(){
        PathName::high = 100;
        PathName::width = 150;
        PathName::left = false;
    }
    virtual void load_shark(Shark *shark);
    //void load_shark(Shark *shark);
};

// this is a decorator calss
class SharkDecorator:public InterShark,public PathName{
protected:
    InterShark &s_decorator;
    PathName &path;
public:
    SharkDecorator(InterShark & decorator, PathName path_)
        :s_decorator(decorator),path(path_){

    }
    virtual void load_shark(Shark *shark){

        s_decorator.load_shark(shark);
    }

};

// specific actions or changes
class LoadRedShark:public SharkDecorator{
public:
    LoadRedShark(InterShark & decorator, PathName &path_)
        :SharkDecorator(decorator,path_){

    }
    virtual void load_shark(Shark *shark){
        path.shark_path= path.red_shark;
        path.left_shark_path=path.left_red_shark;
        s_decorator.load_shark(shark);
    }
};

class LoadBanana:public PathName{
public:
    LoadBanana()
    {
        PathName::high = 100;
        PathName::width = 150;
    }
    void load_banana(Banana *banana);

};

class LoadPlatform:public PathName{
public:
    LoadPlatform(){
        high=10;
        width=500;
    }
    void load_platform(Platform *plat);
};

class LoadExit : public PathName{
public:
    LoadExit(){
        high=100;
        width=75;
    }
    void load_exit(Exit *exit);
};

//this is a example of using delegation
class LoadSteam{
private:
    PathName *path=new PathName();
public:
    LoadSteam(){
        path->high=100;
        path->width=100;
    }
    void set(int high_,int width_){
        path->high=high_;
        path->width=width_;
    }
    void load_steam(Steam *steam);
};
*/
#endif // GRAPHICS_H
