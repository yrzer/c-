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