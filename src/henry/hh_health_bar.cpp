#include "../../inc/henry/hh_health_bar.h"
#include "../../inc/henry/hh_health.h"
#include <QDebug>

void HealthBar::add_health(QGraphicsScene * scene)
{
    //qDebug() << "add health";
    int new_x_pos = health_list.last()->new_x_pos+30; //for visual cleanliness, each health box will be 30 pixels to the right of the last
    Health * health = new Health(new_x_pos);
    health_list.append(health);
    scene->addItem(health); //adds them to the scene and makes them visible
    health_list.last()->setVisible(true);
}

void HealthBar::renew_health()
{
//unused currently
}

int HealthBar::decrease_health()
{
    if(health_list.isEmpty() == false) //only do this if list is empty, otherwise will seg fault
    {
        health_list.last()->setVisible(false);
        health_list.removeLast();
        //qDebug() << health_list.count();
        return health_list.count(); //return this so we know when there is no more health left (player is dead), returns to shark_collision()
    }


}



HealthBar::HealthBar(QGraphicsScene *scene): QGraphicsRectItem()
{

    if(scene == 0)qDebug() << "no scene visualized";


    int x_pos = 5; //padding before health bar
    for(int i = 0; i < 5; i++)//player starts with 5 health
    {
        Health * health = new Health(x_pos); //y position doesnt need to change, intialize all 5 health objects
        scene->addItem(health);
        x_pos = x_pos + 30; //increment health position so they're not stacked
        health_list.append(health);
    }
}
