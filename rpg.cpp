#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
int los_atak(){

return 1;
};
struct klass_p{ // player
int hp;
int dmg;
int def;
int speed;
int mana; // nie potzrebne teraz
int lvl; // nie potzrebne teraz
int fireball(){
    cout << "fireball" << endl;
    dmg = dmg*0.003*speed;
    return dmg;
}
int heal(){
    cout << "leczenie" << endl;
    hp = hp+0.003*lvl*def;
    return hp;
}
int energetyk(){
    cout << "energetyk" << endl;
    speed = 0.007*lvl*def;
    // hp -
    return hp;
}};
struct klass_e{ // enemy
int hp;
int dmg;
int def;
int speed;
int lvl; // nie potzrebne teraz
int range; // nie potzrebne teraz
int scratching(){
    cout << "scratching" << endl;
    dmg = dmg*0.003*lvl;
    return dmg;
}
int energetyk(){
    cout << "energetyk" << endl;
    hp = hp+0.003*lvl*def;
    return hp;
}
int freez(){
    cout << "shees" << endl;
    def = 0.003*lvl*def;
    return hp;
}};
int main(){
    // gracze klassy
    klass_p tank = {
    300,
    150,
    300,
    50,
    15,
    1,
    };
    klass_p ninja = {
        100,
    150,
    200,
    300,
    50,
    1,
    };
    klass_p czarodziej = {
        100,
    50,
    70,
    150,
    300,
    1,
    };
    // gracze klassy przciwnnicy
    klass_e golem = {
    200,
    150,
    200,
    50,
    15,
    1,
    };
    klass_e pion = {
    100,
    150,
    200,
    200,
    50,
    1,
    };
    klass_e czarno_ksieznik = {
    100,
    50,
    70,
    150,
    200,
    1,
    };

    int atak_e,atak_p;
    int wybor;
    
    do {
        atak_e = 0;atak_p = 0;
        cout << "wybiez atak 1,2,3 = " ;
        cin >> wybor;
        switch (wybor)
        {
        default: //case 1;
             atak_p = tank.fireball();  break;
        case 2:
            tank.hp = tank.heal();  break;
        case 3:
            tank.speed = tank.energetyk();  break;
        };
        pion.hp -= atak_p;
        cout << "garcz atakuje zadajac " << atak_p << " hp przeciwnikowi; HP piona" << pion.hp << endl;
    Sleep(1000);
        switch (1) {
        case 1:
            atak_e = pion.scratching();  break;
        case 2:
            
            break;
        }
        tank.hp -= atak_e;
        cout << "przciwnik atakuje zadajac " << atak_e << " hp graczowi; HP piona" << pion.hp << endl;
 

    } while (pion.hp > 0 && tank.hp > 0);

    return( 0 );
}
// można zobić wielką gre jako szachy jako rpg tekstową
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