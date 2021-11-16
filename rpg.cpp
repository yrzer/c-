#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>  

int chwilowe;
int atak_e,atak_p;
using namespace std;
int los_atak(){
     srand (time(NULL));
    chwilowe = rand() % 4 + 1;
return chwilowe;
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
    return (dmg*0.003*speed);
}
int z_policzkowanie(){
    cout << "plaskacz" << endl;
    return ((0.5*speed*dmg)*0.033);
}
int heal(){
    chwilowe = 0;
    cout << "leczenie" ;
    chwilowe = hp+0.015*lvl*def;
    cout << " = " << chwilowe << endl;
    return chwilowe;
}
int energetyk(){
    cout << "energetyk - BOOST!" << endl;
    return (0.017*lvl*def);
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
    return (dmg*0.004*lvl);
}
int radiation(){
    cout << "uran - leczenie" << endl;
    return (hp+0.003*lvl*def);
}
int freez(){
    cout << "sheesh!" << endl;
    return (0.003*lvl*def);
}
int miss(){
    cout << "miss" << endl;
    return 0;
}

};

 // gracz każdy
klass_p gracz;
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

// tutorial
void klassa_postaci(){
        int wybor=0;
    cout << "1= tank | 2= ninja | 3= czarodziej" ;
    cout << "\nwybiez klase 1,2,3 = " ; cin >> wybor;
    switch (wybor)
    {
    case 1:
        gracz = tank;
        break;
    case 2:
        gracz = ninja;
        break;
    case 3:
        gracz = czarodziej;
        break;
    default:
    cout << "\n error\n" ;
    klassa_postaci();
        break;
    }
}
void ruch_1_p(){
    int wybor;
    cout << "\nwybiez atak 0,1,2,3 = " ;
        atak_e = 0;atak_p = 0;
    cin >> wybor;
        switch (wybor)
        {
        default: //case 1;
            atak_p = gracz.z_policzkowanie();  break;
        case 1:
            atak_p = gracz.fireball();  break;
        case 2:
            gracz.hp = gracz.heal();  break;
        case 3:
            gracz.speed = gracz.energetyk();  break;
        };
}
void ruch_1_e(){
        atak_e = 0;atak_p = 0;
    chwilowe = los_atak();
        switch (1) {
        case 1:
            atak_e = pion.scratching();  break;
        case 2:
            pion.hp = pion.radiation(); break;
        case 3:
            pion.def = pion.freez(); break;
            case 4:
            atak_e = pion.miss();  break;
        }
        gracz.hp -= atak_e;
        cout << "przciwnik atakuje zadajac " << atak_e << " hp graczowi; HP gracz " << gracz.hp << endl;
}
void ruch_2_e(){
        atak_e = 0;atak_p = 0;
    chwilowe = los_atak();
        switch (1) {
        case 1:
            atak_e = golem.scratching();  break;
        case 2:
            golem.hp = golem.radiation(); break;
        case 3:
            golem.def = golem.freez(); break;
            case 4:
            atak_e = golem.miss();  break;
        }
        gracz.hp -= atak_e;
        cout << "przciwnik atakuje zadajac " << atak_e << " hp graczowi; HP gracz " << gracz.hp << endl;
}
void ruch_3_e(){
        atak_e = 0;atak_p = 0;
    chwilowe = los_atak();
        switch (1) {
        case 1:
            atak_e = czarno_ksieznik.scratching();  break;
        case 2:
           czarno_ksieznik.hp = czarno_ksieznik.radiation(); break;
        case 3:
            czarno_ksieznik.def = czarno_ksieznik.freez(); break;
            case 4:
            atak_e = czarno_ksieznik.miss();  break;
        }
        gracz.hp -= atak_e;
        cout << "przciwnik atakuje zadajac " << atak_e << " hp graczowi; HP gracz " << gracz.hp << endl;
}

int tutorial(){
    klassa_postaci();
int plus_50_do_hp = gracz.hp;
cout << "\n przciwnik pion !!! " ;
    do {
    ruch_1_p();
    pion.hp -= atak_p;
        cout << "garcz atakuje zadajac " << atak_p << " hp przeciwnikowi;";
    Sleep(1000);
     cout << " HP przeciwnika " << pion.hp << endl;
    if (pion.hp > 0)
    {
        ruch_1_e();
    }
    else {
        cout << "\nprzciwnik umarł bo nie żyje\n" ;
    };

    } while (pion.hp > 0 && gracz.hp > 0);
if(gracz.hp <= 0){
     cout << "\nGAME OVER YOU DIE\n" ;
    system("pause");
    return 0;} 
cout << "\n\n WYGRANNA !!! \n z pion \n następny przciwnik - GOLEM\n leczenie ! i + 50 do hp \n\n strat!\n" ;
gracz.hp = plus_50_do_hp + 50;
do {
    ruch_1_p();
    golem.hp -= atak_p;
        cout << "garcz atakuje zadajac " << atak_p << " hp przeciwnikowi;";
    Sleep(1000);
     cout << " HP przeciwnika " << golem.hp << endl;
    if (golem.hp > 0)
    {
        ruch_2_e();
    }
    else {
        cout << "\nprzciwnik umarł bo nie żyje\n" ;
    };

    } while (golem.hp > 0 && gracz.hp > 0);
    if(gracz.hp <= 0){
     cout << "\nGAME OVER YOU DIE\n" ;
    system("pause");
    return 0;} 
    cout << "\n\n WYGRANNA !!! \n z GOLEM \n następny przciwnik - czarno_ksieznik\n leczenie ! i + 50 do hp \n\n strat!\n" ;
    gracz.hp = plus_50_do_hp + 100;
do {
    ruch_1_p();
    czarno_ksieznik.hp -= atak_p;
        cout << "garcz atakuje zadajac " << atak_p << " hp przeciwnikowi;";
    Sleep(1000);
     cout << " HP przeciwnika " << czarno_ksieznik.hp << endl;
    if (czarno_ksieznik.hp > 0)
    {
        ruch_3_e();
    }
    else {
        cout << "\nprzciwnik umarł bo nie żyje\n" ;
    };

    } while (czarno_ksieznik.hp > 0 && gracz.hp > 0);
    if(gracz.hp <= 0){
     cout << "\nGAME OVER YOU DIE\n" ;
    system("pause");
    return 0;} 
    cout << "\n\n WYGRANNA !!! \n przeszedłeś tutorial\n\n w strat wpisz liczbe 7\n" ;
    return 1;
}

void autorzy(){
    cout << " całą gre wykonał yrzer - grzegorz szczepkowski \nwszelkie prawa zastrzeżone" << endl;
}
// koniec tutoriala
void main2(){
cout << "przeszedłeś gre\n";
}
int main(){ // /////////////////// main
    cout << " | 1:start gry | 2: autorzy |   \n" ;
    
    int wybor;
    cin>>wybor;
    switch (wybor)
    {
    case 2:
        autorzy();
        main();
    case 7:
        main2();
        break;
    default:
        cout << "error\n";
        main();
    case 1:
        int abc = tutorial();
        if(abc==1){ main();}else{cout <<"\n";}
        break;
    }
   
   system("pause");
   return 0;
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