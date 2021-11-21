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
int wybor=0;
    for(int i=1;i<4;){
    
    wybor = los_atak();
    cout << i <<" "<< wybor<<endl;
    
    i++;Sleep(1);
    };
    system("pause");
    return main();
}