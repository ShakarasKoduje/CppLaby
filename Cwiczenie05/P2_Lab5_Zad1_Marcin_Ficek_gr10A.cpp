#include <iostream>
#include <cmath>

using namespace std;


class Zespolona{
    double czesc_rzeczywista=0;
    double czesc_urojona=0;
    
    public:
        Zespolona(){}
        Zespolona(double re, double im) : czesc_rzeczywista(re), czesc_urojona(im){

        }
        void Wyswietl(){
            if(this->czesc_urojona >=0) cout << this->czesc_rzeczywista <<" + i" << this->czesc_urojona <<endl;
            else  cout << this->czesc_rzeczywista <<" - i" << abs(this->czesc_urojona) <<endl;
        }
        //Przeciążenie operatorów arytmetycznych:
        friend Zespolona operator + (const Zespolona &z1, const Zespolona &z2);
        friend Zespolona operator - (const Zespolona &z1, const Zespolona &z2);
        friend Zespolona operator * (const Zespolona &z1, const Zespolona &z2);
        friend Zespolona operator / (const Zespolona &z1, const Zespolona &z2);

        //Przeciążenie operatorów new oraz delete
        static void* operator new(size_t n){
            cout <<"Wywolanie nadpisanego operatora new" <<endl;
            void * wskaznik = malloc(n);
            return wskaznik;
        }
        void operator delete(void * wskaznik){
            
        cout<< "Wywolanie nadpisanego operatora delete " << endl;
        free(wskaznik);
        }       
};


Zespolona operator + (const Zespolona &z1, const Zespolona &z2){
    double re = z1.czesc_rzeczywista+z2.czesc_rzeczywista;
    double im = z1.czesc_urojona+z2.czesc_urojona;
    Zespolona z3(re, im);
    return z3;
}
Zespolona operator - (const Zespolona &z1, const Zespolona &z2){
    double re = z1.czesc_rzeczywista-z2.czesc_rzeczywista;
    double im = z1.czesc_urojona-z2.czesc_urojona;
    Zespolona z3(re, im);
    return z3;
}
Zespolona operator * (const Zespolona &z1, const Zespolona &z2){
    double re = z1.czesc_rzeczywista*z2.czesc_rzeczywista - z1.czesc_urojona*z2.czesc_urojona;
    double im = z1.czesc_urojona*z2.czesc_rzeczywista + z2.czesc_urojona*z1.czesc_rzeczywista;
    Zespolona z3(re, im);
    return z3;
}
Zespolona operator / (const Zespolona &z1, const Zespolona &z2){
    double re = (z1.czesc_rzeczywista*z2.czesc_rzeczywista + z1.czesc_urojona*z2.czesc_urojona)/(z2.czesc_rzeczywista*z2.czesc_rzeczywista + z2.czesc_urojona*z2.czesc_urojona);
    double im = (z1.czesc_rzeczywista*z2.czesc_urojona - z1.czesc_urojona*z2.czesc_rzeczywista)/(z2.czesc_rzeczywista*z2.czesc_rzeczywista + z2.czesc_urojona*z2.czesc_urojona);
    Zespolona z3(re, im);
    return z3;
}

int main(){
    Zespolona z1(12,-20);
    Zespolona z2;
    z1.Wyswietl();
    Zespolona z3 = z1 + z1;
    Zespolona z4 = z2 / z1;
    z4.Wyswietl();

    z3.Wyswietl();

    Zespolona * ptrZ1 = new Zespolona(12,-999.98787);
    Zespolona * ptrZ2 = new Zespolona(-123.1, 58.8989);

    Zespolona * ptrZ3 = new Zespolona(1, 5);

    *ptrZ3 = *ptrZ1 - (*ptrZ2);
    ptrZ3->Wyswietl();
    *ptrZ3 = *ptrZ1 + (*ptrZ2);
    ptrZ3->Wyswietl();
    *ptrZ3 = *ptrZ1 / (*ptrZ2);
    ptrZ3->Wyswietl();
    *ptrZ3 = *ptrZ1 * (*ptrZ2);
    ptrZ3->Wyswietl();
    delete(ptrZ1);
    delete(ptrZ2);
    delete(ptrZ3);
    return 0;
}

/*

Laboratorium 5.

Zadanie 1.

1. Zdefiniuj klasę Zespolona (zawierającą pola: czesc_rzeczywista, czesc_urojona, 
konstruktor 2-parametrowy umożliwiający inicjalizację liczby zespolonej,
metodę wyswietl() umożliwiającą wyświetlenie liczby zespolonej w postaci algebraicznej (z = a + bi), 
przeciążone operatory dodawania, odejmowania, mnożenia oraz dzielenia zwracające obiekt klasy Zespolona 
(zadbaj o oprawność operacji arytmetycznych dla liczb zespolonych).
Określ pola przechowujące dane jako prywatne, a metody oraz przeciążone operatory jako publiczne.
Przeciążone operatory są 2-operandowe (mają umożliwiać operacje na dwóch obiektach klasy Zespolona).
Wyniki operacji mają być zapisywane do kolejnych obiektów klasy Zespolona.
Wyświetl wyniki operacji z zastosowaniem przeciążonych operatorów w funkcji main().

2. Do klasy Zespolona dodaj przeciążone operatory: new oraz delete. 
(Wykorzystaj w tym celu funkcje malloc() oraz free().)
Wykorzystaj je do dynamicznego tworzenia obiektów klasy Zespolona oraz ich usuwania,
a następnie do realizacji operacji arytmetycznych na liczbach zespolonych.

*/