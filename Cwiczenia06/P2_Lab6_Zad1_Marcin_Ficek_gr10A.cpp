#include <iostream>
#include <cmath>

using namespace std;


class Wieloscian{
    protected:
        double dlugoscPodstawy, szerokoscPodstawy, wysokosc;

    public:
        void setDlugoscPodstawa(double dP){
            this->dlugoscPodstawy = dP;
        }
        void setSzerokoscPodstawy(double szP){
            this->szerokoscPodstawy = szP; 
        }
        void setWysokosc(double w){
            this->wysokosc = w;
        }


};

class Prostopadloscian: public Wieloscian{
    public:


        double Objetosc(){
            return this->dlugoscPodstawy * this->szerokoscPodstawy * this->wysokosc;

        } 
        double Pole(){
            return 2*(this->dlugoscPodstawy*this->szerokoscPodstawy) + 2*(this->dlugoscPodstawy*this->wysokosc) + 2*(this->szerokoscPodstawy*this->wysokosc);
        }


};

class Ostroslup: public Wieloscian{
    public:
        double objetosc(){
            return (this->dlugoscPodstawy*this->szerokoscPodstawy*this->wysokosc)/3;

        } 
        double pole(){
            double h1 =sqrt(this->wysokosc*this->wysokosc + (this->dlugoscPodstawy/2)*(this->dlugoscPodstawy/2));
            double t1 = this->dlugoscPodstawy/2 * h1;

            double h2 = sqrt(this->wysokosc*this->wysokosc + (this->szerokoscPodstawy/2)*(this->szerokoscPodstawy/2)); 
            double t2 =  this->szerokoscPodstawy/2 * h2;           
            return (this->dlugoscPodstawy*this->szerokoscPodstawy)+(2*t1+2*t2);
        }
};


int main(){

    Wieloscian *w = new Prostopadloscian;

    w->setSzerokoscPodstawy(8);

    Prostopadloscian p;
    Ostroslup o;

    Prostopadloscian *wskP = new Prostopadloscian;
    Ostroslup *wskO = new Ostroslup;

    p.setDlugoscPodstawa(3); p.setSzerokoscPodstawy(3); p.setWysokosc(8);
    cout <<"Prostopadloscian: V=" << p.Objetosc() << " Pc=" << p.Pole()<< endl;

    o.setDlugoscPodstawa(4); o.setSzerokoscPodstawy(4); o.setWysokosc(9);
    cout <<"Ostroslup: V=" << o.objetosc() << " Pc=" << o.pole()<< endl;

    wskP->setDlugoscPodstawa(11); wskP->setSzerokoscPodstawy(3); wskP->setWysokosc(18);
    cout <<"Prostopadloscian dynamiczny: V=" << wskP->Objetosc() << " Pc=" << wskP->Pole()<< endl;

    wskO->setDlugoscPodstawa(13); wskO->setSzerokoscPodstawy(17); wskO->setWysokosc(18);
    cout <<"Ostroslup dynamiczny: V=" << wskO->objetosc() << " Pc=" << wskO->pole()<< endl;
    
    
    delete(wskP); delete(wskO);


    return 0;
}

/*

Laboratorium 6.

Zadanie 1.

1. Zdefiniuj klasę Wieloscian (zawierającą pola: dlugoscPodstawy, szerokoscPodstawy, wysokosc 
(pola te nie mogą być publiczne);
mutatora umożliwiającego ustawianie danych wejściowych 
dla obiektów korzystających z klasy Wieloscian).

2. Zdefiniuj klasę Prostopadloscian- ma być ona klasą potomną względem klasy Wieloscian 
(zawierającą metody (publiczne) Objetosc() oraz Pole();
metody te powinny zwracać odpowiednio objętość oraz pole powierzchni prostopadlościanu).

3. Zdefiniuj klasę Ostroslup - ma być ona klasą potomną względem klasy Wieloscian 
(zawierającą metody (publiczne) objetosc() oraz pole();
metody te powinny zwracać odpowiednio objętość oraz pole powierzchni ostrosłupa o podstawie prostokąta).

4. W funkcji main() utwórz obiekty (w sposób statyczny oraz dynamiczny) klasy Prostopadloscian oraz Ostroslup 
i dokonaj obliczeń pola powierzchni oraz objętości odpowiednich figur. 
W oparciu o strumień wyjściowy wyświetl wyniki obliczeń w konsoli.

*/