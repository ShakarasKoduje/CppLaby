#include <iostream>

using namespace std;

int Wypisz (int p, int pp, int k, int maks);

int main(){
        cout << Wypisz(1,1,3,1) << endl;
    cout << Wypisz(1,1,3,2) << endl;

    cout << Wypisz(1,1,3,3) << endl;
        cout << Wypisz(1,1,3,4) << endl;

    cout << Wypisz(1,1,3,5) << endl;

    cout << Wypisz(1,1,3,10) << endl;
    return 0;
}

int Wypisz (int p, int pp, int k, int maks){
    if (k <= maks) return Wypisz(p+pp, p, k+1, maks);
    return p;
    //cout << "Wypisz x i y: " << *x << " " << *y << endl;
}