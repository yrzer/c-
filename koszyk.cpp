#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>  
using namespace std;
int wybor_1,wybor_2,a=3,ret=1;
double portfel=0.0;bool dne = true;
bool *koszyk = new bool[a];

struct regal {
    string nazwa;
    double cena;
    int ile;
};
regal *produkty = new regal[a];
void zapis(){
    for(int i=0;i<a;i++){
        koszyk[i]=false;
    } 
produkty[0].nazwa = "soczek";
produkty[0].cena = 0.99;

produkty[1].nazwa = "batonik";
produkty[1].cena = 2.5;

produkty[2].nazwa = "cola/pepsi";
produkty[2].cena = 2.99; 
}

int end_1(int i){ //
    if (koszyk[i]==true){
        double z_portfel = portfel; // zapas
        cout << (i+1) << " " << produkty[i].nazwa << ", " << produkty[i].cena <<endl;
        cout << "czy na pewno chcesz jedno? wybiez ile chcesz - " <<endl;
        cin >> produkty[i].ile;
        if(produkty[i].ile<1){
            cout <<"error - za malo \n"; end_1(i);
        }
        else if(produkty[i].ile>15){
            cout <<"error - za duzo\n"; end_1(i);
        }
        else{
            portfel -= produkty[i].ile*produkty[i].cena;
            if (portfel <= 0){
                portfel = z_portfel;// za malo to resetowanie jedejn z petli czyli 2 linijki wyzej
                cout << "za malo kasy \nchcesz zmienic:\n| 1:ilosc | 2:pordukty | - "; cin >> wybor_2;
                switch (wybor_2){
                case 1:
                    cout <<endl; end_1(i);
                    break;
                case 2:
                    return 0;
                    break;
                default:
                    cout <<"error\n"; end_1(i);
                    break;
                }
            };
            cout<<"\n";}
    return 1;
    };}

void end(){
    cout << "podsumowanie koszyka\nmam:\n";
    ret=1;
    for(int i=0; i<a;i++){
        ret = end_1(i);
        if(ret==0){i=a+1;};
}
if(ret==1){
    system("cls");
    cout << "zostalo ci w portfelu "<< portfel << "kupiles:"<<endl;
    for(int i=0;i<a;i++){
        if(koszyk[i]==true){
        cout << produkty[i].nazwa <<" w ilosci " << produkty[i].ile <<endl;
};};};

}

void z_koszyk(){ // zapis koszyk
if(wybor_1<=a){
koszyk[wybor_1-1]= true;
cout << " usuwanie sie powiodlo\n";}
else{cout << "error"<<endl; z_koszyk();
}}

void d_koszyk(){ // dodawanie do koszyk
    cout << "produkty, cena :\n";
    for(int i = 0;i<a;i++){
        cout << (i+1) << " " << produkty[i].nazwa << ", " << produkty[i].cena <<endl;
    };
cout << "wybierz 1,2,3... - ";
cin >> wybor_1; z_koszyk();
}

void main_2(){ // main 2           // poprostu
// system("cls");
cout << "chcesz?:\n| 1:dodac | 2:portfel | 3:podsumowanie |\n| 4:usunac poprzednie | 5: usun wybrane | \n";
cin >> wybor_2;
switch(wybor_2){

    case 1: // dodwanie do koszyka
        d_koszyk();
        break; 
    case 2:// portfel 
            cout << "stan - " << portfel << " zl\n";
        break; 
    case 3: // podsumowanie 
        end();//end
        if(ret==0){main_2();};
        dne = false;
        break;
    case 4: // usuwanie poprzedniej pozycji
        koszyk[wybor_1] =false;
        cout << " usuwanie sie powiodlo\n";
        break; 
    case 5: // usuwanie wybranej pozycji
        cin >> wybor_1;
        koszyk[wybor_1] =false;
        cout << " usuwanie sie powiodlo\n";
        break;
default: cout << "error"<<endl; main_2();break;}
}

int kasa_od_babci(){
    int kasa;
    kasa = rand() % 5 + 1;
    portfel = (double)kasa;
    return (kasa*5);}
int main(){
zapis();
cout << "witaj w sklepie \n";
 srand (time(NULL));
cout << "dostales od babci - "<< kasa_od_babci() <<" zl\ntylko nie mow mamie \n\n";
d_koszyk();
do{
main_2();
cout<<endl;
}while (dne == true);
cout << "ale toreb, wychodzisz ze sklepu \n";
    system("pause");
    return main();
}
/*
1 dodaj produkty
2 usun produkty
3 wyswietlanie produktow
• nazwa, cena

-- portfel

*/