#include "../../inc/henry/hh_health_bar.h"
#include "../../inc/henry/hh_health.h"
#include <QDebug>

void HealthBar::add_health()
{
    int new_x_pos = health_list.last()->new_x_pos+30;
    Health * health = new Health(new_x_pos);
    health_list.append(health);
}

void HealthBar::renew_health()
{

}

int HealthBar::decrease_health()
{
    qDebug() << "in decrease health\n";
    if(health_list.isEmpty() == false)
    {
        health_list.last()->setVisible(false);
        health_list.removeLast();
        if(health_list.count() == 0)
        {
        return health_list.count();
        }

         if(health_list.isEmpty())
         {
            qDebug() << "you dead";
         }
         qDebug()<< health_list.count();
    }

    else if(health_list.isEmpty())
    {
        qDebug() << "you dead";
    }
}



HealthBar::HealthBar(QGraphicsScene *scene): QGraphicsRectItem()
{

    if(scene == 0)qDebug() << "no scene visualized";

    //Health * health = new Health(); //y position doesnt need to change
    //scene->addItem(health);

    static int x_pos = 5;
    for(int i = 0; i < 5; i++)
    {
        Health * health = new Health(x_pos); //y position doesnt need to change
        scene->addItem(health);
        x_pos = x_pos + 30;
        health_list.append(health);
    }
}
