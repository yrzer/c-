#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

int main(){
int wybor;
cin>>wybor;
cout<< wybor << endl;
switch (wybor){
        case 0:// admin
            cout<<"admin";  break;
        case 2:
            cout<<"2";  break;
        case 3:
            cout<<"3";  break;
        case 4:
            cout<<"4";  break;
        case 5:
            cout<<"5";  break;
        default: //case 1;
            cout<<"0";  break;
        };
        wybor=0;
system("pause");
    return main();
}