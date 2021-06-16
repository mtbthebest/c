//
// Created by mtb on 6/5/21.
//
#include<iostream>
using namespace std;


enum Group {
    mammal, fish
};

struct Animal {
    char *name;
    Group group;
};

struct Mammal: public Animal {
    int legs;
    Mammal(char *name, int l=4): Animal{name, Group::mammal}, legs{l}{}
};

struct Fish: public Animal {
    Fish(char *name): Animal{name, Group::fish}{}
};
ostream &operator<<(ostream &os,const Animal &a ) {
    cout << "Mammal(" << a.name <<")" << endl;
    return os;
}


void t1(){
    Animal a{"lion", Group::mammal};
    Mammal m{"tiger"};
    cout << a;
    cout << m;

    Animal *pa = &a;
    cout << pa->name << endl;

    pa = & m; // ok Derived to base
    cout << pa->name << endl;

    Mammal *pm2 = & m;
    cout << pm2->name << endl;

//     pm2 = &a; // Not ok only name attr not legs
    pm2 = static_cast<Mammal*>(pa); // Not advised
    pm2->name = "cat";
    pm2->legs = 2;
    pa = &a;
    cout <<"Static cast: " <<pm2->name << "  legs: "<< pm2->legs << " " << pa->name << "  " << endl;

}



int main(int argc, char *argv[]){
    t1();
    return 0;
}

