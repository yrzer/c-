// System ewidencji pracowników  Dodawanie, usuwanie, edycja pracowników oraz wyświetlenie całej listy. Pracownik składać się ma z imienia, nazwiska, stanowiska, rodzaju umowy, pensji brutto. Kalkulator na następnej lekcji
#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;
struct struktura{
	string imie, nazwisko;
    string stanowisko;
    string umowa; // na czas próbny, na czas określony, na czas nieokreślony, na czas wykonywania określonej pracy, na zastępstwo.
    float pensja; // 1999.99
};
    int lp_a = 1; // liczba pracowników
    int lp_b = 0; // realna liczba
    bool a_main = false;
    struktura *p = new struktura[lp_a];
    int *w=new int;
    void panel(){ cout << "| 1: dodawanie | 2: usuwanie |\n| 3: edycja   | 4: lista |"<< endl; };
// koniec stałych deklaracji  

int lista(){
cout<< "lista"<<endl;
for(int i=0; i<lp_b;i++){
cout<< "pracownik nr"<< i+1 <<endl;
cout<< p[i].imie <<endl;
cout<< p[i].nazwisko <<endl;
cout<< p[i].stanowisko <<endl;
cout<< p[i].umowa <<endl;
cout<< p[i].pensja <<endl;
}return 0;}
void full(){ 
delete w; w=new int;
cout << "pamiętaj tym razem dobrze. obecnie: "<<lp_a<<"\nile chcesz całościowo mieć użytkowników"<<endl;cin>>*w;
lp_a = *w;
struktura *q = new struktura[lp_a];
for(int i=0; i<lp_b;i++){
    cout<<"id przepisane: ";
q[i].imie       = p[i].imie ;
q[i].nazwisko   = p[i].nazwisko ;
q[i].stanowisko = p[i].stanowisko ;
q[i].umowa      = p[i].umowa ;
q[i].pensja     = p[i].pensja;
    cout<<i+1<<endl;
}
delete[] p;
p = new struktura[lp_a];
*p=*q;
lista();
delete[] q;
}
int dodawanie(){

    if(lp_a==(lp_b)){// przepełnienie
        cout << "zadużo użytkowników, chcesz dodać następne miejsca?\n| 1:tak| inne:nie |"<<endl;
        cin>>*w;
        switch (*w){
        case 1:// jeszcze jeden
// nie działa poniewasz źle przepisuje string            full();
        cout << "error"<<endl;

        //    break;
        default: //case 0
          delete w; w=new int;  return 0;
        };
    };

cout<< "dodawanie i zapisywanie pracownika do listy id:"<< lp_b+1 <<endl; 

cout<< "imie:"<<endl;
cin >> p[lp_b].imie;
cout<< "nazwisko:"<<endl;
cin >> p[lp_b].nazwisko;
cout<< "stanowsko:"<<endl;
cin >> p[lp_b].stanowisko;
cout<< "umowa:"<<endl;
cin >> p[lp_b].umowa;
cout<< "pensja:"<<endl;
cin >> p[lp_b].pensja;

lp_b++;
cout<< "jeszcze jeden pracownik?\n| 1:tak | inne:nie |:"<<endl;
cin>>*w;
switch (*w){
        case 1:// jeszcze jeden
            return dodawanie();
        default: //case 0
          delete w; w=new int;  return 0;
        };
}
void edycja(){//edycja
    cout<< "liczba id:"<< lp_b << " edycja pracownika nr?:"<< endl; int id_p; cin>>id_p; id_p--;
    ed_w:
    cout << "| 1: imie | 2: nazwisko |\n| 3: stanowski  | 4: umowa | 5: pensja |"<< endl;cin>>*w;
    switch (*w){
        case 0:// admin
            cout <<"error\n";delete w; w=new int; goto ed_w;  break; // potwier();  break;
        case 1:// imie
        cout << "zmień na imie"<<endl;
            cin >> p[id_p].imie; break;
        case 2:// nazwisko
        cout << "zmień na nazwisko"<<endl;
            cin >> p[id_p].nazwisko; break;
        case 3:// stanowisko
        cout << "zmień na stanowisko"<<endl;
            cin >> p[id_p].stanowisko; break;
        case 4:// umowa
        cout << "zmień na umowa"<<endl;
            cin >> p[id_p].umowa; break;
        case 5:// pensja
        cout << "zmień na pensja"<<endl;
            cin >> p[id_p].pensja; break;
        default: //case 1 - dodawanie
           cout <<"error\n";delete w; w=new int; goto ed_w;  break;
        };
    cout<< "jeszcze jedena edycja pracownik?\n| 1:tak | 2:inny pracownik | inne:nie |:"<<endl;cin>>*w;
    switch (*w){
    case 1:// jeszcze jeden
        goto ed_w;
    case 2:// jeszcze jeden
        edycja();
    default: //case 0
      delete w; w=new int;  break;}
}
void usuwanie(){ /// usuwanie

cout << "liczba prcowników wpisanych - "<<lp_b<<";\npracownik  do usunięcia z id?:"<< endl;
 int id_p; cin>>id_p; id_p--;
struktura *q = new struktura[lp_a];
for(int i=0; i<lp_b;i++){
    if(i!=id_p){
        cout<<"id zapisane: "<<i<<endl;
q[i].imie       = p[i].imie ;
q[i].nazwisko   = p[i].nazwisko ;
q[i].stanowisko = p[i].stanowisko ;
q[i].umowa      = p[i].umowa ;
q[i].pensja     = p[i].pensja ;};}
p=q;
delete[] q;
lp_b--;

}

int main(){//// main
if(a_main==false){a_main=true;
    cout<< "ile masz ogułem pracowników :"<<endl;
    delete[] p;
    cin>> lp_a;
    p = new struktura[lp_a];
dodawanie();}
panel();
cin>> *w;
switch (*w){
        case 0:// admin
            // potwier();  break;
        case 2:// usuwanie
            usuwanie();  break;
        case 3:// edycja
            edycja();  break;
        case 4:// admin
           lista();  break;
        default: //case 1 - dodawanie
           delete w; w=new int; dodawanie();  break;
        };
        
system("pause");
    return main();
}