#include <iostream>


using namespace std;

unsigned long int silnia (unsigned long int, unsigned long int);

int main(){
    cout << silnia(5,1);



    return 0;
}

unsigned long int silnia (unsigned long int x, unsigned long int tmp=1){

    if(x==0){
        return tmp;
    }
    else return silnia(x-1, x*tmp);

}