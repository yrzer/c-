// zadanie.gra
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
using namespace std;


void zasady() {
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
void autorzy() {
    setlocale(LC_CTYPE, "Polish");
    cout << " " << endl;
    cout << " zespół Timon i Pumba company " << endl;
    cout << " członkowie: " << endl;
    cout << "    timon - kosiara2015 (bartek żebrowski)  " << endl;
    cout << "   pumba - yrzer (grzegorz szczepkowski)" << endl;
    cout << " " << endl;
}
int game_over(int wynik) {
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
}


int main()
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
