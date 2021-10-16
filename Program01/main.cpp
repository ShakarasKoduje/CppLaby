#include <iostream>
#include <windows.h>
#include <string>
#include <locale.h>

using namespace std;

void PrzejdzDalej();

class Obiekt {
    public:
        void Nazwij(string n){
            this->nazwa = n;
        }
        void Wypisz(){
            cout << "Obiekt ma nazwe: " << this->nazwa << endl;
        }

    private:
        string nazwa;
};


int main(){
    setlocale( LC_ALL, "pl_PL" );
    string name;
    cout << "Hello Me" << endl;
    getline(cin, name);
    cout << "\n" << name << endl;

    Obiekt *o1 = new Obiekt();
    o1->Nazwij(name);
    o1->Wypisz();
    delete o1;


    PrzejdzDalej();
    return 0;
}

void PrzejdzDalej(){
    cout << "Naciśnij ENTER by przejść dalej";
    cin.get();
}