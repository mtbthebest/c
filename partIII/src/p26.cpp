//
// Created by mtb on 6/5/21.

#include <iostream>

using namespace std;

struct Base {
    void f(int){
        cout << "Base f() int" << endl;
    };
    void g(double){
        cout << "Base g() double" << endl;
    };
};

struct Derived : Base{
    void f(double){ // No overloading across scopes
        cout << "Derived f() double" << endl;
    }
    using Base::g; // Overloading allowed

    void g(int ){
        cout << "Derived g() int" << endl;
    }

};

void t1() {
    Derived d;
    d.f(5);
    Base &b = d;
    b.f(4);
    b.f(4.0);

    d.g(5);
    d.g(5.0);

    const Base &bb = d;
    d.g(4);
    d.g(5.0);

}

int main(int argc, char **argv){
    t1();

    return 0;
}
