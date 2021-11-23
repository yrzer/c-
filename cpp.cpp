#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>  
using namespace std;
int chwilowe;

int los_atak(){
    Sleep(100);
     srand(time(NULL));
    chwilowe = rand() % 4 + 1;
return chwilowe;
};

int main(){
string nazwa_boss = " czarno_ksieznik ";
    int liczba_znakow = nazwa_boss.size();
	
	cout<<"Podany ciąg składa się z "<<liczba_znakow<<" znaków.";
    system("pause");
    return main();
}