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

1. Stw??rz klas?? Student 
z polem nrIndeksu,
getterem (do pobrania numeru indeksu),
metod?? wyswietlNrIndeksu() wy??wietlaj??c?? numer indeksu. 
Pole nrIndeksu nie mo??e by?? publiczne.

2. Stw??rz klas?? Kolokwium dziedzicz??c?? po klasie Student 
z polami: wynikKol1, wynikKol2, wynikKol3,
(3-parametrowym) setterem (do pobrania wynik??w ka??dego kolokwium (w punktach)),
metod?? wy??wietlWynikiKolokwium() wy??wielaj??c?? wyniki kolokwi??w.
Pola maj?? by?? typu zmiennoprzecinkowego i nie mog?? by?? publiczne.

3. Stw??rz klas?? Egzamin 
z polem wynikEgzaminu,
getterem (do pobrania wyniku egzaminu (w punktach)),
metod?? wy??wietlWynikEgzaminu() wy??wietlaj??c?? wynik egzaminu.
Pole wynik_egzaminu ma by?? typu zmiennoprzecinkowego i mie mo??e by?? publiczne.

4. Stw??rz klas?? Wynik dziedzicz??c?? po klasach Kolokwium oraz Egzamin 
zawieraj??c?? pole wynikStudenta,
metod?? obliczWynik(), 
wyswietlWynik() 
odpowiednio obliczaj??cymi oraz wy??wietlaj??cymi wynik studenta.
Pole wynikStudenta musi by?? prywatne.
Wynik studenta ma by?? obliczony wed??ug wzoru: (wynikKol1 + wynikKol2 + wynikKol3) / 3 + 3 * wynikEgzaminu.

5. Utw??rz dw??ch student??w 
(jednego w spos??b statyczny, drugiego w spos??b dynamiczny),
pobierz dla ka??dego z nich:
numer indeksu, wyniki kolokwi??w oraz wynik egzaminu,
nast??pnie oblicz wynik ko??cowy,
na ko??cu go wy??wietl. 

Zapobiegaj wyciekom pami??ci  usuwaj??c r??cznie obiekty w przypadku, gdy jest to wymagane.


*/