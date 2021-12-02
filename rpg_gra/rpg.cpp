#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int chwilowe;
int atak_e,atak_p,wybor_l,score;
double limit= 0.00014; 
string nazwa_boss = " !!! -- BOSS -- !!!";

int los_atak(int a){
    Sleep(9);
    chwilowe = rand() % a + 1;
return chwilowe;
};
void game_over(int e){
    if (e==1)
    {
         cout << "\nGAME OVER YOU DIE\n";
    }
    else if (e==2){
        cout << "\nGAME OVER YOU DIE\n";
      system("pause");
      exit(EXIT_SUCCESS);
    }else{
        cout << "\nGAME OVER WYGRANA\n";
    };
    cout << "\ntwoj wynik = "<< score<<endl;
    system("pause");
    exit(EXIT_SUCCESS);
}

struct klass_p{ // player
int hp;
int dmg;
int def;
int speed;
int charyzma; // magia  "-" czarna
int lvl; // jako losowanie kryta
int id;// id of kalsa
int k_lvl(){int a = los_atak(lvl); if(a>=5){a=a%7;cout<<"krytyk\n";}else{a=0;}; return (a*lvl/25);}
int yeet(){ // 0 admin
    cout << "yeet" << endl;
    return (dmg*def*speed*charyzma*limit);
}
int a_t(){ //atak fizyczny
    string s_a_t[4] = { {"z liscia"},{"kop w 4 litery"},{"prosty serpowy"},{"kop w klejnoty"}};
    cout << s_a_t[los_atak(4)-1] << endl; 
    return (dmg*speed*k_lvl()*limit*3);};// deafult
int exorcyzm(){ // magik
    cout << "lorem ipsum" << endl; 
    return (dmg*speed*charyzma*k_lvl()*limit);
}
int opetanie(){ //n_magig
        cout << "kto pytal" << endl; 
    return (dmg*speed*(charyzma*(-1))*k_lvl()*limit);
}
int bow(){ 
    cout << " HOWKAY " << endl; 
    return (speed*def*k_lvl()*limit);
}
int ruch_(){ 
    cout << " AAAAAAAAA! " << endl; 
    return (speed*hp*k_lvl()*limit);
}
int w_weapon(){ // bron
    cout << " dziagniecie " << endl; 
    return (2*dmg*speed*k_lvl()*limit);
}

int omamienie() { // return lvl
    cout << " strzal z laczka" << endl;
    return (lvl*def*speed*limit);
}
int heal(){ // return hp
    chwilowe = 0;
    cout << "leczenie" ;
    chwilowe = hp*speed*def*limit;
    cout << " = " << chwilowe << endl;
    return chwilowe;
}
int energetyk(){ // return speed
    cout << "energetyk - BOOST!" << endl;
    return (hp*def*speed*limit);
}
int kamikadze_s(){
    int a = 0; a = a+ruch_()+w_weapon();
    return a;}
int flash_s(){
    cout << " speeed! + ";
    int a = a_t();
    return (a*speed);}

int specjaly(){

if(id == 1){return exorcyzm();}
else if(id == 2){return opetanie();}
else if(id == 3){return w_weapon();}
else if(id == 4){return ruch_();}
else if(id == 5){return exorcyzm();}
else if(id == 6){return opetanie();}
else if(id == 7){return kamikadze_s();}
else if(id == 8){return ruch_();}
else if(id == 9){return w_weapon();}
else if(id == 10){return flash_s();}
return yeet();}};

