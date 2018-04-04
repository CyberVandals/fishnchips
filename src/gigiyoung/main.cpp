/* main.cpp - main for testing objects
 */

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include "../../inc/gigiyoung/gy_object.h"

int main(int argc, char **argv) {
    QApplication a(argc, argv);

    // make objects 
    QGraphicsScene *scene = new QGraphicsScene(0,0,400,400);
    QGraphicsView *view = new QGraphicsView(scene);

    // create items
    // platforms
    //Platform *plat1, *plat2, *plat3, *plat4;
    //plat1 = new Platform(10,600,0,0);
    //plat2 = new Platform(600,10,0,0);
    //plat3 = new Platform(600,10,0,590);
    //plat4 = new Platform(10,600,590,0);
 
    // sharks 
    Shark *shark1 = new Shark(200,200);

    // bananas
    //Banana *bana1 = new Banana(300,300);

    // steam
    //Steam *steam1 = new Steam(200,200);

    // exit
    //Exit *exit = new Exit(530,20);


    // add items to scene
    //scene->addItem(plat1);
    //scene->addItem(plat2);
    //scene->addItem(plat3);
    //scene->addItem(plat4);
    scene->addItem(shark1);
    //scene->addItem(bana1);
    //scene->addItem(steam1);
    //scene->addItem(exit);
    

    view->mapToScene(0,0,600,600);
    // show
    view->show();

    return a.exec();
}
