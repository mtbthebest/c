//
// Created by mtb on 6/6/21.
//
#include<iostream>

using namespace std;

struct V{
    int m;
    V(int i){
        cout << "Initialized V : " << i << endl;
        m = i;
    }
};

struct A{
    A(){
        cout << "Initialized A" << endl;

    };
};

struct B: virtual V, virtual A{
    B(int i): V(i){
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
    D(int i1, int i) : B(i1), C(i), V(i) {// Must initialize Virtual V
        cout << "Initialized D" << endl;

    };
};

int main(int argc, char **argv){
    B  b{-9};
    cout << "---------------------" << b.m << endl;

    D d{4,15};

    cout << d.m  << endl;


    return 0;
}
