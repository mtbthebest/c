//
// Created by mtb on 12/30/20.
//

#include <iostream>
using  namespace std;

enum Side {
    top, down, left, right
};

int f = Side::right;
int v= down;

ostream& operator<<(ostream &os, Side &s){
    cout << static_cast<int>(s);
    return os;
}

void t1(){
    Side s{};
    cout << s << endl;
    cout << v << endl;
    cout << f << endl;

    s = down;
    cout << s<< endl;

    Side ss = static_cast<Side>(99);
    cout << ss;

}


int  main(int arg, char **argv){
    t1();
    return  0;
}

