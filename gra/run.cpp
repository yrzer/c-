// zadanie.gra
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime> 
#include <cstdio>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <sstream>
using namespace std;
// globalne zmienne
int liczba_graczy;
int z_rzut[4][8]; // rzuty kostką [4]- gracze ; [6]-rundy, [7]-wygrane rundy
string player[4][8]; // dugi wymiar po rundy // trzeci wybar zapisuje sume wygranych więc ruda musi mieć 0
int rzut_k() // funkcja rzucenia kostką 
{    
	int w_kostka;
    int wk_r_suma = 0; // w_kostka rzut suma
	cout << "wartosci wylosowane przez magiczna kostke: ";
	srand(time(NULL));
	for (int i = 0; i < 2; i++) 
    {
		w_kostka = rand() % 6 + 1;
		cout << w_kostka << "  ";
        wk_r_suma = wk_r_suma + w_kostka;
	}
    cout << "  suma - ";
    return wk_r_suma;
}
void wg_r(int r){
    if (z_rzut[0][r] > z_rzut[1][r] && z_rzut[0][r] > z_rzut[2][r] && z_rzut[0][r] > z_rzut[3][r]) {
			cout << "wygral: " << player[0][0] << endl;
			z_rzut[0][7] = z_rzut[0][7] + 1;
		}
		else if (z_rzut[1][r] > z_rzut[0][r] && z_rzut[0][r] > z_rzut[2][r] && z_rzut[0][r] > z_rzut[3][r]) {
			cout << "wygral: " << player[1][0] << endl;
			z_rzut[1][7] = z_rzut[1][7] + 1;
		}
		else if (z_rzut[2][r] > z_rzut[1][r] && z_rzut[0][r] > z_rzut[0][r] && z_rzut[0][r] > z_rzut[3][r]) {
			cout << "wygral: " << player[2][0] << endl;
			z_rzut[2][7] = z_rzut[2][7] + 1;
		}
		else if (z_rzut[3][r] > z_rzut[1][r] && z_rzut[0][r] > z_rzut[2][r] && z_rzut[0][r] > z_rzut[0][r]) {
			cout << " wygral: " << player[3][0] << endl;
			z_rzut[3][7] = z_rzut[3][7] + 1;
		}
}
void s_r_g(int r,int i){// symulowanie rzutów graczy  
    cout << "gracz nr "<< i+1  // jaki gracz/player 0 czyli 1 
    << " - " << player[i][0] << endl; // musin być zero bo to jest lina gracza w tabeli
    cout << "symulowanie rzutem podwujnej kosci ...\n";
    Sleep(2000); // odczekanie sekundy
    z_rzut[i][r] = rzut_k();
    cout << z_rzut[i][r] << " \n \n"; // i gracze r rozgrywak
    Sleep(500);
Sleep(1000); // odczekanie sekundy
}
void sprawdzenie_if(int r){
    if (z_rzut[0][r] == z_rzut[1][r]) {
			cout << "Remis " << player[0][0] << " miedzy " << player[1][0] << "\nGracze zaczynaja jeszcze raz" << endl;
			cout << "rzuca gracz: " << player[0][0] << endl;
			z_rzut[0][r] = rzut_k();
			cout << "wynik rzutu = " << z_rzut[0][r] << endl;
			Sleep(700);
			cout << "rzuca gracz: " << player[1][0] << endl;
			z_rzut[1][r] = rzut_k();
			cout << "wynik rzutu = " << z_rzut[1][r] << endl;
			Sleep(700);
		}
		else if (z_rzut[0][r] == z_rzut[2][r]) {
			cout << "Remis " << player[0][0] << " miedzy " << player[2][0] << "\nGracze zaczynaja jeszcze raz" << endl;
			cout << "rzuca gracz: " << player[0][0] << endl;
			z_rzut[0][r] = rzut_k();
			cout << "wynik rzutu = " << z_rzut[0][r] << endl;
			Sleep(700);
			cout << "rzuca gracz: " << player[2][0] << endl;
			z_rzut[2][r] = rzut_k();
			cout << "wynik rzutu = " << z_rzut[2][r] << endl;
			Sleep(700);
		}
		else if (z_rzut[0][r] == z_rzut[3][r]) {
			cout << "Remis " << player[0][0] << " miedzy " << player[3][0] << "\nGracze zaczynaja jeszcze raz" << endl;
			cout << "rzuca gracz: " << player[0][0] << endl;
			z_rzut[0][r] = rzut_k();
			cout << "wynik rzutu = " << z_rzut[0][r] << endl;
			Sleep(700);
			cout << "rzuca gracz: " << player[3][0] << endl;
			z_rzut[3][r] = rzut_k();
			cout << "wynik rzutu = " << z_rzut[3][r] << endl;
			Sleep(700);
		}
		else if (z_rzut[1][r] == z_rzut[2][r]) {
			cout << "Remis " << player[1][0] << " miedzy " << player[2][0] << "\nGracze zaczynaja jeszcze raz" << endl;
			cout << "rzuca gracz: " << player[1][0] << endl;
			z_rzut[1][r] = rzut_k();
			cout << "wynik rzutu = " << z_rzut[1][r] << endl;
			Sleep(700);
			cout << "rzuca gracz: " << player[2][0] << endl;
			z_rzut[2][r] = rzut_k();
			cout << "wynik rzutu = " << z_rzut[2][r] << endl;
			Sleep(700);
		}
		else if (z_rzut[1][r] == z_rzut[3][r]) {
			cout << "Remis " << player[1][0] << " miedzy " << player[3][0] << "\nGracze zaczynaja jeszcze raz" << endl;
			cout << "rzuca gracz: " << player[1][0] << endl;
			z_rzut[1][r] = rzut_k();
			cout << "wynik rzutu = " << z_rzut[1][r] << endl;
			Sleep(700);
			cout << "rzuca gracz: " << player[3][0] << endl;
			z_rzut[3][r] = rzut_k();
			cout << "wynik rzutu = " << z_rzut[3][r] << endl;
			Sleep(700);
		}
		else if (z_rzut[2][r] == z_rzut[3][r]) {
			cout << "Remis " << player[2][0] << " miedzy " << player[3][0] << "\nGracze zaczynaja jeszcze raz" << endl;
			cout << "rzuca gracz: " << player[2][0] << endl;
			z_rzut[2][r] = rzut_k();
			cout << "wynik rzutu = " << z_rzut[2][r] << endl;
			Sleep(700);
			cout << "rzuca gracz: " << player[3][0] << endl;
			z_rzut[3][r] = rzut_k();
			cout << "wynik rzutu = " << z_rzut[3][r] << endl;
			Sleep(700);
		}
		else {
			cout << " ";
		}
}
void rozgrywka() { 
    for(int i = 0; i < 4; i++){z_rzut[i][7] = 0;}
for(int r=1; r<7;r++){ // symulowanie rundy musi być 7 :) // specjalnie dałem 2 rundy bo za duża się wyświetla // specjalnie dałem 2 rundy bo za duża się wyświetla
 // r jaka runda 
 cout << "|| runda nr "<< r << " ||\n \n";
Sleep(500);
     for(int i=0; i<liczba_graczy;i++){// symulowanie rzutów graczy 
        s_r_g(r,i); // symulowanie rzutów graczy
        }//wykoneane rzutów graczy liczba_graczy
        // uuu sprawdza czy nie było remisu
        //zdefinowanie widmo
        z_rzut[2][r] = 0;
        z_rzut[3][r] = 1;
    sprawdzenie_if(r);
    // ^^^ sprawdza czy nie było remisu
    // wygrane rundy
    wg_r(r); // wygrana rundy
    //----------------------
 cout << "\n";
Sleep(2000); // odczekanie sekundy
}

}
void nick_player(){// wpisywanie nicków garczy 
    cout << "wpisz nicki: \n";
    for (int i = 0; i < liczba_graczy; i++){
        cout << i+1 << " player = ";
        cin >> player[i][0];
    } // potwierdza liczbe i nicki graczy
    cout << "nicki: ";
    for (int i = 0; i < liczba_graczy; i++){
        cout << i+1 << "  player = ";
        cout << player[i][0] << " ";
    }
    cout << " \n";
}
int p_l_g(){ // liczba graczy zmienna
	cout << "ile jest graczy: ";
	cin >> liczba_graczy; 
	if (liczba_graczy < 5 && liczba_graczy > 1){
	        cout << "spoko mozesz gra \n";
            return liczba_graczy;
	    }
	else{
	        cout << "NO TY CHYBA SOBIE JAJA ROBISZ, NIE GRASZ ZDRADZIECKA KURWO \n";
            return p_l_g();
    }
}
void zasady() { // zasady gry
    cout << " Gracz z najwyzsza suma punktow - wygrywa runde \n ilosc round - 6 // specjalnie dałem 2 rundy bo za duża się wyświetla \n remis w rundzie - powtarzanie rundy tylko remisowych \n Zasady - \n Gracz ktory uzyska szostke na obu kostkach ma  mozliwosc dodatkowego rzutu  koscmi w tej samej rundzie i dodaje do calego wyniku z rundy \n Gracz ktoremu na obu kostkach wypadnie wynik parzysty moze dodac + 1 do wyniku \n Gracz ktoremu wypadną dwie jedynki otrzymuje w tej rundzie 0 punktow  \n  \n \n";}
