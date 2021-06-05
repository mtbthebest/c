//
// Created by mtb on 12/29/20.
//

#include <iostream>
using  namespace std;

void t1(){
    std::cout << "Hello" << endl  ;
    std::cout << sizeof(double );
}

void  t2() {
    int  x=10,  y=6;
    int c = (x % y);
    int d= (x / y);
    std::cout << c << endl;
    std::cout << d << endl;

}

int  main(int arg, char **argv){

    t2();

    return  0;
}