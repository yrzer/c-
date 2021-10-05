// zadanie.gra
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
using namespace std;

void zasady() { // zasady gry
setlocale(LC_CTYPE, "Polish");
cout << " " << endl;
cout << "Gracz z najwyższą sumą punktów - wygrywa rundę " << endl;
cout << "rund - 6 " << endl;
cout << "remis w rundzie - powtarzanie rundy tylko remisowych " << endl;
cout << "Zasady + " << endl;
cout << "Gracz który uzyska szóstkę na obu kostkach ma  możliwość dodatkowego rzutu  kośćmi w tej samej rundzie i dodaje do całego wyniku z rundy " << endl;
cout << "Gracz któremu na obu kostkach wypadnie wynik parzysty może dodać + 1 do wyniku " << endl;
cout << "Gracz któremu wypadną dwie jedynki otrzymuje w tej rundzie 0 punktów " << endl;
cout << " " << endl;
}
void autorzy() { // informacje na temat autorów
    setlocale(LC_CTYPE, "Polish");
    cout << " " << endl;
    cout << " zespół Timon i Pumba company " << endl;
    cout << " członkowie: " << endl;
    cout << "    timon - kosiara2015 (bartek żebrowski)  " << endl;
    cout << "   pumba - yrzer (grzegorz szczepkowski)" << endl;
    cout << " " << endl;
}

int rzut() {    // funkcja rzucenia kostką
	setlocale(LC_CTYPE, "Polish");

	int w_kostka;	
	cout << "wartości wylosowane przez magiczną kostke: ";
	srand(time(NULL));
	for (int i = 0; i < 2; i++) {
		w_kostka = rand() % 6;
		cout << w_kostka << "  ";
	}
    // return liczbe wyniku żucenia kością;
}

int game_over(int wynik) { // menu końca gry
    setlocale(LC_CTYPE, "Polish");
    cout << " " << endl;
    cout << " wynik = " << wynik << endl;
    cout << " koniec \n | 1:exit | 2:restart <error> | = " << endl;
    int endgame;
    cin >> endgame;
    switch (endgame)
    {
    case 1:
    system("pause");
    return wynik;
    break;
    case 2:
    // error
    break;
    default:
    cout << " error " << endl;
    return game_over(wynik);
    break;
    }
    return 0;
}
int l_g(){ // liczba graczy zmienna
    int liczba_graczy;
	cout << "ile jest graczy: ";
	cin >> liczba_graczy; 
	if (liczba_graczy < 5 && liczba_graczy > 1){
	        cout << "spoko możesz grać";
            return liczba_graczy;
	    }
	    else {
	        cout << "NO TY CHYBA SOBIE JAJA ROBISZ, NIE GRASZ ZDRADZIECKA KURWO \n";
            return l_g();
        }
}
string nik_name(int liczba_graczy){
    string player[4];
    for(int i=0; liczba_graczy<i; i++){
        cout << "wpisz nazwe gracza nr"<< i << endl;
        cin >> player[i];
    }
    return player[4];
}
int start(){
    string player[4];
        int liczba_graczy = l_g();
        nik_name(liczba_graczy);
        cout << " witajcie gracze \n" << player[1] << endl;
        cout << player[2] << endl;
        cout << player[3] << endl;
        cout << player[4] << endl;

        // return nawet nie wim
}
int main() // działanie gry
{
    // system("chcp 65001");
    setlocale(LC_CTYPE, "Polish");
    // if(wynik == 0) cout << "poprzedni wynik: "<< wynik << endl;
    cout << "gra kościana :D | play:1 | zasady:2 | autorzy:3 | ?:4 ||liczba:";
    int menu;
    cin >> menu;
    switch (menu)
    {
    case 1:
        cout << " start " << endl;
        start();
        break;
    case 2:
        zasady();
        main();
        break;
    case 3:
        autorzy();
        main();
        break;
    default:
        cout << " error " << endl;
        return main();
        break;
    }
    

    int wynik = 1;
    return game_over(wynik);
    return 0; // tu może być zapisywanie wyniku ponieważ jeszcze widnieje tu
}
