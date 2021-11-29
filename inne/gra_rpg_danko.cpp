#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

int a;

struct postac {
    string nazwa;
    int hp;
    int dmg;
    int def;
    int skill1() {
        cout << "Wodna kula!" << endl;
        return (dmg * 0.3);
    }

    int skill2() {
        cout << "Smocze tornado!" << endl;
        return (dmg * 0.5);
    }

    int skill3() {
        cout << "Ognisty miecz!" << endl;
        return (dmg * 0.5);
    }
    int skill4() {
        cout << "Trująca strzala!" << endl;
        return (dmg * 0.3);
    }
    int skill5() {
        cout << "Duchowy podkop!" << endl;
        return (dmg * 0.3);
    }
    int skill6() {
        cout << "Powietrzna reka!" << endl;
        return (dmg * 0.3);
    }
    int skill7() {
        cout << "Wdzieczny noz" << endl;
        return (dmg * 0.3);
    }

};

struct enemy {
    string nazwa;
    int hp;
    int dmg;
    int def;
    int skill1() {
        cout << "Zasadzka!" << endl;
        return (dmg * 0.5);
    }
    int skill2() {
        cout << "Deszczowy szal!" << endl;
        return (dmg * 0.5);
    }
    int skill3() {
        cout << "Trujace oplucie!" << endl;
        return (dmg * 0.3);
    }
    int skill4() {
        cout << "Latający smok!" << endl;
        return (dmg * 0.3);
    }
    int skill5() {
        cout << "Nocny miecz!" << endl;
        return (dmg * 0.3);
    }
    int skill6() {
        cout << "Świetlne kopnięcie!" << endl;
        return (dmg * 0.3);
    }
    int skill7() {
        cout << "Taktowne dźgnięcie!" << endl;
        return (dmg * 0.3);
    }
};

postac mag = {
    "mag",
    100,
    15,
    10
};

postac lucznik = {
    "lucznik",
    20,
    15,
    10
};

postac zolnierz = {
    "zolnierz",
    20,
    15,
    10
};

postac ninja = {
    "ninja",
    20,
    15,
    10
};


postac snajper = {
    "snajper",
    20,
    15,
    10
};

postac lowca = {
    "lowca",
    20,
    15,
    10
};

postac smok = {
    "smok",
    20,
    15,
    10
};

postac minotaur = {
    "minotaur",
    20,
    15,
    10
};

postac utopiec = {
    "utopiec",
    20,
    15,
    10
};

postac bestia = {
    "bestia",
    20,
    15,
    10
};

enemy pirat = {
    "pirat",
    20,
    15,
    10
};

enemy ogr = {
    "ogr",
    20,
    15,
    10
};

enemy cyklop = {
    "cyklop",
    20,
    15,
    10
};
enemy szkielet = {
    "szkielet",
    20,
    15,
    10
};

enemy tytan = {
    "tytan",
    20,
    15,
    10
};

enemy wiedzma = {
    "wiedzma",
    20,
    15,
    10
};

enemy elf = {
    "elf",
    20,
    15,
    10
};

enemy zombie = {
    "zombie",
    20,
    15,
    10
};

enemy wilk = {
    "wilk",
    20,
    15,
    10
};

enemy jaszczur = {
    "jaszczur",
    20,
    15,
    10
};

postac gracz;
enemy przeciwnik;

int mag1() {
    int akcja1 = 0;
    int atak1 = 0;
    cout << "Wybierz skill" << endl;
    cout << "1 - smocze tornado" << endl;
    cout << "2 - ognisty miecz" << endl;
    cout << "3 - powietrzna ręka" << endl;
    cin >> akcja1;
    switch (akcja1) {
    case 1:
        atak1 = gracz.skill2();
        break;
    case 2:
        atak1 = gracz.skill3();
        break;
    case 3:
        atak1 = gracz.skill4();
        break;
    }
    przeciwnik.hp = przeciwnik.hp - atak1;
    cout << "Zadales " << atak1 << " punktow obrazen, przeciwnik ma " << przeciwnik.hp << "hp" << endl;
    return(przeciwnik.hp);
}

