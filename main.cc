#include <cstring>
#include <iostream>
#include "creature.h"
#include <time.h>


using namespace std;

int main (int argc,char* argv[])
{

    srand(time(NULL));
                                                              
    int N=std::atoi(argv[1]);
    int M=std::atoi(argv[2]);
    int L=std::atoi(argv[3]);
    int good_thrsh=std::atoi(argv[4]);
    int bad_thrsh=std::atoi(argv[5]);

    Creature_Society society(N,L,good_thrsh,bad_thrsh);

    int pos_i,action;                                          //random position and random action of 2(bless or beat)
    for (int i=0;i<M;i++)
    {
        pos_i=rand()%N+1;
        action=rand()%2+1;
        if(action==1)
        {
            society.beat(pos_i);
        }
        else if(action==2)
        {
            society.bless(pos_i);
        }
    }
    
    if (society.no_of_good()==N) 
    {
        cout<<"Good Dominates in the World!"<<endl;
    }
    else if (society.no_of_zombies()!=0)
    {
        cout<<"This is a dead society"<<endl;
    }
    else
    {
        cout<<"Try again to improve the world"<<endl;
    }
    society.print();

}