#include "../../inc/henry/hh_health_bar.h"
#include "../../inc/henry/hh_health.h"


void HealthBar::add_health()
{
    //tail = new Health(tail);


}

void HealthBar::renew_health()
{

}

void HealthBar::decrease_health()
{

}

HealthBar::HealthBar()
{
    tail = new Health(0,0,0,this);

    for(int i = 1; i <= 5; i++)
    {
        tail = new Health(tail->pos().x()+10,tail->pos().y(), i, tail)
    }
}
