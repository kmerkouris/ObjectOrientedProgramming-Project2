#include <iostream>
#include <string.h>
#include <cstring>
#include "creature.h"

using namespace std;

///////////////////-Creature-//////////////////////////
bool Creature::is_a_zombie()
{
    if (life==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Creature::beat()
{
    if (is_a_zombie()==false)
    {
        life=life-1;
        clone();
    }
}

void Creature::bless()
{
    if (is_a_zombie()==false)
    {
        life=life+1;
        clone();
    }
}
void Creature::print()
{
    cout<<"name"<<name<<"life"<<life<<endl;
}
//////////////////////////good-Creature///////////////////
void Good_creature::bless(int life) 
{
    Creature::bless();
    if (life>good_thrsh)
    {
       clone(pos_i);
    }
}

void Good_creature::clone(int pos_i) const
{
    
}

bool Good_creature::is_a_good() const
{
    return true;
}


/////////////////////////////bad-Creature///////////////////
void Bad_creature::bless(int life)
{
    Creature::bless();
    if (life>bad_thrsh)
    {
        
    }
}
void Bad_creature::clone(int pos_i) const
{
    
}

bool Bad_creature::is_a_good() const
{
    return false;
}
///////////////////////Creature-Society///////////////////////////
void Creature_Society::print()
{
    for (size_t i = 0; i < number_Of_Positions; i++)
    {
        creatures[i]->print();
    }

}
void Creature_Society::beat(int pos_i)
{
    beat(pos_i);

}

void Creature_Society::bless(int pos_i)
{
    bless(pos_i);
}

void Creature_Society::clone_next(int pos_i)
{
    if (pos_i!=number_Of_Positions)
    {
        delete creatures[pos_i+1];
        creatures[pos_i+1]= new Good_creature(creatures[pos_i]);
    }
    else
    {

        delete creatures[0];
        creatures[0]=new Good_creature(creatures[pos_i]);
    }    
}


void Creature_Society::clone_zombies(int pos_i)
{
    
}