int lucznik1() {
    int akcja1 = 0;
    int atak1 = 0;
    cout << "Wybierz skill" << endl;
    cout << "1 - trujaca strzala" << endl;
    cout << "2 - duchowy podkop" << endl;
    cout << "3 - powietrzna reka" << endl;
    cin >> akcja1;
    switch (akcja1) {
    case 1:
        atak1 = gracz.skill4();
        break;
    case 2:
        atak1 = gracz.skill5();
        break;
    case 3:
        atak1 = gracz.skill6();
        break;
    }
    przeciwnik.hp -= atak1;
    cout << "Zadales " << atak1 << " punktow obrazen, przeciwnik ma " << przeciwnik.hp << "hp" << endl;
    return(przeciwnik.hp);
}

int zolnierz1() {
    int akcja1 = 0;
    int atak1 = 0;
    cout << "Wybierz skill" << endl;
    cout << "1 - duchowy podkop" << endl;
    cout << "2 - powietrzna reka" << endl;
    cout << "3 - wdzieczny noz" << endl;
    cin >> akcja1;
    switch (akcja1) {
    case 1:
        atak1 = gracz.skill5();
        break;
    case 2:
        atak1 = gracz.skill6();
        break;
    case 3:
        atak1 = gracz.skill7();
        break;
    }
    przeciwnik.hp -= atak1;
    cout << "Zadales " << atak1 << " punktow obrazen, przeciwnik ma " << przeciwnik.hp << "hp" << endl;
    return(przeciwnik.hp);
}

int ninja1() {
    int akcja1 = 0;
    int atak1 = 0;
    cout << "Wybierz skill" << endl;
    cout << "1 - duchowy podkop" << endl;
    cout << "2 - powietrzna reka" << endl;
    cout << "3 - wdzieczny noz" << endl;
    cin >> akcja1;
    switch (akcja1) {
    case 1:
        atak1 = gracz.skill5();
        break;
    case 2:
        atak1 = gracz.skill6();
        break;
    case 3:
        atak1 = gracz.skill7();
        break;
    }
    przeciwnik.hp -= atak1;
    cout << "Zadales " << atak1 << " punktow obrazen, przeciwnik ma " << przeciwnik.hp << "hp" << endl;
    return(przeciwnik.hp);
}

int snajper1() {
    int akcja1 = 0;
    int atak1 = 0;
    cout << "Wybierz skill" << endl;
    cout << "1 - duchowy podkop" << endl;
    cout << "2 - powietrzna reka" << endl;
    cout << "3 - wdzieczny noz" << endl;
    cin >> akcja1;
    switch (akcja1) {
    case 1:
        atak1 = gracz.skill5();
        break;
    case 2:
        atak1 = gracz.skill6();
        break;
    case 3:
        atak1 = gracz.skill7();
        break;
    }
    przeciwnik.hp -= atak1;
    cout << "Zadales " << atak1 << " punktow obrazen, przeciwnik ma " << przeciwnik.hp << "hp" << endl;
    return(przeciwnik.hp);
}

int lowca1() {
    int akcja1 = 0;
    int atak1 = 0;
    cout << "Wybierz skill" << endl;
    cout << "1 - duchowy podkop" << endl;
    cout << "2 - powietrzna reka" << endl;
    cout << "3 - wdzieczny noz" << endl;
    cin >> akcja1;
    switch (akcja1) {
    case 1:
        atak1 = gracz.skill5();
        break;
    case 2:
        atak1 = gracz.skill6();
        break;
    case 3:
        atak1 = gracz.skill7();
        break;
    }
    przeciwnik.hp -= atak1;
    cout << "Zadales " << atak1 << " punktow obrazen, przeciwnik ma " << przeciwnik.hp << "hp" << endl;
    return(przeciwnik.hp);
}

int smok1() {
    int akcja1 = 0;
    int atak1 = 0;
    cout << "Wybierz skill" << endl;
    cout << "1 - duchowy podkop" << endl;
    cout << "2 - powietrzna reka" << endl;
    cout << "3 - wdzieczny noz" << endl;
    cin >> akcja1;
    switch (akcja1) {
    case 1:
        atak1 = gracz.skill5();
        break;
    case 2:
        atak1 = gracz.skill6();
        break;
    case 3:
        atak1 = gracz.skill7();
        break;
    }
    przeciwnik.hp -= atak1;
    cout << "Zadales " << atak1 << " punktow obrazen, przeciwnik ma " << przeciwnik.hp << "hp" << endl;
    return(przeciwnik.hp);
}