void w_t_p() { // wytłumaczenie tabeli player
    cout << "tabela zrobiona jako pokaz zrobiona zmiennej player tu akurat na 3 graczy na 8 miejsc\n0 123456 7 \n0 123456 7 \n0 123456 7 \n0 - gracz i enterów jest 2-4 \n1-6 - rundy i zapisane wyniki graczy (w karzdej rundzie osobny  wynik(- suma wyrzuconych oczek w dwóch kostkach))\n7 - suma wygranych rund w X obok siebie\n // specjalnie dałem 2 rundy bo za duża się wyświetla\n";}
void autorzy() { // informacje na temat autorów
    cout << "\n zespol Timon i Pumba company \n czlonkowie: \n Timon - kosiara2015 (Bartek Zebrowski) \n Pumba - yrzer (Grzegorz Szczepkowski) \n  \n "<< endl;}
void koniec(){
    cout << player[0][0] << " wygral: " << z_rzut[0][7] << " rund" << endl;
	cout << player[1][0] << " wygral: " << z_rzut[1][7] << " rund" << endl;
	if (liczba_graczy > 2) {
		cout << player[2][0] << " wygral: " << z_rzut[2][7] << " rund" << endl;

		if (liczba_graczy > 3) {
			cout << player[3][0] << " wygral: " << z_rzut[3][7] << " rund" << endl;
		}
        cout << endl;
	}
	if (z_rzut[0][7] > z_rzut[1][7] && z_rzut[0][7] > z_rzut[2][7] && z_rzut[0][7] > z_rzut[3][7]) {
		cout << "GRATULACJE GRACZU: " << player[0][0] << " WYGRAlEs";
	}
	else if (z_rzut[1][7] > z_rzut[0][7] && z_rzut[1][7] > z_rzut[2][7] && z_rzut[1][7] > z_rzut[3][7]) {
		cout << "GRATULACJE GRACZU: " << player[1][0] << " WYGRAlEs";
	}
	else if (z_rzut[2][7] > z_rzut[1][7] && z_rzut[2][7] > z_rzut[0][7] && z_rzut[2][7] > z_rzut[3][7]) {
		cout << "GRATULACJE GRACZU: " << player[2][0] << " WYGRAlEs";
	}
	else if (z_rzut[3][7] > z_rzut[1][7] && z_rzut[3][7] > z_rzut[2][7] && z_rzut[3][7] > z_rzut[0][7]) {
		cout << "GRATULACJE GRACZU: " << player[3][0] << " WYGRAlEs";
	}
}
bool game_over(){
    cout << "\n koniec \n || 1:exit | 2:restart  || = "<<endl;
    int endgame;
    cin >> endgame;
        switch (endgame){
            case 1:
                return true;
                break;
            case 2:
                return false;
                break;
            default:
                cout << " error \n";
                return game_over();
                break;
    }
}
int main(){ // działanie gry
    cout << "-- gra kosciana :D || play:1 | zasady:2 | autorzy:3 | ?:4 || --\n   liczba: ";
    int menu;
    cin >> menu;
    switch (menu)
    {
    case 1:
        cout << " start \n";
        liczba_graczy = p_l_g(); // podaj liczbe graczy
        nick_player(); // zapisywanie nicków graczy
        Sleep(1000); // odczekanie sekundy
        rozgrywka();  // rozgrywka
        // specjalnie dałem 2 rundy bo za duża się wyświetla
        koniec();
        Sleep(1000); // odczekanie sekundy
    if(game_over() == 0){
        main();
    }
    else{return 0;};
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
cout<<"syntax error";
return main();
}