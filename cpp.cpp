#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>  
using namespace std;
int chwilowe;
int l=100;
int los_atak(){
    Sleep(1);
    
    chwilowe = rand() % 10 + 1;
cout << chwilowe << endl;
return chwilowe;
};

int main(){ 
  int sum, suma; 
  srand(time(NULL));
    while (l>0){
    suma = suma + los_atak();
    l--;
    sum++;
    }
    cout << sum << " " << suma << endl;
    system("pause");
    return main();
}