struct klass_e{ // enemy
int hp;
int dmg;
int def;
int speed;
int charyzma; // magia  "-" czarna
int lvl; // jako losowanie kryta
int k_lvl(){int a = los_atak(lvl); if(a>=5){a=a%7;cout<<"krytyk\n";}else{a=0;}; return (a*lvl/10);}
int a_t(){ //atak fizyczny
    string s_a_t[4] = { {"z liscia"},{"kop w 4 litery"},{"scratching"},{"trupi jad"}};
    cout << s_a_t[los_atak(4)-1] << endl; 
    return (dmg*speed*k_lvl()*limit);};// deafult
int exorcyzm(){ // magik
    cout << "lorem ipsum" << endl; 
    return (dmg*speed*charyzma*k_lvl()*limit*3);
}
int opetanie(){ //n_magig
        cout << "kto pytal" << endl; 
    return (dmg*speed*(charyzma*(-1))*k_lvl()*limit);
}
int bow(){ 
    cout << " HOWKAY " << endl; 
    return (speed*def*k_lvl()*limit*2);
}
int radiation(){
    cout << " uran - leczenie | ";
    chwilowe = (hp*k_lvl()*def/10001);
    cout << chwilowe << " punktow " << endl;
    return chwilowe;
}
int miss(){
    cout << "miss" << endl;
    return 0;
}};

 // gracz kazdy i enemy
    klass_p gracz;
    klass_e enemy;
 // gracze klassy // admin0; aniol1; diabel2; thor3; P_E_K_K_A4; magik5; nygga_magik6//mroczny; kamikadze7; smok8; mini_P_E_K_K_A9; flash10;
    klass_p admin = {
    999, 499, 499, 99, 99, 99,  
    };
    klass_p aniol = {
    400, 250, 300, 70,  99, 70, 1,
    };
    klass_p diabel = {
    400, 250, 300, 70,  -99,  70,  2,
    };
    klass_p thor = {
    500, 200, 320, 60,  25,  50,  3,
    };
    klass_p P_E_K_K_A = {
    750, 200, 400, 20,  0,  25,  4,
    };
    klass_p magik = {
    150, 100, 200, 80,  70,  50, 5,
    };
    klass_p nygga_magik = {
    150, 100, 200, 80,  -70,  50,  6,
    };
    klass_p kamikadze = {
    150, 100, 230, 80,  0,  99,  7,
    };
    klass_p smok = {
    600, 100, 250, 80, 5, 80, 8,
    };
    klass_p mini_P_E_K_K_A = {
    650, 250, 300, 60, 0, 55, 9,
    };
    klass_p flash = {
    250, 200, 130, 89,  0, 99,  
    };
    // gracze klassy przciwnnicy // pion1; golem2; czarno_ksieznik3; bomber_man4; loki5; wilkolak6; wampir7; subkub8; duch9; boss10
    klass_e boss = {
    499, 249, 249, 49, 49, 49,  
    };
    klass_e pion = {
    100, 70, 70, 30, 0, 25,  
    };
    klass_e golem = {
    350, 100, 140, 20, 0, 20,  
    };
    klass_e czarno_ksieznik = {
    120, 100, 70, 35, -49, 20,  
    };
    klass_e bomber_man = {
    90, 70, 130, 40, 0, 49,        
    };
    klass_e loki = {
    180, 130, 90, 32, -39, 26,  
    };
    klass_e wilkolak = {
    300, 200, 140, 32, 0, 30,  
    };
    klass_e wampir = {
    200, 210, 100, 32, 0, 39,  
    };
    klass_e subkub = {
    150, 110, 100, 32, -15, 25,  
    };
    klass_e duch = {
    150, 
    110, 
    249, 
    32,  
    -15,  
    25,  
    };
   
// tutorial
void klassa_postaci(){
        int wybor=0;
    cout << "| 1= aniol | 2= diabel | 3= thor | 4= P_E_K_K_A | 5= magik |\n"
         << "| 6= mroczny magik | 7= kamikadze | 8= smok | 9= mini_P_E_K_K_A | 10= flash| " ;
    cout << "\n-- wybiez klase 1,2,3... = " ; cin >> wybor;
    switch (wybor)
    {
    case 0:
        gracz = admin;
        break;
    case 1:
        gracz = aniol;
        break;
    case 2:
        gracz = diabel;
        break;
    case 3:
        gracz = thor;
        break;
    case 4:
        gracz =  P_E_K_K_A;
        break;
    case 5:
        gracz = kamikadze;
        break;
    case 6:
        gracz = smok;
        break;
    case 7:
        gracz = mini_P_E_K_K_A;
        break;
    case 8:
        gracz = flash;
        break;
    case 9:
        gracz = admin;
        break;
    case 10:
        gracz = admin;
        break;
    default:
    cout << "\n error\n" ;
    klassa_postaci();
        break;
    }
}

void ruch_p(){
    int wybor_atak=0;
    cout << "\n1 = defult | 2 = heal | 3 = energetyk | 4 = omamienie | 5 = atak specjaly" ;
    cout << "\n-- wybiez atak 1,2,3,4,5 = " ;
        atak_e = 0;atak_p = 0;
    cin >> wybor_atak;
        switch (wybor_atak)
        {
        case 0:// admin
            atak_p = gracz.yeet();  break;
        case 2:
            gracz.hp = gracz.heal();  break;
        case 3:
            gracz.speed = gracz.energetyk();  break;
        case 4:
            gracz.lvl = gracz.omamienie();  break;
        case 5:
            atak_p = gracz.specjaly();  break;
        default: //case 1;
            atak_p = gracz.a_t();  break;
        };
}
void ruch_t_e(){
        atak_e = 0;atak_p = 0;
         srand (time(NULL));
    chwilowe = los_atak(6);
        switch(chwilowe) {
        case 1:
            atak_e = enemy.a_t();  break;
        case 2:
            atak_e = enemy.exorcyzm();  break;
        case 3:
            atak_e = enemy.opetanie();  break;
        case 4:
            atak_e = enemy.bow();  break;
        case 5:
            enemy.hp = enemy.radiation(); break;
        case 6:
            atak_e = enemy.miss();  break;
        }
        gracz.hp -= atak_e;
        cout << "przciwnik atakuje zadajac " << atak_e << " hp graczowi; HP gracz " << gracz.hp << endl;
}

