#include "../../inc/ck_mainwindow.h"
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QRect>
#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>


MainWindow::MainWindow(){
    scene = new QGraphicsScene(this);
    background_music = new SoundManager();

    background_music->play_background();

    //get desktop resolution
    /*
    QRect rec = QApplication::desktop()->screenGeometry();
    WID_HEI = rec.height();
    WID_WIDTH = rec.width();
    setFixedSize(WID_WIDTH/1.5, WID_HEI/1.1);
    scene->setSceneRect(0,0,WID_WIDTH/1.5,WID_HEI/1.1);
    */

    WID_HEI = 700;
    WID_WIDTH  = 950;
    setFixedSize(WID_WIDTH, WID_HEI);
    scene->setSceneRect(0,0,WID_WIDTH,WID_HEI);


    QPixmap pim(":/images/menu_background.jpg");
    scene->setBackgroundBrush(pim.scaled(WID_WIDTH,WID_HEI,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    setScene(scene);

    // turn off the scroll bars both horizontal and vertical
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void MainWindow::mainmenu(){
    scene->clear();
    // add logo to start menu
    logo = new QGraphicsPixmapItem(QPixmap(":/images/icon_shark.png"));
    logo->setPos((scene->width() - logo->boundingRect().width()) / 2, scene->height() / 12);
    scene->addItem(logo);

    //add play and quit buttons
    play_button = new Button(":/images/play3.png");
    play_button->setGeometry((scene->width() - play_button->width()) /2,scene->height()/2,0,0);
    connect(play_button,SIGNAL(clicked()),this,SLOT(start()));
    scene->addWidget(play_button);

    quit_button = new Button(":/images/quit3.png");
    quit_button->setGeometry((scene->width() - quit_button->width()) /2,play_button->pos().y()+quit_button->height(),0,0);
    connect(quit_button,SIGNAL(clicked()),this,SLOT(close()));
    scene->addWidget(quit_button);

    demo_button = new Button(":/images/demoBtn.png");
    demo_button->setGeometry((scene->width() - demo_button->width()*2)/2, play_button->pos().y()-demo_button->height(),0,0);
    connect(demo_button,SIGNAL(clicked()),this,SLOT(start_demo()));
    scene->addWidget(demo_button);

    stress_button = new Button(":/images/stressBtn.png");
    stress_button->setGeometry((scene->width() - stress_button->width()/20)/2, play_button->pos().y()-stress_button->height(),0,0);
    connect(stress_button,SIGNAL(clicked()),this,SLOT(start_stress()));
    scene->addWidget(stress_button);
}
void MainWindow::display_gameover(){
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
            //scene->items()[i]->setEnabled(false);
            scene->items()[i]->setEnabled(false);
            //delete scene->items()[i];
    }
    scene->clear();
    bring_gameover_scene();

}
void MainWindow::bring_gameover_scene(){
    QPixmap pim(":/images/GameOverS.png");
    scene->setBackgroundBrush(pim.scaled(WID_WIDTH,WID_HEI,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    setScene(scene);

    quit_button = new Button(":/images/quit3.png");
    quit_button->setGeometry((scene->width() - quit_button->width()*2.5) /2,scene->height() - (quit_button->height()*2),0,0);
    connect(quit_button,SIGNAL(clicked()),this,SLOT(close()));
    scene->addWidget(quit_button);

    replay_button = new Button(":/images/replay.png");
    replay_button->setGeometry((scene->width() - replay_button->width()/2.2) /2,scene->height() - (replay_button->height()*2),0,0);
    connect(replay_button,SIGNAL(clicked()),this,SLOT(restart()));
    scene->addWidget(replay_button);


}
void MainWindow::restart(){
    replay_button->disconnect();
    quit_button->disconnect();
    replay_button->deleteLater();
    quit_button->deleteLater();
    /*for (size_t i = 0, n = scene->items().size(); i < n; i++){
            scene->items()[i]->setEnabled(false);
    }
    scene->clear();
    //delete scene;
    //scene = new QGraphicsScene(this);
    //scene->setSceneRect(0,0,WID_WIDTH,WID_HEI);
    //QPixmap pim(":/images/menu_background.jpg");
    //scene->setBackgroundBrush(pim.scaled(WID_WIDTH,WID_HEI,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    //setScene(scene);
    //scene = new QGraphicsScene(this);
    //this->mainmenu();
    //QTimer::singleShot(0,this, SLOT(start()));*/

    QPixmap pim(":/images/menu_background.jpg");
    scene->setBackgroundBrush(pim.scaled(WID_WIDTH,WID_HEI,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    setScene(scene);

    logo = new QGraphicsPixmapItem(QPixmap(":/images/icon_shark.png"));
    logo->setPos((scene->width() - logo->boundingRect().width()) / 2, scene->height() / 12);
    scene->addItem(logo);

    play_button = new Button(":/images/play3.png");
    play_button->setGeometry((scene->width() - play_button->width()) /2,scene->height()/2,0,0);
    connect(play_button,SIGNAL(clicked()),this,SLOT(start()));
    scene->addWidget(play_button);

    quit_button = new Button(":/images/quit3.png");
    quit_button->setGeometry((scene->width() - quit_button->width()) /2,play_button->pos().y()+quit_button->height(),0,0);
    connect(quit_button,SIGNAL(clicked()),this,SLOT(close()));
    scene->addWidget(quit_button);

    demo_button = new Button(":/images/demoBtn.png");
    demo_button->setGeometry((scene->width() - demo_button->width()*2)/2, play_button->pos().y()-demo_button->height(),0,0);
    connect(demo_button,SIGNAL(clicked()),this,SLOT(start_demo()));
    scene->addWidget(demo_button);

    stress_button = new Button(":/images/stressBtn.png");
    stress_button->setGeometry((scene->width() - stress_button->width()/20)/2, play_button->pos().y()-stress_button->height(),0,0);
    connect(stress_button,SIGNAL(clicked()),this,SLOT(start_stress()));
    scene->addWidget(stress_button);
}
void MainWindow::start(){
    scene->removeItem(logo);
    play_button->disconnect();
    quit_button->disconnect();
    demo_button->disconnect();
    stress_button->disconnect();
    play_button->deleteLater();
    quit_button->deleteLater();
    demo_button->deleteLater();
    stress_button->deleteLater();
    game_scene = new SceneManager(scene,0);

    game_scene->play_game();
}
void MainWindow::start_demo(){
    scene->removeItem(logo);
    play_button->disconnect();
    quit_button->disconnect();
    demo_button->disconnect();
    stress_button->disconnect();
    play_button->deleteLater();
    quit_button->deleteLater();
    demo_button->deleteLater();
    stress_button->deleteLater();
    game_scene = new SceneManager(scene,1);

    game_scene->play_game();
}
void MainWindow::start_stress(){
    scene->removeItem(logo);
    play_button->disconnect();
    quit_button->disconnect();
    demo_button->disconnect();
    stress_button->disconnect();
    play_button->deleteLater();
    quit_button->deleteLater();
    demo_button->deleteLater();
    stress_button->deleteLater();
    game_scene = new SceneManager(scene,2);

    game_scene->play_game();
}
