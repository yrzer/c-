// zadanie.gra
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime> 
#include <cstdio>
#include <Windows.h>
#include <fstream>
#include <conio.h>

using namespace std;

void zasady() { // zasady gry
    cout << " Gracz z najwyzsza suma punktow - wygrywa runde \n ilosc round - 6 // specjalnie dałem 2 rundy bo za duża się wyświetla \n remis w rundzie - powtarzanie rundy tylko remisowych \n Zasady - \n Gracz ktory uzyska szostke na obu kostkach ma  mozliwosc dodatkowego rzutu  koscmi w tej samej rundzie i dodaje do calego wyniku z rundy \n Gracz ktoremu na obu kostkach wypadnie wynik parzysty moze dodac + 1 do wyniku \n Gracz ktoremu wypadną dwie jedynki otrzymuje w tej rundzie 0 punktow  \n  \n \n";}
void w_t_p() { // wytłumaczenie tabeli player
    cout << "tabela zrobiona jako pokaz zrobiona zmiennej player tu akurat na 3 graczy na 8 miejsc\n0 123456 7 \n0 123456 7 \n0 123456 7 \n0 - gracz i enterów jest 2-4 \n1-6 - rundy i zapisane wyniki graczy (w karzdej rundzie osobny  wynik(- suma wyrzuconych oczek w dwóch kostkach))\n7 - suma wygranych rund w X obok siebie\n // specjalnie dałem 2 rundy bo za duża się wyświetla\n";}
void autorzy() { // informacje na temat autorów
    cout << "\n zespol Timon i Pumba company \n czlonkowie: \n Timon - kosiara2015 (Bartek Zebrowski) \n Pumba - yrzer (Grzegorz Szczepkowski) \n  \n "<< endl;}
int rzut() // funkcja rzucenia kostką 
{    
	int w_kostka;
    int wk_r_suma; // w_kostka rzut suma
	cout << "wartosci wylosowane przez magiczna kostke: ";
	srand(time(NULL));
	for (int i = 0; i < 2; i++) 
    {
		w_kostka = rand() % 6 + 1;
		cout << w_kostka << "  ";
        wk_r_suma = wk_r_suma + w_kostka;
	}
    return wk_r_suma;
}

int game_over(int wynik){ // menu końca gry
    cout << " \n";
    cout << " wynik = " << wynik << endl;
    cout << " koniec \n | 1:exit | 2:restart <error> | = \n";
    int endgame;
    cin >> endgame;
        switch (endgame){
            case 1:
                system("pause");
                return wynik;
                break;
            case 2:
                // error
                break;
                default:
                cout << " error \n";
                return game_over(wynik);
                break;
        }
    return 0;}
int l_g()
{ // liczba graczy zmienna
    int liczba_graczy;
	cout << "ile jest graczy: ";
	cin >> liczba_graczy; 
	if (liczba_graczy < 5 && liczba_graczy > 1){
	        cout << "spoko mozesz gra \n wpisz nicki: \n";
            return liczba_graczy;
	    }
	else{
	        cout << "NO TY CHYBA SOBIE JAJA ROBISZ, NIE GRASZ ZDRADZIECKA KURWO \n";
            return l_g();
    }
}
/* string nik_name(int liczba_graczy){
    string player[liczba_graczy];
    for(int i=0; liczba_graczy > i; i++){
        cout << " \n wpisz nazwe gracza nr "<< i + 1 << ": ";
        cin >> player[i];
    }
if (liczba_graczy==2)
{
    return player[0],player[1];
}
else if (liczba_graczy==3)
{
    return player[0],player[1],player[2];
}
else
{
   return player[0],player[1],player[2],player[3]; 
}

    
}
*/
int start(){
    // zabiera liczbe graczy
  int liczba_graczy = l_g();
  // zbiera nicki graczy
  string player[liczba_graczy][8]; // dugi wymiar po rundy // trzeci wybar zapisuje sume wygranych więc ruda musi mieć 0
    for (int i = 0; i < liczba_graczy; i++){
        cout << i+1 << " player = ";
        cin >> player[i][0];
    } // potwierdza liczbe i nicki graczy
    for (int i = 0; i < liczba_graczy; i++){
        cout << i+1 << "  player = ";
        cout << player[i][0] << " ";
    }
Sleep(2000); // odczekanie sekundy
cout << " \n \n";

for(int i=1; i<3;i++){ // symulowanie rundy musi być 7 :) // specjalnie dałem 2 rundy bo za duża się wyświetla // specjalnie dałem 2 rundy bo za duża się wyświetla
int r = i; //jaka runda 1 
cout << "|| runda nr "<< r << " ||\n \n";
Sleep(500);
for(int i=0; i<liczba_graczy;i++){// symulowanie rzutów graczy 
int jp = i; 
cout << "gracz nr "<< jp+1  // jaki gracz/player 0 czyli 1 
<< " - " << player[jp][0] << endl;// musin być zero bo to jest lina gracza w tabeli
cout << "symulowanie rzutem podwujnej kosci ...\n";
Sleep(2000); // odczekanie sekundy
player[jp][r] = // zapisywanie w tabeli
rzut(); // zwraca liczbe wyrzuconych oczek
cout << " \n \n";
Sleep(2000); // odczekanie sekundy
}
cout << "runde wygral - ";
Sleep(500);
//pokazywanie wygranego
/* if // i dlaczego nie działa
// nie działa poniewarz player jest stringeim/tekstem więc nie można porównać
// X dlatego dodaje poniewarz (player jest stringeim/tekstem) zaznacza wygracne za pomocą ile jest X
// teoria z x taka że można odczytać to jako liczbe podzielić to naka to jest liczba i wyśietlić jako ilczbe wygranych 
// -- kończe dlatego bo nie mam neta żeby sprawdzić jak to zrobić i skonsultować z bartkiem
if(player[0][r]>player[1][r] && player[0][r]>player[2][r] && player[0][r]>player[3][r]){    
     player[0][7] = player[0][7] + 'x'; 
     cout<< player[0][0] << "\n \n";
}
else if (player[1][r]>player[0][r] && player[1][r]>player[2][r] && player[1][r]>player[3][r]){
     player[1][7] = player[1][7] + 'x';
     cout << "runde wygral - "<< player[1][0] << "\n \n";
}
else if (player[2][r]>player[0][r] && player[2][r]>player[1][r] && player[2][r]>player[3][r]){
     player[2][7] = player[2][7] + 'x';
     cout << "runde wygral - "<< player[2][0] << "\n \n";
}
else{
    player[3][7] = player[1][7] + 'x';
     cout << "runde wygral - "<< player[3][0] << "\n \n";
}
*/
cout << "\n";
Sleep(2000); // odczekanie sekundy
}

//    return wynik[]
}
int main() // działanie gry
{
    cout << "-- gra kosciana :D || play:1 | zasady:2 | autorzy:3 | ?:4 || --\n   liczba: ";
    int menu;
    cin >> menu;
    switch (menu)
    {
    case 1:
        cout << " start \n";
        start();// specjalnie dałem 2 rundy bo za duża się wyświetla
        break;
    case 2:
        zasady();
        main();
        break;
    case 3:
        autorzy();
        main();
        break;
    case 4:
        w_t_p();
        main();
        break;
    default:
        cout << " error \n";
        return main();
        break;
    }
    
Sleep(1000); // odczekanie sekundy
    int wynik = 1;
    return game_over(wynik);
    return 0; // tu może być zapisywanie wyniku ponieważ jeszcze widnieje tu
}
// system("chcp 65001");
// if(wynik == 0) cout << "poprzedni wynik: "<< wynik << endl;
// char 32 to spacja
