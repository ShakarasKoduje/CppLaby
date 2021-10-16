#include <iostream>


using namespace std;


class Pies{
    string imie = "Noname";
    string rasa = "Unkown";
    char plec = 'u';
    int wiek = 0;
    double waga = 0.0;
    float wielkosc = 0.0;
    
    public:
        //KONSTRUKTORY:
        Pies(){ 
            cout << "Powstał nieznany pies" << endl;
        }
        Pies(string Imie, string Rasa, char Plec, int Wiek, double Waga, float Wielkosc){
            this->setImie(Imie); this->setRasa(Rasa); this->setPlec(Plec); this->setWiek(Wiek); this->setWaga(Waga); this->setWielkosc(Wielkosc);
         }

        //gettery
        string getImie(){
            return this->imie;
        }
        string getRasa(){
            return this->rasa;
        }
        char getPlec(){
            return this->plec;
        }               
        int getWiek(){
            return this->wiek;
        }
        double getWaga(){
            return this->waga;
        }
        float getWielkosc(){
            return this->wielkosc;            
        }


        
        void getInfo(){
            string buffor;
            if (this->plec == 'm' ||this->plec == 'M' )
            {
                buffor = "pies";
            }
            else if(this->plec == 'f' ||this->plec == 'F'){
                buffor = "suka";
            }
            else buffor = "nieokreslonej plci pies";       
            cout << getImie() << " rasy " << getRasa() << " to " << buffor << " ma " << getWiek() << " lat i wazy" << getWaga() << " kg."<< endl;
        }
        //settery
        void setImie(string i){
            this->imie = i;
            cout << "Pies wabi sie: " << getImie() << endl;
        }
        void setRasa(string r){
            this->rasa = r;
            cout << "Pies " << getImie() <<" jest rasy " << getRasa() << endl;

        }
        void setPlec(char p){
            this->plec = p;
            cout << "Pies " << getImie() <<" to ";
            if (this->plec == 'm' ||this->plec == 'M' )
            {
                cout << "samiec." << endl;
            }
            else if(this->plec == 'f' ||this->plec == 'F'){
                cout << "suka." << endl; 
            }
            else cout << "nieokreslonej plci pies." << endl;        

        }               
        void setWiek(int w){
            if(w >= 0) this->wiek = w;
            else cout << "Wiek nie moze byc ujemny." << endl;
            cout << "Pies " << getImie() <<" ma" << getWiek() << " lat." << endl;

        }
        void setWaga(double w){
            if(w > 0.1) this->waga = w;
            else cout << "Waga nie moze byc ujemna." << endl;
            cout << "Pies " << getImie() <<" wazy" << getWaga() << " kg." << endl;

        }
        void setWielkosc(float w){
            if(w > 0.1) this->wielkosc = w;
            else cout << "Wielkosc nie moze byc ujemna." << endl;
            cout << "Pies " << getImie() <<" ma " << getWielkosc() << " cm." << endl;

        }

};


int main(){

    cout << "==============REKSIO================" << endl;
    Pies p1("Reksio", "kundel", 'M', 7, 10, 43);
    //cout << p1.getImie() << endl;
    p1.getInfo();
    cout << "===========BUREK=================" << endl;

    Pies p2("Burek", "jamnik", 'f', 3, 10.43, 27.45);

    p2.setWiek(5);
    cout << "===============ROLLO=======================" << endl;

    Pies p3;
    p3.getInfo();

    p3.setImie("Rollo"); p3.setRasa("Buldog"); p3.setPlec('m'); p3.setWiek(3); p3.setWaga(12.54); p3.setWielkosc(27.89);
    p3.getInfo();

    cout << "==============DESTROYER===============" << endl;


    Pies *p4 = new Pies("Destroyer", "Amstaf", 'm', 4, 50.13, 60.05);
    cout <<endl;
    cout << p4->getImie() << " ma " << p4->getWiek() << " lat." << endl;   
    p4->getInfo();

    p4->setWaga(69.01);
    delete p4;
    cout << "================================================================" << endl;

    return 0;
}

