#include "../../inc/henry/hh_health_bar.h"
#include "../../inc/henry/hh_health.h"
#include <QDebug>

void HealthBar::add_health()
{
    int new_x_pos = health_list.last()->x_pos+10;
    Health * health = new Health(new_x_pos);
    health_list.append(health);
}

void HealthBar::renew_health()
{

}

void HealthBar::decrease_health()
{
    qDebug() << "in decrease health\n";
    if(health_list.isEmpty() == false)
    {
         health_list.removeLast();
    }

    else if(health_list.isEmpty())
    {
        qDebug() << "you dead";
    }
}



HealthBar::HealthBar()
{
    static int x_pos = 0;
    for(int i = 0; i < 5; i++)
    {
        Health * health = new Health(x_pos); //y position doesnt need to change
        x_pos = x_pos + 10;
        health_list.append(health);
    }
}
