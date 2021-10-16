#include <iostream>

using namespace std;

struct zespolona {
    double rzeczywista;
    double urojona;
};

void pobierzDane(struct zespolona*);
void wyswietlWynik(struct zespolona);
struct zespolona suma(struct zespolona, struct zespolona);
struct zespolona roznica(struct zespolona, struct zespolona);
struct zespolona iloczyn(struct zespolona, struct zespolona);
struct zespolona iloraz(struct zespolona, struct zespolona);
struct zespolona sprzezona(struct zespolona);

int main(){

    zespolona z1;
    zespolona z2;
    cout << "Wprowadz dane dla z1: " ;
    pobierzDane(&z1);
    cout << "Wprowadz dane dla z2: " ;
    pobierzDane(&z2);
    zespolona z3 = suma(z1,z2); 
    wyswietlWynik(z3);
    zespolona z4 = roznica(z1,z2); 
    wyswietlWynik(z4);
    zespolona z5 = iloczyn(z1,z2);
    wyswietlWynik(z5);
    zespolona z6 = iloraz(z1,z2);
    wyswietlWynik(z6);
    zespolona z7 = sprzezona(z1);
    wyswietlWynik(z7);
    zespolona z8 = sprzezona(z2);
    wyswietlWynik(z8);




    return 0;
}

void pobierzDane(struct zespolona* z){
    cout << "Wprowadz dane dla czesci rzeczywistej: ";
    cin >> z->rzeczywista ;
    cout << "Wprowadz dane dla czesci urojonej: ";
    cin >>  z->urojona;
}
void wyswietlWynik(struct zespolona z){
    if(z.urojona > 0) cout << "Liczba zespolona: " << z.rzeczywista << " + " << z.urojona <<"i" << endl;
    else cout << "Liczba zespolona: " << z.rzeczywista << " - " << z.urojona*(-1) <<"i" << endl;
}

struct zespolona suma(struct zespolona z1, struct zespolona z2){
    //sumę (z3 = (a+c) + (b+d)i) w oparciu o funkcję suma();
    struct zespolona z;
    z.rzeczywista = z1.rzeczywista + z2.rzeczywista;
    z.urojona = z1.urojona + z2.urojona;
    return z;

}

struct zespolona roznica(struct zespolona z1, struct zespolona z2){
//różnicę (z4 = (a-c) + (b-d)i) w oparciu o funkcję roznica();
    struct zespolona z;
    z.rzeczywista = z1.rzeczywista - z2.rzeczywista;
    z.urojona = z1.urojona - z2.urojona;
    return z;

}
struct zespolona iloczyn(struct zespolona z1, struct zespolona z2){
//- iloczyn (z5 = (a*c-b*d) + (a*d+b*c)i) w oparciu o funkcję iloczyn();
//(z1 = a + bi; z2 = c + di)
    struct zespolona z;
    z.rzeczywista = (z1.rzeczywista * z2.rzeczywista)-(z1.urojona * z2.urojona);
    z.urojona = (z1.rzeczywista * z2.urojona)-(z1.urojona * z2.rzeczywista);
    return z;
}

struct zespolona iloraz(struct zespolona z1, struct zespolona z2){
//(z1 = a + bi; z2 = c + di)    
//- iloraz (z6 = (a*c+b*d)/(c*c+d*d) + ((b*c-a*d)/(c*c+d*d))i (c*c+d*d>0) w oparciu o funkcję iloraz();
    struct zespolona z;
    double mianownik = (z1.urojona*z1.urojona)+(z2.urojona*z2.urojona);
    double iloczynrzeczywisty = (z1.rzeczywista*z2.rzeczywista)+(z1.urojona*z2.urojona);
    double iloczynurojony = (z1.urojona*z2.rzeczywista)-(z1.rzeczywista*z2.urojona);
    if( mianownik >0 ){
            z.rzeczywista = iloczynrzeczywisty/mianownik;
            z.urojona = iloczynurojony/mianownik;
            return z;
    }
    else{
        return z;
    }
}

struct zespolona sprzezona(struct zespolona z1){
    struct  zespolona z;
    z.rzeczywista = z1.rzeczywista;
    z.urojona = z1.urojona * (-1);    
    return z;

}

/*
Laboratorium 1.

Zadanie 1:

Dana jest struktura w postaci:
struct zespolona {
                 double rzeczywista;
                 double urojona;
};

Dane są następujące deklaracje funkcji:
void pobierzDane(struct zespolona*);
void wyswietlWynik(struct zespolona);
struct zespolona suma(struct zespolona, struct zespolona);
struct zespolona roznica(struct zespolona, struct zespolona);
struct zespolona iloczyn(struct zespolona, struct zespolona);
struct zespolona iloraz(struct zespolona, struct zespolona);
struct zespolona sprzezona(struct zespolona);

Napisz program, który będzieł:
1.Umożliwiał wprowadzenie dwóch liczb zespolonych (z1 = a + bi; z2 = c + di) w oparciu o funkcję pobierzDane();

2.Wykonywał na nich operacje arytmetyczne:
- sumę (z3 = (a+c) + (b+d)i) w oparciu o funkcję suma();
- różnicę (z4 = (a-c) + (b-d)i) w oparciu o funkcję roznica();
- iloczyn (z5 = (a*c-b*d) + (a*d+b*c)i) w oparciu o funkcję iloczyn();
- iloraz (z6 = (a*c+b*d)/(c*c+d*d) + ((b*c-a*d)/(c*c+d*d))i (c*c+d*d>0) w oparciu o funkcję iloraz();
- sprzężenie (z7 = a - bi; z8 = c - di) w oparciu o funkcję sprzezona().

3.Wyświetlał wyniki wykonanych operacji w oparciu o funkcję wyswietlWynik().

Sprawdz poprawność obliczeń z zastosowaniem programu WolframAlpha (https://www.wolframalpha.com/).
*/