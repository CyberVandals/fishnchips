#include "../../inc/henry/hh_health_bar.h"
#include "../../inc/henry/hh_health.h"


void Health::add_health()
{
    //tail = new Health(tail);


}

void Health::renew_health()
{

}

HealthBar::HealthBar()
{
    //Health * new_health = tail;
    Health tail = new Health(0,0,0,this);

    for(int i = 1; i <= 5; i++)
    {
        tail = new Health(tail->pos().x()+10,tail->pos().y(), i, tail)
    }
}
