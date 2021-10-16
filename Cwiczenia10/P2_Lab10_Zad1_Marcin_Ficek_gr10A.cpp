#include <iostream>
#include <vector>


using namespace std;

class Test
{
private:
    vector<int> v1{3,50,10};
    vector<int> v2{1,2,3,4};
    int tablica[5]={0};
    
public:

    void pokazelementy() {
        for(const auto &i : v1) cout << i << endl;
        cout << "\n\n==========================\n\n";
        for(const auto &i : v2) cout << i << endl;
    }
    void inicjalizujtablice(){
        for(int i = 0; i <=3; i++) {
        int a = (-1)*(i+1);
        tablica[i] = a;
    } 
    }

    void dadanieliczby() {
        v1.insert(v1.begin(), -50);
    }

    void dodaniejedynek() {
        for(int i = 1; i <=3; i++)v1.push_back(1);
    }

    void laczeniewektorow() {
        for(int i = 2; i >=0; i--){
            v1.insert(v1.begin()+1, v2[i]); // 2 pozycja, czyli indeks numer 1
        }
    }

    void dodajtablice() {
        for(int i = 0; i <=4; i++) {
            v1.push_back(tablica[i]);
        } 
    }

    void wymaz() {
        v1.erase(v1.begin() + 1, v1.end() - 1);
    }

    void zamien() {
        vector<int> tmp = v1;
        v1 = v2;
        v2 = tmp;
    }


};


int main(){
    cout <<"\n=========TEST STATYCZNY============\n";
    Test statyczny;
    statyczny.inicjalizujtablice();
    statyczny.dadanieliczby();
    statyczny.dodaniejedynek();
    statyczny.laczeniewektorow();
    statyczny.dodajtablice();
    statyczny.wymaz();
    statyczny.zamien();
    statyczny.pokazelementy();
    cout <<"\n============================\n";
    Test *dynamiczny = new Test;
    dynamiczny->inicjalizujtablice();
    dynamiczny->dadanieliczby();
    dynamiczny->dodaniejedynek();
    dynamiczny->laczeniewektorow();
    dynamiczny->dodajtablice();
    dynamiczny->wymaz();
    dynamiczny->zamien();
    dynamiczny->pokazelementy();
    delete dynamiczny;
    /*
    1. Utwórz pusty wektor przechowujący liczby typu int.
    2. Zarezerwuj pamięć na 3 elementy.
    3. Zainicjuj go wartościami: 3, 50, 10.
    4. Dodaj do wektora na jego początku liczbę: -50.
    5. Dodaj na końcu wektora 3 elementy o wartości: 1.
    */
    vector<int> v1(3); 
    v1.insert(v1.begin(),3);
    v1.insert(v1.begin()+1,50);
    v1.insert(v1.begin()+2,10);


    v1.insert(v1.begin(), -50);

    for(int i = 1; i <=3; i++)v1.push_back(1);

    vector<int> v2 {1,2,3,4};
    cout<<endl <<"==============" << endl;
    for(int i = 2; i >=0; i--){
        v1.insert(v1.begin()+1, v2[i]); // 2 pozycja, czyli indeks numer 1
    }

    int tablica[5]={0};
    for(int i = 0; i <=3; i++) {
        int a = (-1)*(i+1);
        tablica[i] = a;
    } 
    for(int i = 0; i <=4; i++) {
        v1.push_back(tablica[i]);
    } 
    //10. Usuń z pierwszego wektora wszystkie liczby oprócz pierwszej i ostatniej.

    v1.erase(v1.begin()+1, v1.end()-1);

    //for(const auto &i : v1) cout << i << endl;

    //11. Wykonaj operacje zamiany wektora pierwszego z drugim.
    vector<int> tmp = v1;
    v1 = v2;
    v2 = tmp;
    for(const auto &i : v1) cout << i << endl;
    cout<<"\n=====================\n";
    for(const auto &i : v2) cout << i << endl;  

    //Dynamicznie.
    cout<<"\n\n" << "DYNAMICZNIE" << endl;
    vector<int> *v1d = new vector<int>(3);
    //3. Zainicjuj go wartościami: 3, 50, 10.
    v1d->insert(v1d->begin(),3); v1d->insert(v1d->begin()+1,50); v1d->insert(v1d->begin()+2, 10);
    //4. Dodaj do wektora na jego początku liczbę: -50.
    v1d->insert(v1d->begin(), -50); 
    //5. Dodaj na końcu wektora 3 elementy o wartości: 1.
    for(int i = 1; i <=3; i++)v1d->push_back(1);


    //6. Utwórz kolejny wektor i wypełnij go wartościami:1, 2, 3, 4.
    vector<int> *v2d = new vector<int>();
    v2d->push_back(1); v2d->push_back(2); v2d->push_back(3); v2d->push_back(4); 
    //7. Dołącz do pierwszego wektora od 2 pozycji pierwsze 3 elementy drugiego wektora.
    for(int i = 2; i >=0; i--){
        
        v1d->insert(v1d->begin()+1, v2d->at(i)); // 2 pozycja, czyli indeks numer 1
    }
    //9. Dołącz do pierwszego wektora na jego końcu elementy tablicy utworzonej w kroku 8.
    for(int i = 0; i <=4; i++) {
        v1d->push_back(tablica[i]);
    } 
    //10. Usuń z pierwszego wektora wszystkie liczby oprócz pierwszej i ostatniej.
    v1d->erase(v1d->begin()+1, v1d->end()-1);


    //11. Wykonaj operacje zamiany wektora pierwszego z drugim.
    vector<int> *tmpD = v1d;
    v1d = v2d;
    v2d = tmpD;

    for(const auto &i : *v1d) cout << i << endl;
    cout<<"\n=====================\n";
    for(const auto &i : *v2d) cout << i << endl;
    delete v1d; delete v2d;

    //12. Przetestuj realizację pkt.1-11 w oparciu o obiekt statyczny oraz dynamiczny klasy Test.




    return 0;
}

/*
Laboratorium 10.

Zadanie 1.

1. Utwórz pusty wektor przechowujący liczby typu int.
2. Zarezerwuj pamięć na 3 elementy.
3. Zainicjuj go wartościami: 3, 50, 10.
4. Dodaj do wektora na jego początku liczbę: -50.
5. Dodaj na końcu wektora 3 elementy o wartości: 1.
6. Utwórz kolejny wektor i wypełnij go wartościami:1, 2, 3, 4.
7. Dołącz do pierwszego wektora od 2 pozycji pierwsze 3 elementy drugiego wektora.
8. Utwórz tablicę przechowującą pięć liczb typu int i zainicjuj ją wartościami: -1,-2,-3,-4.
9. Dołącz do pierwszego wektora na jego końcu elementy tablicy utworzonej w kroku 8.
10. Usuń z pierwszego wektora wszystkie liczby oprócz pierwszej i ostatniej.
11. Wykonaj operacje zamiany wektora pierwszego z drugim.
12. Przetestuj realizację pkt.1-11 w oparciu o obiekt statyczny oraz dynamiczny klasy Test.
*/