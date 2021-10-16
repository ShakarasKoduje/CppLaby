#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;


/*
    w zadaniu zrobiłem dwie metody dodajAiB
    jedna jest w klasie Drugiej, a druga jest zaprzyjaźnioną metodą dla obu klas.
*/


class Druga;

class Pierwsza{
    friend class Druga;
    int wartoscA;
    
    public:
        Pierwsza() : wartoscA(150){}
        friend int dodajAiB2(Pierwsza & a, Druga & b);
      
        
};


class Druga{
    friend class Pierwsza;
    int wartoscB;
    //

    public:
        Druga(){
            wartoscB = 20;
        }
        int dodajAiB(Pierwsza & a, Druga & b){
            int wynik = a.wartoscA + b.wartoscB;
            return wynik;
        }
        friend int dodajAiB2(Pierwsza & a, Druga & b);

};

int dodajAiB2(Pierwsza &a, Druga &b){
    return a.wartoscA + b.wartoscB;
}

int main(){

    Pierwsza A;
    Druga B;

    
    cout << B.dodajAiB(A, B) <<endl;
    cout << dodajAiB2(A,B)<<endl;
    


    return 0;
}



/*
Laboratorium 3.

Zadanie 1.

1. Utwórz klasę Pierwsza zawierającą:
- pole prywatne wartoscA;
- konstuktor bezparametrowy z przypisaną warością równą 150 (w tym celu użyj listy inicjalizującej).

2. Utwórz klasę  Druga zawierającą:
- pole prywatne wartoscB;
- konstuktor bezparametrowy z przypisaną warością równą 20 (nie używaj listy inicjalizującej).

3. Do klasy ( Pierwsza ) lub ( Druga ) lub ( Pierwsza i Druga ) dodaj odpowiednią metodę dodajAiB() 
umożliwiającą dodawanie 
aktualnych wartości obiektów klasy Pierwsza oraz Druga. 
Metoda dodajAiB() powinna być dwuargumentowa, określona poprzez typ klasy Pierwsza oraz typ klasy Druga. 
(Pamiętaj o wykorzystaniu słowa kluczowego friend).

4. W odpowiednim miejscu i w odpowiedni sposób zdefiniuj metodę dodajAiB().

5. W funkcji main():
- utwórz statycznie dwa obiekty (po jednym dla każdej klasy);
- wywołaj metodę dodajAiB();
- wyświetl wynik dodawania obiektów za pomocą  strumienia wyjściowego cout.


*/