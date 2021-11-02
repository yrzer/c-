#include <iostream>
#include <string>

using namespace std;
struct klass
{
int hp;
int dmg;
int def;
int speed;
int mana;
int lvl;
int fireball(){
    cout << "fireball" << endl;
    dmg = dmg*3*lvl;
    return dmg;
}
int heal(){
    cout << "leczenie" << endl;
    hp = hp+3*lvl*def;
    return hp;
}
int tarcza(){
    cout << "tarcza" << endl;
    def = 3*lvl*def;
    return hp;
}

};
int main(){
    klass tank = {
    300,
    150,
    300,
    50,
    15,
    1,
    };
    klass ninja = {
        100,
    150,
    200,
    300,
    50,
    1,
    };
    klass czarodziej = {
        100,
    50,
    70,
    150,
    300,
    1,
    };
    

    return( 0 );
}
/*
// zadanie.gra
#include <iostream> // nagłówek potrzebny do wprowadzenia jakiś danych 
#include <stdlib.h>
#include <ctime> // dodaje nam rand() i srand () 
#include <Windows.h> // dodaje nam opóźnienie
#include <conio.h>
using namespace std;
struct klass {//deklaracja struktury
    int hp; // życie w 100% /zmienne
    int def; // obrona 100% /zmienne 
    int dbt; // durability 100% /zmienne
    int strength; // siła w niutonach\% / np dbt*h*w*%\n
    int intelligence; // inteligencja
    int mana; //
    int magic; //
    int antymagic; //
    int hight; // wysokość w metrach
    int waga; // w kilogramach
    int speed; // szybkość np chodzenia
    int holnes; // świętość/duchowność
    // int płeć
};
int main(){
    // gracze
	klass tank = {
        70, // życie w 100% /zmienne
        60, // obrona 100% /zmienne 
        70, // durability 100% /zmienne
        tank.dbt*tank.hight*tank.waga*(6/10), // siła w niutonach\% / np dbt*h*w*%\n
        20, // inteligencja   /mało zmienne bardziej lvl
        10, // mana 
        2, // magic
        1, // anty magic
        180, // wysokość w metrach /nie zminna
        110, // waga w kg /nie zmienna
        7, // szybkość np biegania W KH
        2, // świętość/duchowność NA 100% /mało zmienna
    };
    klass magik = {
        40, // życie w 100% magia zwiększa /zmienne
        45, // obrona 100% /zmienne 
        55, // durability 100% /zmienne
        tank.dbt*tank.hight*tank.waga*(2/10), // siła w niutonach\% / np dbt*h*w*%\n
        70, // inteligencja   /mało zmienne bardziej lvl
        90, // mana 
        65, // magic
        35, // anty magic
        166, // wysokość w metrach /nie zminna
        68, // waga w kg /nie zmienna
        8, // szybkość np biegania W KH
        40, // świętość/duchowność NA 100% /mało zmienna
    };
    klass mroczny_magik = {
        40, // życie w 100% magia zwiększa /zmienne
        40, // obrona 100% /zmienne 
        60, // durability 100% /zmienne
        tank.dbt*tank.hight*tank.waga*(2/10), // siła w niutonach\% / np dbt*h*w*%\n
        70, // inteligencja   /mało zmienne bardziej lvl
        90, // mana 
        40, // magic
        65, // anty magic
        165, // wysokość w metrach /nie zminna
        70, // waga w kg /nie zmienna
        7, // szybkość np biegania W KH
        10, // świętość/duchowność NA 100% /mało zmienna
    };
    klass healer = {
        50, // życie w 100% /zmienne
        35, // obrona 100% /zmienne 
        60, // durability 100% /zmienne
        tank.dbt*tank.hight*tank.waga*(4/10), // siła w niutonach\% / np dbt*h*w*%\n
        50, // inteligencja   /mało zmienne bardziej lvl
        65, // mana 
        30, // magic
        2, // anty magic
        160, // wysokość w metrach /nie zminna
        50, // waga w kg /nie zmienna
        9, // szybkość np biegania W KH
        60, // świętość/duchowność NA 100% /mało zmienna
    };


    // entity
    klass pionek = {
        45, // życie w 100% /zmienne
        30, // obrona 100% /zmienne 
        35, // durability 100% /zmienne
        tank.dbt*tank.hight*tank.waga*(5/10), // siła w niutonach\% / np dbt*h*w*%\n
        10, // inteligencja   /mało zmienne bardziej lvl
        10, // mana 
        5, // magic
        5, // anty magic
        120, // wysokość w metrach /nie zminna
        40, // waga w kg /nie zmienna
        9, // szybkość np biegania W KH
        0, // świętość/duchowność NA 100% /mało zmienna
    };
    klass golem = {
        65, // życie w 100% /zmienne
        50, // obrona 100% /zmienne 
        55, // durability 100% /zmienne
        tank.dbt*tank.hight*tank.waga*(6/10), // siła w niutonach\% / np dbt*h*w*%\n
        10, // inteligencja   /mało zmienne bardziej lvl
        30, // mana 
        5, // magic
        25, // anty magic
        220, // wysokość w metrach /nie zminna
        180, // waga w kg /nie zmienna
        6, // szybkość np biegania W KH
        0, // świętość/duchowność NA 100% /mało zmienna
    };
    klass czarno_księżnik = {
        40, // życie w 100% magia zwiększa /zmienne
        40, // obrona 100% /zmienne 
        60, // durability 100% /zmienne
        tank.dbt*tank.hight*tank.waga*(2/10), // siła w niutonach\% / np dbt*h*w*%\n
        70, // inteligencja   /mało zmienne bardziej lvl
        90, // mana 
        40, // magic
        65, // anty magic
        165, // wysokość w metrach /nie zminna
        70, // waga w kg /nie zmienna
        7, // szybkość np biegania W KH
        10, // świętość/duchowność NA 100% /mało zmienna
    };
return main();
}
*/