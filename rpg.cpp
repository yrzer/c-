#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int chwilowe;
int atak_e,atak_p,wybor_l,score;
string nazwa_boss = " !!! BOSS !!!";

int los_atak(){
    Sleep(9);
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

 // gracz kazdy i enemy
    klass_p gracz;
    klass_e enemy;
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
    klass_e boss = {
    200,
    150,
    120,
    350,
    250,
    50,
    };

// tutorial
void klassa_postaci(){
        int wybor=0;
    cout << "1= tank | 2= ninja | 3= czarodziej" ;
    cout << "\n-- wybiez klase 1,2,3 = " ; cin >> wybor;
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
    cout << "\n-- wybiez atak 0,1,2,3 = " ;
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
         srand (time(NULL));
    chwilowe = los_atak();
        switch (1) {
        case 1:
            atak_e = enemy.scratching();  break;
        case 2:
            enemy.hp = enemy.radiation(); break;
        case 3:
            enemy.def = enemy.freez(); break;
            case 4:
            atak_e = enemy.miss();  break;
        }
        gracz.hp -= atak_e;
        cout << "przciwnik atakuje zadajac " << atak_e << " hp graczowi; HP gracz " << gracz.hp << endl;
}
void ruch_2_e(){
        atak_e = 0;atak_p = 0;
         srand (time(NULL));
    chwilowe = los_atak();
        switch (1) {
        case 1:
            atak_e = enemy.scratching();  break;
        case 2:
            enemy.hp = enemy.radiation(); break;
        case 3:
            enemy.def = enemy.freez(); break;
            case 4:
            atak_e = enemy.miss();  break;
        }
        gracz.hp -= atak_e;
        cout << "przciwnik atakuje zadajac " << atak_e << " hp graczowi; HP gracz " << gracz.hp << endl;
}
void ruch_3_e(){
        atak_e = 0;atak_p = 0;
         srand (time(NULL));
    chwilowe = los_atak();
        switch (1) {
        case 1:
            atak_e = enemy.scratching();  break;
        case 2:
           enemy.hp = enemy.radiation(); break;
        case 3:
            enemy.def = enemy.freez(); break;
            case 4:
            atak_e = enemy.miss();  break;
        }
        gracz.hp -= atak_e;
        cout << "przciwnik atakuje zadajac " << atak_e << " hp graczowi; HP gracz " << gracz.hp << endl;
}

int tutorial(){
    klassa_postaci();
int plus_50_do_hp = gracz.hp;
cout << "\n przciwnik pion !!! " ;
enemy = pion;
    do {
    ruch_1_p();
    enemy.hp -= atak_p;
        cout << "garcz atakuje zadajac " << atak_p << " hp przeciwnikowi;";
    Sleep(1000);
     cout << " HP przeciwnika " << enemy.hp << endl;
    if (enemy.hp > 0)
    {
        ruch_1_e();
    }
    else {
        cout << "\nprzciwnik umarl bo nie zyje\n" ;
    };

    } while (enemy.hp > 0 && gracz.hp > 0);
if(gracz.hp <= 0){
     cout << "\nGAME OVER YOU DIE\n" ;
    system("pause");
    return 0;} 
cout << "\n\n WYGRANNA !!! \n z pion \n nastepny przciwnik - GOLEM\n leczenie ! i + 50 do hp \n\n strat!\n" ;
gracz.hp = plus_50_do_hp + 50;
enemy = golem;
do {
    ruch_1_p();
    enemy.hp -= atak_p;
        cout << "garcz atakuje zadajac " << atak_p << " hp przeciwnikowi;";
    Sleep(1000);
     cout << " HP przeciwnika " << enemy.hp << endl;
    if (enemy.hp > 0)
    {
        ruch_2_e();
    }
    else {
        cout << "\nprzciwnik umarl bo nie zyje\n" ;
    };

    } while (enemy.hp > 0 && gracz.hp > 0);
    if(gracz.hp <= 0){
     cout << "\nGAME OVER YOU DIE\n" ;
    system("pause");
    return 0;} 
    cout << "\n\n WYGRANNA !!! \n z GOLEM \n nastepny przciwnik - czarno_ksieznik\n leczenie ! i + 50 do hp \n\n strat!\n" ;
    gracz.hp = plus_50_do_hp + 100;
    enemy = czarno_ksieznik;
do {
    ruch_1_p();
    enemy.hp -= atak_p;
        cout << "garcz atakuje zadajac " << atak_p << " hp przeciwnikowi;";
    Sleep(1000);
     cout << " HP przeciwnika " << enemy.hp << endl;
    if (enemy.hp > 0)
    {
        ruch_3_e();
    }
    else {
        cout << "\nprzciwnik umarl bo nie zyje\n" ;
    };

    } while (enemy.hp > 0 && gracz.hp > 0);
    if(gracz.hp <= 0){
     cout << "\nGAME OVER YOU DIE\n" ;
    system("pause");
    return 0;}
    cout << "\n\n WYGRANNA !!! \n przeszedles tutorial\n\n w strat wpisz liczbe 7 /by grac w pelna gre\n" ;
    system("pause"); system("cls"); 
    cout << "\n\n WYGRANNA !!! \n przeszedles tutorial\n\n w strat wpisz liczbe 7 /by grac w pelna gre\n" ;
    return 1;
}

void autorzy(){
    cout << " cala gre wykonal yrzer - grzegorz szczepkowski \nwszelkie prawa zastrzezone" << endl;
}
// koniec tutoriala
void ruch_p(){
    int wybor;
    cout << "\n-- wybiez atak 0,1,2,3 = " ;
        atak_e = 0;atak_p = 0;
    cin >> wybor;
        switch (wybor)
        {
        default: //case 1;
            atak_p = gracz.z_policzkowanie();  break;
        case 1:
            atak_p = gracz.fireball();  break;
        case 2:
            gracz.hp = gracz.heal()*3;  break;
        case 3:
            gracz.speed = gracz.energetyk();  break;
        };
}
void ruch_e(){
        atak_e = 0;atak_p = 0;
         srand (time(NULL));
        chwilowe = los_atak();
        switch (chwilowe) {
        case 1:
            atak_e = enemy.scratching();  break;
        case 2:
            enemy.hp = enemy.radiation(); break;
        case 3:
            enemy.def = enemy.freez(); break;
        case 4:
            atak_e = enemy.miss();  break;
        }
        gracz.hp -= atak_e;
        cout << "przciwnik atakuje zadajac " << atak_e << " hp graczowi; HP gracz " << gracz.hp << endl;
}
void game_over(int e){
    if (e==1)
    {
         cout << "\nGAME OVER YOU DIE\n";
    }else{
        cout << "\nGAME OVER WYGRANA\n";
    };
    cout << "\ntwoj wynik = "<< score<<endl;


    system("pause");
    exit(EXIT_SUCCESS);
}
string klassa_enemy(){
    wybor_l=0;string nazwa;int ile = 3;
    do{
    srand(time(NULL));
    wybor_l = los_atak();
    Sleep(1);
    ile--;
    }while (wybor_l == 4 && ile > 0);
    
    switch (wybor_l)
    {
    case 1:
        enemy = golem;
        nazwa = " golem ";
        break;
    case 2:
        enemy = pion;
        nazwa = " pion ";
        break;
    case 3:
        nazwa = " czarno_ksieznik ";
        enemy = czarno_ksieznik;
        break;
    case 4:
        nazwa = nazwa_boss;
        enemy = boss;
        break;
    default:
    cout << "\n error\n" ;
    klassa_enemy();
        break;
    }
    
    return nazwa;
}
void main2(){
cout << "\nStart /prawdziwa rozgrywka z czystm kontem\n";
    klassa_postaci();
    int plus_50_do_hp = gracz.hp + 100; string przeciwnik_nazwa;int l_z_boss;int l_z_pn;
    //
    do {
    przeciwnik_nazwa = klassa_enemy();
    cout << "\n przciwnik"<<przeciwnik_nazwa<<" !!! \n" ;
    do {
        ruch_p();
        enemy.hp -= atak_p;
        cout << "garcz atakuje zadajac " << atak_p << " hp przeciwnikowi;";
        cout << " HP przeciwnika " << enemy.hp << endl;
     Sleep(1000);
    if (enemy.hp > 0)
    {
        ruch_e();//numer 1-10
    }
    else {
        cout << "\nprzciwnik umarl bo nie zyje\n" ;
    };
    } while (enemy.hp > 0 && gracz.hp > 0);
    
    if(gracz.hp <= 0){game_over(1);}; //wynik
    score = score + 10 + (wybor_l*10);    // runda 10 pk przciwnik pion 10 bo jeden
    cout << "\n\n WYGRANNA !!! \n z "<< przeciwnik_nazwa <<"\n leczenie !    // do 2/3 zycia\n zwiekszenie zycia o 25% \n" ;
    plus_50_do_hp = plus_50_do_hp + plus_50_do_hp*0.25;
    if(plus_50_do_hp <= (gracz.hp/3)*2){gracz.hp = plus_50_do_hp;}
    l_z_boss = nazwa_boss.size();
    l_z_pn = przeciwnik_nazwa.size();
    } while (l_z_boss != l_z_pn);
    cout<< "wygrales z bossem";
    score = score+50;    // runda 10 pk przciwnik pion 10 bo jeden
    game_over(0);// wynik
}
int main(){ // /////////////////// main
    cout << " | 1:start gry | 2: autorzy |              ?exit = alt + f4 \n-- " ;
    
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
// mozna zobic wielka gre jako szachy jako rpg tekstowa
/*
// zadanie.gra
#include <iostream> // naglowek potrzebny do wprowadzenia jakis danych 
#include <stdlib.h>
#include <ctime> // dodaje nam rand() i srand () 
#include <Windows.h> // dodaje nam opoznienie
#include <conio.h>
using namespace std;
struct klass {//deklaracja struktury
    int hp; // zycie w 100% /zmienne
    int def; // obrona 100% /zmienne 
    int dbt; // durability 100% /zmienne
    int strength; // sila w niutonach\% / np dbt*h*w*%\n
    int intelligence; // inteligencja
    int mana; //
    int magic; //
    int antymagic; //
    int hight; // wysokosc w metrach
    int waga; // w kilogramach
    int speed; // szybkosc np chodzenia
    int holnes; // swietosc/duchownosc
    // int plec
};
int main(){
    // gracze
	klass tank = {
        70, // zycie w 100% /zmienne
        60, // obrona 100% /zmienne 
        70, // durability 100% /zmienne
        tank.dbt*tank.hight*tank.waga*(6/10), // sila w niutonach\% / np dbt*h*w*%\n
        20, // inteligencja   /malo zmienne bardziej lvl
        10, // mana 
        2, // magic
        1, // anty magic
        180, // wysokosc w metrach /nie zminna
        110, // waga w kg /nie zmienna
        7, // szybkosc np biegania W KH
        2, // swietosc/duchownosc NA 100% /malo zmienna
    };
    klass magik = {
        40, // zycie w 100% magia zwieksza /zmienne
        45, // obrona 100% /zmienne 
        55, // durability 100% /zmienne
        tank.dbt*tank.hight*tank.waga*(2/10), // sila w niutonach\% / np dbt*h*w*%\n
        70, // inteligencja   /malo zmienne bardziej lvl
        90, // mana 
        65, // magic
        35, // anty magic
        166, // wysokosc w metrach /nie zminna
        68, // waga w kg /nie zmienna
        8, // szybkosc np biegania W KH
        40, // swietosc/duchownosc NA 100% /malo zmienna
    };
    klass mroczny_magik = {
        40, // zycie w 100% magia zwieksza /zmienne
        40, // obrona 100% /zmienne 
        60, // durability 100% /zmienne
        tank.dbt*tank.hight*tank.waga*(2/10), // sila w niutonach\% / np dbt*h*w*%\n
        70, // inteligencja   /malo zmienne bardziej lvl
        90, // mana 
        40, // magic
        65, // anty magic
        165, // wysokosc w metrach /nie zminna
        70, // waga w kg /nie zmienna
        7, // szybkosc np biegania W KH
        10, // swietosc/duchownosc NA 100% /malo zmienna
    };
    klass healer = {
        50, // zycie w 100% /zmienne
        35, // obrona 100% /zmienne 
        60, // durability 100% /zmienne
        tank.dbt*tank.hight*tank.waga*(4/10), // sila w niutonach\% / np dbt*h*w*%\n
        50, // inteligencja   /malo zmienne bardziej lvl
        65, // mana 
        30, // magic
        2, // anty magic
        160, // wysokosc w metrach /nie zminna
        50, // waga w kg /nie zmienna
        9, // szybkosc np biegania W KH
        60, // swietosc/duchownosc NA 100% /malo zmienna
    };


    // entity
    klass pionek = {
        45, // zycie w 100% /zmienne
        30, // obrona 100% /zmienne 
        35, // durability 100% /zmienne
        tank.dbt*tank.hight*tank.waga*(5/10), // sila w niutonach\% / np dbt*h*w*%\n
        10, // inteligencja   /malo zmienne bardziej lvl
        10, // mana 
        5, // magic
        5, // anty magic
        120, // wysokosc w metrach /nie zminna
        40, // waga w kg /nie zmienna
        9, // szybkosc np biegania W KH
        0, // swietosc/duchownosc NA 100% /malo zmienna
    };
    klass golem = {
        65, // zycie w 100% /zmienne
        50, // obrona 100% /zmienne 
        55, // durability 100% /zmienne
        tank.dbt*tank.hight*tank.waga*(6/10), // sila w niutonach\% / np dbt*h*w*%\n
        10, // inteligencja   /malo zmienne bardziej lvl
        30, // mana 
        5, // magic
        25, // anty magic
        220, // wysokosc w metrach /nie zminna
        180, // waga w kg /nie zmienna
        6, // szybkosc np biegania W KH
        0, // swietosc/duchownosc NA 100% /malo zmienna
    };
    klass czarno_ksieznik = {
        40, // zycie w 100% magia zwieksza /zmienne
        40, // obrona 100% /zmienne 
        60, // durability 100% /zmienne
        tank.dbt*tank.hight*tank.waga*(2/10), // sila w niutonach\% / np dbt*h*w*%\n
        70, // inteligencja   /malo zmienne bardziej lvl
        90, // mana 
        40, // magic
        65, // anty magic
        165, // wysokosc w metrach /nie zminna
        70, // waga w kg /nie zmienna
        7, // szybkosc np biegania W KH
        10, // swietosc/duchownosc NA 100% /malo zmienna
    };
return main();
}
*/