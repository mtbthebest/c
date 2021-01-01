//
// Created by mtb on 1/1/21.
//

#include <iostream>
#include <bits/unique_ptr.h>
#include <cstring>
using namespace std;

class X {
    int v;
public:
    X(int x) {
        cout << x << endl;
    };
    void *operator new(size_t, void *p){
        cout << p << endl;
        return p;
    }

    void print() {
        cout << "V: " << v << endl;
    }
    void set_value(int x) {
        cout << "Setting the values" ;
//        v= x;
    }
};

class X2{
public:
    virtual void *alloc(size_t) =0;
    virtual void free(void *) =0;
};

void *operator new(size_t sz, X2 *x) {
    return x->alloc(sz);
}


void t1() {
    void *buf = reinterpret_cast<void *>(0xF00F);

    X *p2 = new(buf) X{4}; // new(sizeof(X),buf)

    cout << p2;

    X2 *x2;
    X *p = new(x2) X{2};
    X *q = new(x2) X{4};

    q ->set_value(2);
    p->print();
    q->print();

}


int main() {
    t1();
    return 0;
}
