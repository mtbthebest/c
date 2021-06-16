//
// Created by mtb on 6/5/21.
// Inheriting constructors

#include <iostream>

using namespace std;

struct B1 {
   B1(){};
};

struct D1 : B1{

};

struct B2 {
    B2(int) {
        cout << "B2 initializer" << endl;
    }
    ~B2() {}
};

struct D2: B2 {
// Need to import the constructor
    using B2::B2;
};

void t1() {
    D1 d1{};
    D2 d2{5};
//    D2 d3; // Error no default constructor


}

int main(int argc, char **argv){
    t1();

    return 0;
}
