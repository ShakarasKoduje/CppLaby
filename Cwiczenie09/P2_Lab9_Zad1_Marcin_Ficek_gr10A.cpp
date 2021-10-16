#include <iostream>

#include <string>

using namespace std;

class Piatka{
    public:
    Piatka() {};
    ~Piatka() {};

    template <typename T>
    T znajdzMinimum(T arr[], int n){
        T wynik = arr[0];
        for(int i = 1; i <n; i++){
            if(wynik > arr[i]) wynik = arr[i];
        }
        return wynik;
    }
    template <typename T>
    T znajdzMaksimum(T arr[], int n){
        T wynik = arr[0];
        for(int i = 1; i <n; i++){
            if(wynik < arr[i]) wynik = arr[i];
        }
        return wynik;
    }


    //sortowanie babelkowe

    template <typename T>
    void sortowanie(T arr[], int n){
        for (int i = 0; i <n; i++)
            for (int j = n-1; i < j; j--)
                if (arr[j] < arr[j - 1]){
                    swap(arr[j], arr[j - 1]);
                }
    }
    
    template <typename T>
    T znajdzSrodkowa(T arr[], int n){
        return arr[n/2];
    }
    template <typename T>
    T znajdzDruga(T arr[]){
        return arr[1];
    }
    template <typename T>
    T znajdzPrzedostatnia(T arr[], int n){
        return arr[n-1];
    }

};



int main(){
    Piatka piatkaST; int N = 5;
    int arrint[N] = {12, 3, 11, 8, 1};
    double arrdb[N] = {123.21, -989.32, 1.0002, 123.321};
    string arrstr[5] = {"k", "s", "t", "j", "o"};
        
    char arrchar[5] = {'o', 'z', 'a', 'y', 'w'};
    piatkaST.sortowanie(arrint, N);
    piatkaST.sortowanie(arrdb, N);
    piatkaST.sortowanie(arrstr, N);
    piatkaST.sortowanie(arrchar, N);

    cout <<endl << "STATYCZNIE" <<endl;
    cout<<"DLA INT: " <<endl;
    cout  << "MIN: " << piatkaST.znajdzMinimum(arrint, N)<< endl;  
    cout << " MAX: "<< piatkaST.znajdzMaksimum(arrint, N)<< endl;
    cout <<"znajdz srodkowa " << piatkaST.znajdzSrodkowa(arrint, N) <<endl;
    cout <<"znajdz druga " << piatkaST.znajdzDruga(arrint) <<endl;
    cout <<"znajdz przedostatnia " << piatkaST.znajdzPrzedostatnia(arrint, N) <<endl;

    cout<<"DLA DOUBLE: " <<endl;
    cout << "MIN: " << piatkaST.znajdzMinimum(arrdb, N)<< endl;  
    cout << " MAX: " <<piatkaST.znajdzMaksimum(arrdb, N)<< endl;
    cout <<"znajdz srodkowa " << piatkaST.znajdzSrodkowa(arrdb, N) <<endl;
    cout <<"znajdz druga " << piatkaST.znajdzDruga(arrdb) <<endl;
    cout <<"znajdz przedostatnia " << piatkaST.znajdzPrzedostatnia(arrdb, N) <<endl;
    cout<<"DLA STRING: " <<endl;
    cout  << "MIN: " << piatkaST.znajdzMinimum<string>(arrstr, N)<< endl;  
    cout << " MAX: "<< piatkaST.znajdzMaksimum<string>(arrstr, N)<< endl;
    cout <<"znajdz srodkowa " << piatkaST.znajdzSrodkowa<string>(arrstr, N) <<endl;
    cout <<"znajdz druga " << piatkaST.znajdzDruga<string>(arrstr) <<endl;
    cout <<"znajdz przedostatnia " << piatkaST.znajdzPrzedostatnia(arrint, N) <<endl;
    cout<<"DLA CHAR: " <<endl;
    cout  << "MIN: " << piatkaST.znajdzMinimum(arrchar, N)<< endl;  
    cout << " MAX: "<< piatkaST.znajdzMaksimum(arrchar, N)<< endl;
    cout <<"znajdz srodkowa " << piatkaST.znajdzSrodkowa(arrchar, N) <<endl;
    cout <<"znajdz druga " << piatkaST.znajdzDruga(arrchar) <<endl;
    cout <<"znajdz przedostatnia " << piatkaST.znajdzPrzedostatnia(arrchar, N) <<endl;

    //DYNAMICZNIE
    Piatka *piatkaDN = new Piatka;
    int arrint2[N] = {121,13, 101, 8, 147}; 
    double arrdb2[N] = {1213.21, -9289.32, 12.0002, -123.321};
    string arrstr2[N] = {"a", "c", "t", "d", "o"};
        
    char arrchar2[N] = {'i', 'z', 'f', 'y', 'b'};


    piatkaDN->sortowanie(arrint2, N);
    piatkaDN->sortowanie(arrdb2, N);
    piatkaDN->sortowanie(arrstr2, N);
    piatkaDN->sortowanie(arrchar2, N);

    cout <<endl << "DYNAMICZNIE" <<endl;
    cout<<"DLA INT: " <<endl;
    cout  << "MIN: " << piatkaDN->znajdzMinimum(arrint2, N)<< endl;  
    cout << " MAX: "<< piatkaDN->znajdzMaksimum(arrint2, N)<< endl;
    cout <<"znajdz srodkowa " << piatkaDN->znajdzSrodkowa(arrint2, N) <<endl;
    cout <<"znajdz druga " << piatkaDN->znajdzDruga(arrint2) <<endl;
    cout <<"znajdz przedostatnia " <<piatkaDN->znajdzPrzedostatnia(arrint2, N) <<endl;

    cout<<"DLA DOUBLE: " <<endl;
    cout << "MIN: " << piatkaDN->znajdzMinimum(arrdb2, N)<< endl;  
    cout << " MAX: " <<piatkaDN->znajdzMaksimum(arrdb2, N)<< endl;
    cout <<"znajdz srodkowa " << piatkaDN->znajdzSrodkowa(arrdb2, N) <<endl;
    cout <<"znajdz druga " << piatkaDN->znajdzDruga(arrdb2) <<endl;
    cout <<"znajdz przedostatnia " << piatkaDN->znajdzPrzedostatnia(arrdb2, N) <<endl;
    cout<<"DLA STRING: " <<endl;
    cout  << "MIN: " << piatkaDN->znajdzMinimum<string>(arrstr2, N)<< endl;  
    cout << " MAX: "<< piatkaDN->znajdzMaksimum<string>(arrstr2, N)<< endl;
    cout <<"znajdz srodkowa " << piatkaDN->znajdzSrodkowa<string>(arrstr2, N) <<endl;
    cout <<"znajdz druga " << piatkaDN->znajdzDruga<string>(arrstr2) <<endl;
    cout <<"znajdz przedostatnia " << piatkaDN->znajdzPrzedostatnia<string>(arrstr2, N) <<endl;
    cout<<"DLA CHAR: " <<endl;
    cout  << "MIN: " << piatkaDN->znajdzMinimum(arrchar2, N)<< endl;  
    cout << " MAX: "<< piatkaDN->znajdzMaksimum(arrchar2, N)<< endl;
    cout <<"znajdz srodkowa " << piatkaDN->znajdzSrodkowa(arrchar2, N) <<endl;
    cout <<"znajdz druga " << piatkaDN->znajdzDruga(arrchar2) <<endl;
    cout <<"znajdz przedostatnia " << piatkaDN->znajdzPrzedostatnia(arrchar2, N) <<endl;

    delete piatkaDN;

    return 0;
}

