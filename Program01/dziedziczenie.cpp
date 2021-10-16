#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace std;

class Postac{
    protected:
        int Walka;
        string name;
    public:
        Postac() {
  
        };

        virtual void Krzyk(){
            cout << "GRRRRRRRRRRRRRR" << endl;
        }
        void Atakuj(Postac &p){
            cout << this->name << "Z walka: " << this->Walka << " ATAKUJE W " << p.name << " o walce: " << p.Walka <<endl;

        }


};

class Gracz: public Postac{
    public:
        Gracz(string n, int w) {
            this->name = n;
            this->Walka = w; 

        };
        
        int getWalka(){
            return this->Walka;
        }

        void Krzyk(){
            cout << "JESTEM GRACZEM." <<endl;
        }

};

class Potwor: public Postac{
    public:
        Potwor(string n, int w) {
            this->name = n;
            this->Walka = w; 

        };
         
        int getWalka(){
            return this->Walka;
        }
        void Krzyk(){
            cout << "JESTEM POTWOREM." <<endl;
        }
};


int main(){
    srand (time(NULL));

    Gracz *player = new Gracz("sir Albrecht",10);
    Potwor *potwor = new Potwor("Zmutowany Grzybolud",7);
    cout << player->getWalka() << endl;
    cout << potwor->getWalka() << endl;
    player->Atakuj(*potwor);
    player->Krzyk();

    //Postac *listapostaci[] = {player, potwor, potwor, player};
    //Postac *listapostaci[4] = {player, potwor, potwor, player};
    const int rozmiar = 7;
    Postac *listapostaci[rozmiar] = {};
    
    for(auto &p : listapostaci){
        //p->Krzyk();
        int los = rand()%100+1;
        cout << "\nLOS: " << los << " "<< los%2 <<endl;
        if(los%2 == 0) p = player;
        else p = potwor;
        p->Krzyk();
    }




    delete player;
    delete potwor;


    return 0;
}

