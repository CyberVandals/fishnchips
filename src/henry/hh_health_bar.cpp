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
    Health * new_health = tail;
    new_health = new Health(0,0 50,50);

    for(int i = 0; i < 5; i++)
    {
        new_health = new Health(this->pos().x()+10,this->pos().y(),this)
    }
}