/*

Laboratorium 9.

Zadanie 1.

Zdefiniuj klasę Piatka, a w niej umieść:
1. szablon metody znajdzMinimum(). 
Metoda ta ma:
- określać wartość minimalną sposród pięciu wartości wprowadzonych za pomocą jej parametrów;
- działać dla obiektów utworzonych statycznie oraz dynamicznie;
- generować poprawne wyniki dla typów:
    --stałopozycyjnych, 
    --zmiennoprzecinkowych, 
    --znakowych,  
    --napisowych.

2. szablon metody znajdzMaximum(). 
Metoda ta ma:
- określać wartość maksymalną sposród pięciu wartości wprowadzonych za pomocą jej parametrów;
- działać dla obiektów utworzonych statycznie oraz dynamicznie;
- generować poprawne wyniki dla typów:
    --stałopozycyjnych, 
    --zmiennoprzecinkowych, 
    --znakowych,  
    --napisowych.

3. szablon metody znajdzSrodkowa(). 
Metoda ta ma:
- określać wartość środkową (trzecią z kolei ustawioną w porządku malejącym (lub rosnącym)) 
sposród pięciu wartości wprowadzonych za pomocą jej parametrów;
(przyjmij założenie, że żadna z wprowadzonych warości się nie powtarza);
- działać dla obiektów utworzonych statycznie oraz dynamicznie;
- generować poprawne wyniki dla typów:
    --stałopozycyjnych, 
    --zmiennoprzecinkowych, 
    --znakowych,  
    --napisowych.

4. szablon metody znajdzDruga(). 
Metoda ta ma:
- określać wartość drugą z kolei ustawioną w porządku rosnącym (lub czwartą w porządku malejącym)
sposród pięciu wartości wprowadzonych za pomocą jej parametrów;
(przyjmij to samo założenie, jak w pkt.3);
- działać dla obiektów utworzonych statycznie oraz dynamicznie;
- generować poprawne wyniki dla typów:
    --stałopozycyjnych, 
    --zmiennoprzecinkowych, 
    --znakowych,  
    --napisowych.

5. szablon metody znajdzPrzedostatnia(). 
Metoda ta ma:
- określać wartość drugą z kolei ustawioną w porządku malejącym (lub czwartą w porządku rosnącym)
sposród pięciu wartości wprowadzonych za pomocą jej parametrów;
(przyjmij to samo założenie, jak w pkt.3);
- działać dla obiektów utworzonych statycznie oraz dynamicznie;
- generować poprawne wyniki dla typów:
    --stałopozycyjnych, 
    --zmiennoprzecinkowych, 
    --znakowych,  
    --napisowych.

6. W funkcji main() przetestuj poprawność działania wszystkich metod.



*/