#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>  
using namespace std;
int wybor,a=3;
string produkty_nazwa[a] = {"soczek","batonik","cola/pepsi"};
double produkty_cena[a] = {0.99,2.5,2.99};
int main(){
cout << "produkty - ";
    for(int i = 0;i<a;i++;){
        cout << 1;
    }
cin >> wybor;
switch (wybor)
{
case 1:
    
    break;
default:

    break;
} 


    system("pause");
    return main();
}
/*
1 dodaj produkty
2 usuń produkty
3 wyświetlanie produktów
• nazwa cena

-- portfel

*/