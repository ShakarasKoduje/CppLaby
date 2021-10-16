#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Figura{


    double r;
    double h1;
    double h2;


    public:
        Figura(){
            this->r = 101;
            this->h1 = 102;
            this->h2 = 103; 
        }
        Figura(double R, double H1, double H2) : r(R), h1(H1), h2(H2){

           
        }

  

        //Dla wszystkich obiektów wywołujemy metody obliczające pole powierzchni figury złożonej (oblicz_powierchnie()) i jej objętość (oblicz_objetosc()).
        double oblicz_objetosc(){

            double polePodstawy = M_PI * (r*r);
            double walec = M_PI * (r*r) * h1;
            double stozek = (M_PI * (r*r) * h2)/3;
            double kula = ((4 * M_PI * pow(r,3))/3)/2;
            double wynik = kula + walec + stozek - (polePodstawy*3);

            return wynik;
        }  
        double oblicz_powierzchnie(){

            double walec = 2 * M_PI * r *h1;
            double tmp = pow(r,2) + pow(h2,2);
            double l = sqrt(tmp);
            double stozek = M_PI * r * l;
            double kula = (4 * M_PI * pow(r,2))/2;
            double wynik = kula + stozek + walec;

            return wynik;
        }
    
};

int main(){
    Figura f1;
    Figura f2(101, 102, 103);
    Figura f3(11,12,13);
    cout << "Figura 1: Powierzchnia: " << f1.oblicz_powierzchnie() << " Objetosc: " << f1.oblicz_objetosc()  << endl;
    cout << "Figura 2: Powierzchnia: " << f2.oblicz_powierzchnie() << " Objetosc: " << f2.oblicz_objetosc() << endl;
    cout << "Figura 3: Powierzchnia: " << f3.oblicz_powierzchnie() << " Objetosc: " << f3.oblicz_objetosc() << endl;

    Figura * f4 = new Figura(21,20,19);
    cout << "Figura 4: Powierzchnia: " << f4->oblicz_powierzchnie() << " Objetosc: " << f4->oblicz_objetosc() << endl;

    delete f4;
    return 0;
}

/*
Laboratorium 2.

Zadanie 1.

Część 1

1. 
Utwórz klasę zawierającą następujące pola:
- promień kuli,
- wysokość walca,
- wysokość stożka.

2.
Klasa powinna zawierać 2 konstruktory: 
-bezparametrowy 
-parametrowy (3 parametry: r, h1, h2).

3.
W konstruktorze bezparametrowym do zmiennych przypisujemy wartości: 101, 102, 103. 
Tworzymy statycznie trzy obiekty.
Dwa z nich z zastosowaniem konstruktora parametrowego. 
Pierwszy z wartościami identycznymi jak w przypadku konstruktora bezparametrowego. 
Drugi z parametrami: 11,12,13.

4.
Dla wszystkich obiektów wywołujemy metody obliczające pole powierzchni figury złożonej (oblicz_powierchnie()) i jej objętość (oblicz_objetosc()).
Uwaga:
Figura złożona składa się ze stożka, walca i połowy koła (góra-stożek, środek-walec, dół- połowa kuli).

5.
W funkcji main() wyświetlamy wyniki obliczeń.

Część 2

6.
Zmodyfikuj program tworząc nowy obiekt w sposób dynamiczny z zastosowaniem konstruktora parametrowego (dla parametrów 21,20,19).

7.
Oblicz (i wyświetl wynik w funkcji main()) powierzchnię i objętość bryły złożonej.

Użyj do tego celu listy inicjalizacyjnej.

        //settery
        void setR(double R){
            this->r = R;
        }
        void setH1(double H1){
            this->h1 = H1;
        }
        void setH2(double H2){
            this->h2 = H2;
        }
        //gettery
        double getR(){
            return this->r;
        }
        double getH1(){
            return this->h1;
        }
        double getH2(){
            return this->h2;
        } 
*/