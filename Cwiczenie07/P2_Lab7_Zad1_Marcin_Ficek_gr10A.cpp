#include <iostream>
#include <cmath>

using namespace std;



class Student{
    protected:
        int nrIndeksu;

    public:

        virtual int getNrIndeksu() = 0;
        void setNrIndeksu(int numer){
            this->nrIndeksu = numer;
        }

        void wyswietlNrIndeksu(){
            cout << this->getNrIndeksu() << endl;
        }
};

class Kolokwium : public Student{
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

class Egzamin : public Student{
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
        virtual int getNrIndeksu() override{
            return this->nrIndeksu;
        }

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

    
    delete(s2);
    
    return 0;
}

/*

Laboratorium 7.

Zadanie 1.

1. Stwórz klasę Student 
z polem nrIndeksu,
getterem (do pobrania numeru indeksu),
metodą wyswietlNrIndeksu() wyświetlającą numer indeksu. 
Pole nrIndeksu nie może być publiczne.

2. Stwórz klasę Kolokwium dziedziczącą po klasie Student 
z polami: wynikKol1, wynikKol2, wynikKol3,
(3-parametrowym) setterem (do pobrania wyników każdego kolokwium (w punktach)),
metodą wyświetlWynikiKolokwium() wyświelającą wyniki kolokwiów.
Pola mają być typu zmiennoprzecinkowego i nie mogą być publiczne.

3. Stwórz klasę Egzamin 
z polem wynikEgzaminu,
getterem (do pobrania wyniku egzaminu (w punktach)),
metodą wyświetlWynikEgzaminu() wyświetlającą wynik egzaminu.
Pole wynik_egzaminu ma być typu zmiennoprzecinkowego i mie może być publiczne.

4. Stwórz klasę Wynik dziedziczącą po klasach Kolokwium oraz Egzamin 
zawierającą pole wynikStudenta,
metodę obliczWynik(), 
wyswietlWynik() 
odpowiednio obliczającymi oraz wyświetlającymi wynik studenta.
Pole wynikStudenta musi być prywatne.
Wynik studenta ma być obliczony według wzoru: (wynikKol1 + wynikKol2 + wynikKol3) / 3 + 3 * wynikEgzaminu.

5. Utwórz dwóch studentów 
(jednego w sposób statyczny, drugiego w sposób dynamiczny),
pobierz dla każdego z nich:
numer indeksu, wyniki kolokwiów oraz wynik egzaminu,
następnie oblicz wynik końcowy,
na końcu go wyświetl. 

Zapobiegaj wyciekom pamięci  usuwając ręcznie obiekty w przypadku, gdy jest to wymagane.


*/