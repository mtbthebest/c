//
// Created by mtb on 7/7/21.
//

#include<iostream>
#include <cstring>

using namespace std;

template<typename T>
class X{
    X *x;
    public:

    void sort(){};
};

class Customized{
public:
    void sort(); // Ok
};

void t1(){
    class X;
    X *p; // Ok
//    X a; // Error need definition
}
void t2() {
    X<int> *x;
    X<int> p; // Ok. Instantiated of X

}

void t3(){
    X<char> x{};
    X<Customized> c{};
    x.sort(); // X<char>::sort is instantiated and X<char>::sort

}


int main() {
    t3();


    return 0;
}