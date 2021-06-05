//
// Created by mtb on 1/3/21.
//

#include<iostream>
using namespace std;


class D{
public:
    D(int);
};

D::D(int d) {}

class X{
public:

    D d;
};


int main(int argc, char *argv[]){

    D d(2);
//    X x;// Error
    X x{1};
    return 0;
}