int minotaur1() {
    int akcja1 = 0;
    int atak1 = 0;
    cout << "Wybierz skill" << endl;
    cout << "1 - duchowy podkop" << endl;
    cout << "2 - powietrzna reka" << endl;
    cout << "3 - wdzieczny noz" << endl;
    cin >> akcja1;
    switch (akcja1) {
    case 1:
        atak1 = gracz.skill5();
        break;
    case 2:
        atak1 = gracz.skill6();
        break;
    case 3:
        atak1 = gracz.skill7();
        break;
    }
    przeciwnik.hp -= atak1;
    cout << "Zadales " << atak1 << " punktow obrazen, przeciwnik ma " << przeciwnik.hp << "hp" << endl;
    return(przeciwnik.hp);
}

int utopiec1() {
    int akcja1 = 0;
    int atak1 = 0;
    cout << "Wybierz skill" << endl;
    cout << "1 - duchowy podkop" << endl;
    cout << "2 - powietrzna reka" << endl;
    cout << "3 - wdzieczny noz" << endl;
    cin >> akcja1;
    switch (akcja1) {
    case 1:
        atak1 = gracz.skill5();
        break;
    case 2:
        atak1 = gracz.skill6();
        break;
    case 3:
        atak1 = gracz.skill7();
        break;
    }
    przeciwnik.hp -= atak1;
    cout << "Zadales " << atak1 << " punktow obrazen, przeciwnik ma " << przeciwnik.hp << "hp" << endl;
    return(przeciwnik.hp);
}

int bestia1() {
    int akcja1 = 0;
    int atak1 = 0;
    cout << "Wybierz skill" << endl;
    cout << "1 - duchowy podkop" << endl;
    cout << "2 - powietrzna reka" << endl;
    cout << "3 - wdzieczny noz" << endl;
    cin >> akcja1;
    switch (akcja1) {
    case 1:
        atak1 = gracz.skill5();
        break;
    case 2:
        atak1 = gracz.skill6();
        break;
    case 3:
        atak1 = gracz.skill7();
        break;
    }
    przeciwnik.hp -= atak1;
    cout << "Zadales " << atak1 << " punktow obrazen, przeciwnik ma " << przeciwnik.hp << "hp" << endl;
    return(przeciwnik.hp);
}

int pirat1() {
    int skill;
    int atak1 = 0;
    skill = rand() % 3 + 1;
    switch (skill) {
    case 1:
        atak1 = przeciwnik.skill1();
        break;
    case 2:
        atak1 = przeciwnik.skill2();
        break;
    case 3:
        atak1 = przeciwnik.skill3();
        break;
    }
    gracz.hp = gracz.hp - atak1;
    cout << "Przeciwnik zadal " << atak1 << " punktow obrazen, masz " << gracz.hp << "hp" << endl;
    return(gracz.hp);
}

int ogr1() {
    int skill;
    int atak1 = 0;
    skill = rand() % 3 + 1;
    switch (skill) {
    case 1:
        atak1 =  przeciwnik.skill1();
        break;
    case 2:
        atak1 = przeciwnik.skill2();
        break;
    case 3:
        atak1 = przeciwnik.skill3();
        break;
    }
    gracz.hp -= atak1;
    cout << "Przeciwnik zadal " << atak1 << " punktow obrazen, masz " << gracz.hp << "hp" << endl;
    return(gracz.hp);
}

int cyklop1() {
    int skill;
    int atak1 = 0;
    skill = rand() % 3 + 1;
    switch (skill) {
    case 1:
        atak1 = przeciwnik.skill1();
        break;
    case 2:
        atak1 = przeciwnik.skill2();
        break;
    case 3:
        atak1 = przeciwnik.skill3();
        break;
    }
    gracz.hp -= atak1;
    cout << "Przeciwnik zadal " << atak1 << " punktow obrazen, masz " << gracz.hp << "hp" << endl;
    return(gracz.hp);
}

int szkielet1() {
    int skill;
    int atak1 = 0;
    skill = rand() % 3 + 1;
    switch (skill) {
    case 1:
        atak1 = przeciwnik.skill1();
        break;
    case 2:
        atak1 = przeciwnik.skill2();
        break;
    case 3:
        atak1 = przeciwnik.skill3();
        break;
    }
    gracz.hp -= atak1;
    cout << "Przeciwnik zadal " << atak1 << " punktow obrazen, masz " << gracz.hp << "hp" << endl;
    return(gracz.hp);
}

