#include <iostream>
#include <cmath>

using namespace std;



class Student{
    protected:
        int nrIndeksu;

    public:

        int getNrIndeksu() { return this->nrIndeksu;}
        
        void setNrIndeksu(int numer){
            this->nrIndeksu = numer;
        }

        void wyswietlNrIndeksu(){
            cout << this->getNrIndeksu() << endl;
        }
};

class Kolokwium : virtual public Student{
    protected:
        double wynikKol1, wynikKol2, wynikKol3;

    public:
        void setWynikiKolokwium(double j, double d, double t){
            this->wynikKol1 = j; this->wynikKol2 = d; this->wynikKol3 = t;
        }
        double getWynikiKolokwium(){
            return (this->wynikKol1 + this->wynikKol2 + this->wynikKol3)/3;
        }
        void wyswietlWynikiKolokwium(){
            cout <<"Kolokwium 1: " << this->wynikKol1 << "pkt. Kolokwium 2: " << this->wynikKol2 << "pkt. Kolokwium 3: " << this->wynikKol3 <<"pkt."<<endl;
        }

};

class Egzamin: virtual public Student{
    protected:
        double wynikEgzaminu;
    public:
        double getWynikEgzaminu(){
            return this->wynikEgzaminu;
        }
        void setWynikEgzaminu(double e){
            this->wynikEgzaminu = e;
        }
        void wyswietlWynikEgzaminu(){
            cout << "Wynik egzaminu: " << this->wynikEgzaminu << endl;
        }
};

class Wynik: public Kolokwium, public Egzamin{
    protected:
        double wynikStudenta;

    public:

        void obliczWynik(){
            this->wynikStudenta = this->getWynikiKolokwium() + 3* (this->getWynikEgzaminu()); //k+ 3*e;

        }
        void sredniaKolokwia(){
            cout << "Srednia z kolokwiow Studenta {numer indeksu: "<< this->getNrIndeksu()<< "}: " << this->getWynikiKolokwium() << endl;

        }
        void wyswietlEgzamin(){
            cout << "Wynik Egzaminu Studenta {numer indeksu: "<< this->getNrIndeksu()<< "}: " << this->getWynikEgzaminu() << endl;

        }
        void wyswietlWynik(){
            cout << "Wynik Studenta {numer indeksu: "<< this->getNrIndeksu()<< "}: " << this->wynikStudenta << endl;

        }
};

int main(){
    Wynik s1;
    Wynik *s2 = new Wynik;

    s1.setNrIndeksu(1234); 
    s2->setNrIndeksu(5678);

    s1.setWynikiKolokwium(4.5, 3.5, 3); 
    s2->setWynikiKolokwium(4,3,5);

    s1.setWynikEgzaminu(4); 
    s2->setWynikEgzaminu(3);

    s1.sredniaKolokwia();
    s2->sredniaKolokwia();

    s1.wyswietlEgzamin();
    s2->wyswietlEgzamin();

    s1.obliczWynik(); 
    s2->obliczWynik();

    s1.wyswietlWynik(); 
    s2->wyswietlWynik();
    
    delete(s2);
    
    return 0;
}

/*

Laboratorium 8.

Zadanie 1.

Przekształć program z poprzednich zajęć (Zadanie 7.1) tak, aby efekt działania był taki sam, 
natomiast hierarchia dziedziczenia była następująca:


       Student------->(Kolokwium, Egzamin)------->Wynik
              
Użyj słowa kluczowego virtual.



*/