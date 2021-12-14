#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>  
using namespace std;

int main(){
    int n;
    cin >> n;
    int *tab = new int[n];  
    srand( time( NULL ) );
    for(int i=0; i<n; i++){
        tab[i]= rand() % 100 + 1;
    }
     for(int i=0; i<n; i++){
        cout<< tab[i] <<endl;
    }
    cout<< "delete" <<endl;
    delete [] tab;
    Sleep(5000);
    for(int i=0; i<n; i++){
        cout<< tab[i] <<endl;
    }
    system("pause");
    return main();
}