int tytan1() {
    int skill;
    int atak1 = 0;
    skill = rand() % 3 + 1;
    switch (skill) {
    case 1:
        atak1 = przeciwnik.skill1();
        break;
    case 2:
        atak1 = przeciwnik.skill2();
        break;
    case 3:
        atak1 = przeciwnik.skill3();
        break;
    }
    gracz.hp -= atak1;
    cout << "Przeciwnik zadal " << atak1 << " punktow obrazen, masz " << gracz.hp << "hp" << endl;
    return(gracz.hp);
}

int wiedzma1() {
    int skill;
    int atak1 = 0;
    skill = rand() % 3 + 1;
    switch (skill) {
    case 1:
        atak1 = przeciwnik.skill1();
        break;
    case 2:
        atak1 = przeciwnik.skill2();
        break;
    case 3:
        atak1 = przeciwnik.skill3();
        break;
    }
    gracz.hp -= atak1;
    cout << "Przeciwnik zadal " << atak1 << " punktow obrazen, masz " << gracz.hp << "hp" << endl;
    return(gracz.hp);
}

int elf1() {
    int skill;
    int atak1 = 0;
    skill = rand() % 3 + 1;
    switch (skill) {
    case 1:
        atak1 = przeciwnik.skill1();
        break;
    case 2:
        atak1 = przeciwnik.skill2();
        break;
    case 3:
        atak1 = przeciwnik.skill3();
        break;
    }
    gracz.hp -= atak1;
    cout << "Przeciwnik zadal " << atak1 << " punktow obrazen, masz " << gracz.hp << "hp" << endl;
    return(gracz.hp);
}

int zombie1() {
    int skill;
    int atak1 = 0;
    skill = rand() % 3 + 1;
    switch (skill) {
    case 1:
        atak1 = przeciwnik.skill1();
        break;
    case 2:
        atak1 = przeciwnik.skill2();
        break;
    case 3:
        atak1 = przeciwnik.skill3();
        break;
    }
    gracz.hp -= atak1;
    cout << "Przeciwnik zadal " << atak1 << " punktow obrazen, masz " << gracz.hp << "hp" << endl;
    return(gracz.hp);
}

int wilk1() {
    int skill;
    int atak1 = 0;
    skill = rand() % 3 + 1;
    switch (skill) {
    case 1:
        atak1 = przeciwnik.skill1();
        break;
    case 2:
        atak1 = przeciwnik.skill2();
        break;
    case 3:
        atak1 = przeciwnik.skill3();
        break;
    }
    gracz.hp -= atak1;
    cout << "Przeciwnik zadal " << atak1 << " punktow obrazen, masz " << gracz.hp << "hp" << endl;
    return(gracz.hp);
}

int jaszczur1() {
    int skill;
    int atak1 = 0;
    skill = rand() % 3 + 1;
    switch (skill) {
    case 1:
        atak1 = przeciwnik.skill1();
        break;
    case 2:
        atak1 = przeciwnik.skill2();
        break;
    case 3:
        atak1 = przeciwnik.skill3();
        break;
    }
    gracz.hp -= atak1;
    cout << "Przeciwnik zadal " << atak1 << " punktow obrazen, masz " << gracz.hp << "hp" << endl;
  return(gracz.hp);
}

void los_prze() {
    int wybor1;
      wybor1 = rand() % 10 + 1;
        switch (wybor1) {
        case 1:
            cout << "Wylosowales za przeciwnika piarata!" << endl;
            przeciwnik = pirat;
            break;
        case 2:
            cout << "Wylosowales za przeciwnika ogra!" << endl;
            przeciwnik = ogr;
            break;
        case 3:
            cout << "Wylosowales za przeciwnika cyklopa!" << endl;
            przeciwnik = cyklop;
            break;
        case 4:
            cout << "Wylosowales za przeciwnika szkieleta!" << endl;
            przeciwnik = szkielet;
            break;
        case 5:
            cout << "Wylosowales za przeciwnika tytana!" << endl;
            przeciwnik = tytan;
            break;
        case 6:
            cout << "Wylosowales za przeciwnika wiedzme!" << endl;
            przeciwnik = wiedzma;
            break;
        case 7:
            cout << "Wylosowales za przeciwnika elfa!" << endl;
            przeciwnik = elf;
            break;
        case 8:
            cout << "Wylosowales za przeciwnika zombie!" << endl;
            przeciwnik = zombie;
            break;
        case 9:
            cout << "Wylosowales za przeciwnika wilka!" << endl;
            przeciwnik = wilk;
            break;
        case 10:
            cout << "Wylosowales za przeciwnika jaszczura!" << endl;
            przeciwnik = jaszczur;
            break;
        }
    a=wybor1;
}

