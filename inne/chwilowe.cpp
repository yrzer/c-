#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>  
using namespace std;
int a,b,suma,wybor;
int *wsk_a = &a;
int *wsk_b = &b;

void wynik_1(){
cout << "dodawanie"<<endl;
suma = (*wsk_a) + (*wsk_a);
cout << "wynik - "<<suma<<endl<<endl;
};
void wynik_2(){
cout << "odejmowanie"<<endl;
suma = (*wsk_a) - (*wsk_a);
cout << "wynik - "<<suma<<endl<<endl;
};
void wynik_3(){
cout << "mnożenie"<<endl;
suma = (*wsk_a) * (*wsk_a);
cout << "wynik - "<<suma<<endl<<endl;
};
void wynik_4(){
cout << "dzielenie"<<endl;
suma = (*wsk_a) / (*wsk_a);
cout << "wynik - "<<suma<<endl<<endl;
};
void wynik_5(){
cout << "reszta z dzilenia"<<endl;
cout << "wynik - "<<suma<<endl<<endl;
suma = (*wsk_a) % (*wsk_a);
};
void wynik_6(){
    wynik_4();
    wynik_5();
};
void wynik(){
    wynik_1();
    wynik_2();
    wynik_3();
    wynik_4();
    wynik_5();
};

int main(){
cout << "1:dodawanie"<<endl;
cout << "2:odejmowanie"<<endl;
cout << "3:mnożenie"<<endl;
cout << "4:dzielenie"<<endl;
cout << "5:reszta z dzilenia"<<endl;
cout << "6:reszta z dzilenia z dzieleniem"<<endl;
cout << "wybor ="<<endl;
cin >> wybor;
cout << "wprowadź liczbe ";
cin >> a;
cout << "wprowadź liczbe ";
cin >> b;

switch (wybor){
    case 1:
        wynik_1();
        break;
    case 2:
        wynik_2();
        break;
    case 3:
        wynik_3();
        break;
    case 4:
        wynik_4();
        break;
    case 5:
        wynik_5();
        break;
    case 6:
    wynik_6();
        break;
    default:
        wynik();
        break;
}


    system("pause");
    return main();
}