#include <string>
#include <iostream>
#include <ostream>

using namespace std;

class Creature
{
        private:
            string name;
            int life;
        public:
            Creature(string name ,int L):name(name),life(L)
            {};
            Creature(const Creature &creature):name(creature.name),life(creature.life)
            {
                    new Creature(*this);
            };
            ~Creature(){};
            bool is_a_zombie();
            virtual bool  is_a_good()const ;
            virtual void  clone()const;
            void beat();
            virtual void bless() ;
            void print();
};

class Good_creature : public Creature
{
        private:
                int good_thrsh; 
                int pos_i;   

        public:     
                Good_creature(string name ,int life,int good_thrsh):Creature(name,life),good_thrsh(good_thrsh),pos_i(pos_i)
                {
                        cout<<"Good Creature created"<<endl;
                };
                Good_creature(const Good_creature &good):Creature(good),good_thrsh(good.good_thrsh)
                {
                        new Good_creature(*this);
                        cout<<"copy Good Creature created"<<endl;
                };
                ~Good_creature(){ cout<<"Good Creature destroyed"<<endl; };
                virtual void  bless(int life );
                virtual void  clone(int pos_i)const;
                virtual bool is_a_good() const;

};


class Bad_creature : public Creature
{
        private:
                int bad_thrsh;

        public:
                Bad_creature(string name ,int life,int bad_thrsh):Creature(name,life),bad_thrsh(bad_thrsh)
                {
                        cout<<"Bad Creature destroyed"<<endl;
                };
                Bad_creature(const Bad_creature &bad):Creature(bad),bad_thrsh(bad.bad_thrsh)
                {
                        new Bad_creature(*this);
                        cout<<"copy Bad Creature destroyed"<<endl;
                };
                ~Bad_creature(){cout<<"Bad Creature destroyed"<<endl; };
                virtual void bless(int life) ;
                virtual void clone(int pos_i) const;
                virtual bool is_a_good() const;
};




class Creature_Society
{
        private:
                Creature **creatures;
                int number_Of_Positions;
                int pos_i,good_thrsh,bad_thrsh;

        public:
                Creature_Society(int N,int L,int good_thrsh ,int bad_thrsh):number_Of_Positions(N),good_thrsh(good_thrsh),bad_thrsh(bad_thrsh),pos_i(pos_i)
                {       
                        string good_names[10]={"PeterP","TonyS","SteveR","Thor","NatashaR","BruceB","BlackP","StephenS","ScottL","ClintB"};
                        string bad_names[10]={"NormanO","ObadiahS","RedS","Loki","GeneralD","Maestro","ErikK","MAdsM","WAspG","MAdameM"};
                        creatures=new Creature*[N];
                        for (int i = 0; i < N; i++)
                        {
                                if (rand()%2+1==1)
                                {
                                        creatures[i]=new Good_creature(good_names[rand()%10+1],L,good_thrsh);
                                }
                                else
                                {
                                        creatures[i]=new Bad_creature(bad_names[rand()%10+1],L,bad_thrsh);
                                }
                        }
                        
                };
                
                ~Creature_Society()
                {
                        for (int i = 0; i < number_Of_Positions; i++)
                        {
                                delete creatures[i];
                        }
                        
                        delete[] creatures;
                };
                void beat(int pos_i);
                virtual void bless(int pos_i);
                void clone_next(int pos_i);
                void clone_zombies(int pos_i); 
                int no_of_good();
                int no_of_zombies();
                void print();
};
