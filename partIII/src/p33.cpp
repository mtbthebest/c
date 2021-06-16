//
// Created by mtb on 6/6/21.
//
#include<iostream>

using namespace std;

struct V{
    int m;
    V(int i){
        cout << "Initialized V" << endl;
        m = i;
    }
};

struct A{
    A(){
        cout << "Initialized A" << endl;

    };
};

struct B: virtual V, virtual A{
    B(): V(1){
        cout << "Initialized B" << endl;

    }
};

struct C: virtual V {
    C(int i): V{i}{
        cout << "Initialized C" << endl;

    }
};

class D: virtual public B, virtual public C{
    public:
    D(int i1, int i) : V(i1), C(i) {
        cout << "Initialized D" << endl;

    };
};

int main(int argc, char **argv){
    B  b;
    cout << "---------------------" << endl;

    D d{4,5};

    cout << b.m << endl;
    cout << d.m  << endl;


    return 0;
}