int tutorial(){
    klassa_postaci();
int plus_50_do_hp = gracz.hp;
string n_t_e[4] = { {"pion"},{"golem"},{"czarno ksieznik"},{"error"}};
for(int z_p=1;z_p<=3;z_p++){//
if(z_p==1){enemy = pion;};
cout << "\n przciwnik "<<n_t_e[z_p-1]<<" !!! ";
    do {
    ruch_p();
    enemy.hp -= atak_p;
        cout << "garcz atakuje zadajac " << atak_p << " hp przeciwnikowi;";
    Sleep(1000);
     cout << " HP przeciwnika " << enemy.hp << endl;
    if (enemy.hp > 0){
        ruch_t_e();
    }else { cout << "\nprzciwnik umarl bo nie zyje" ;};
    } while (enemy.hp > 0 && gracz.hp > 0);
if(gracz.hp <= 0){game_over(2);};
if(z_p==3){// nic
}else{
cout << "\n WYGRANNA !!!  ---  z "<< n_t_e[z_p-1] <<"\n nastepny przciwnik - "
 << n_t_e[z_p] // name tutorial enemy string // do petli
<< "\n leczenie !  ---  i + "<<(50*z_p)<<" do hp \n\n strat!\n" ;
gracz.hp = plus_50_do_hp + (50*z_p);// zmienna petla pierwsza 1 druga 2...
if(z_p==1){
enemy = golem;}
else if(z_p==2){enemy = czarno_ksieznik;}
else{// koniec petli c:
};};
}//
    string l_7 = "\n\n WYGRANNA !!! \n przeszedles tutorial\n\n w strat wpisz liczbe 7 /by grac w pelna gre\n";
    cout << l_7;
    system("pause"); system("cls");
    cout << l_7;
    return 1;
}

void autorzy(){
    cout << " cala gre wykonal yrzer - grzegorz szczepkowski \nwszelkie prawa zastrzezone" << endl;
}
// koniec tutoriala
void ruch_e(){
        atak_e = 0;atak_p = 0;
         srand (time(NULL));
    chwilowe = los_atak(6);
        switch(chwilowe) {
        case 1:
            atak_e = enemy.a_t();  break;
        case 2:
            atak_e = enemy.exorcyzm();  break;
        case 3:
            atak_e = enemy.opetanie();  break;
        case 4:
            atak_e = enemy.bow();  break;
        case 5:
            enemy.hp = enemy.radiation(); break;
        case 6:
            atak_e = enemy.miss();  break;
        }
        gracz.hp -= atak_e;
        cout << "przciwnik atakuje zadajac " << atak_e << " hp graczowi; HP gracz " << gracz.hp << endl;
}

string klassa_enemy(){
    wybor_l=0;string nazwa;
    srand(time(NULL));
    wybor_l = los_atak(10);
    Sleep(1);
    switch (wybor_l){
    case 2:
        enemy = golem;
        nazwa = " golem ";
        break;
    case 1:
        enemy = pion;
        nazwa = " pion ";
        break;
    case 3:
        nazwa = " czarno_ksieznik ";
        enemy = czarno_ksieznik;
        break;
    case 4:
        enemy = bomber_man;
        nazwa = " bomber-man ";
        break;
    case 5:
        enemy = loki;
        nazwa = " loki ";
        break;
    case 6:
        enemy = wilkolak;
        nazwa = " wilkolak ";
        break;
    case 7:
        enemy = wampir;
        nazwa = " wampir ";
        break;
    case 8:
        enemy = subkub;
        nazwa = " subkub ";
        break;
    case 9:
        enemy = duch;
        nazwa = " duch ";
        break;
    case 10:
        nazwa = nazwa_boss;
        enemy = boss;
        break;}
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
    if (enemy.hp > 0){
        ruch_e();//numer 1-10
    }else {
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
    switch (wybor){
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