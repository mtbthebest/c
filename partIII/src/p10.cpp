//
// Created by mtb on 1/6/21.
//

#include<iostream>
using namespace std;

class X
{
public:

    static const bool text = true;
//    static int v = 6;Error
//    static const float v = 5; error
    static constexpr float v = 5.;
    static const int t = 5;
    enum Color{red, blue};
    static  Color c ;

    static int h;
    X();


    ~X(){}
};

const int X::t; //Define or error
const int *p = &X::t;
int X::h= 0;

int main(int argc, char *argv[]){
    int *q = & X::h;
    cout << p << endl;
    cout << q   << endl;
    return 0;
}