int enemy1() {

     switch (a) {
        case 1:
            cout << "Pirat atakuje!" << endl;
            przeciwnik = pirat;
            pirat1();
            break;
        case 2:
            cout << "Ogr atakuje!" << endl;
            przeciwnik = ogr;
            ogr1();
            break;
        case 3:
            cout << "Cyklop atakuje!" << endl;
            przeciwnik = cyklop;
            cyklop1();
            break;
        case 4:
            cout << "Szkielet atakuje!" << endl;
            przeciwnik = szkielet;
            szkielet1();
            break;
        case 5:
            cout << "Tytan atakuje!" << endl;
            przeciwnik = tytan;
            tytan1();
            break;
        case 6:
            cout << "Wiedzma atakuje!" << endl;
            przeciwnik = wiedzma;
            wiedzma1();
            break;
        case 7:
            cout << "Elf atakuje!" << endl;
            przeciwnik = elf;
            elf1();
            break;
        case 8:
            cout << "Zombie atakuje!" << endl;
            przeciwnik = zombie;
            zombie1();
            break;
        case 9:
            cout << "Wilk atakuje!" << endl;
            przeciwnik = wilk;
            wilk1();
            break;
        case 10:
            cout << "Jaszczur atakuje!" << endl;
            przeciwnik = jaszczur;
            jaszczur1();
            break;
        }
  return(a);
}

int main()
{
    int wybor = 0;
    int atak = 0;
    int akcja = 0;
    int koniec = 0;
    int petla = 1;
    przeciwnik.hp = 10;
    gracz.hp = 10;
    string pos[10] = { {"Mag"},{"Lucznik"},{"Zolnierz"},{"Ninja"},{"Snajper"},{"Lowca"},{"Smok"},{"Minotaur"},{"Utopiec"},{"Bestia"} };
    srand(time(NULL));
    cout << "Wybierz swoja postac: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << pos[i] << endl;
    }
    cin >> wybor;
    while (gracz.hp > 1 && przeciwnik.hp > 1) {
        switch (wybor) {
        case 1:
            while(petla==1) {
                cout << "Wybrales maga, do boju!" << endl;
                gracz = mag;
                los_prze();
                petla=0;
            }
                mag1();
                enemy1();
            break;
        case 2:
            if(petla==1) {
                cout << "Wybrales lucznika, do boju!" << endl;
                los_prze();
                gracz = lucznik;
            }
                lucznik1();
                enemy1();
            break;
        case 3:
            if(petla==1) {
                cout << "Wybrales zolnierza, do boju!" << endl;
                los_prze();
                gracz = zolnierz;
            }
                zolnierz1();
                enemy1();
            break;
        case 4:
            cout << "Wybrales ninje, do boju!" << endl;
            los_prze();
            gracz = ninja;
            los_prze();
            ninja1();
            break;
        case 5:
            cout << "Wybrales snajper, do boju!" << endl;
            los_prze();
            gracz = snajper;
            los_prze();
            snajper1();
            break;
        case 6:
            cout << "Wybrales lowca, do boju!" << endl;
            los_prze();
            gracz = lowca;
            los_prze();
            lowca1();
            break;
        case 7:
            cout << "Wybrales smoka, do boju!" << endl;
            los_prze();
            gracz = smok;
            los_prze();
            smok1();
            break;
        case 8:
            cout << "Wybrales minotaura, do boju!" << endl;
            los_prze();
            gracz = minotaur;
            los_prze();
            minotaur1();
            break;
        case 9:
            cout << "Wybrales utopca, do boju!" << endl;
            los_prze();
            gracz = utopiec;
            los_prze();
            utopiec1();
            break;
        case 10:
            cout << "Wybrales bestie, do boju!" << endl;
            los_prze();
            gracz = bestia;
            los_prze();
            bestia1();
            break;
        }
    }
}