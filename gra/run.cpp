// zadanie.gra
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>

using namespace std;

void zasady() { // zasady gry
    cout << " Gracz z najwyzsza suma punktow - wygrywa rundę \n ilosc round - 6 \n remis w rundzie - powtarzanie rundy tylko remisowych \n Zasady - \n Gracz ktory uzyska szostke na obu kostkach ma  mozliwosc dodatkowego rzutu  koscmi w tej samej rundzie i dodaje do calego wyniku z rundy \n Gracz ktoremu na obu kostkach wypadnie wynik parzysty moze dodac + 1 do wyniku \n Gracz ktoremu wypadną dwie jedynki otrzymuje w tej rundzie 0 punktow  \n  \n " << endl;
}

void autorzy() { // informacje na temat autorów
    cout << "\n zespol Timon i Pumba company \n czlonkowie: \n Timon - kosiara2015 (Bartek Zebrowski) \n Pumba - yrzer (Grzegorz Szczepkowski) \n  \n "<< endl;
}

int rzut() {    // funkcja rzucenia kostką

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
        case 2: // error
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
	cout << "\n ile jest graczy: ";
	cin >> liczba_graczy; 
	if (liczba_graczy < 5 && liczba_graczy > 1){
	        cout << " \n spoko mozesz grac \n ";
            return start();
	    }
	    else {
	        cout << "NO TY CHYBA SOBIE JAJA ROBISZ, NIE GRASZ ZDRADZIECKA KURWO \n \n ";
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
