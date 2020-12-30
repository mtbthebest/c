//
// Created by mtb on 12/30/20.
//

#include <iostream>
using  namespace std;

void t1(){
    int i; unsigned int ui; signed int si;
    i = 5; ui= i; si = i;
    cout << "i: "<<  i<< ", " << "ui: "<<  ui<< ", " << "si: "<<  si << endl;

    i = -50; ui= i; si = i;
    cout << "i: "<<  i<< ", " << "ui: "<<  ui<< ", " << "si: "<<  si << endl;

}

void  t2() {
    short  int i; short unsigned int ui; short  signed int si;
    i = 5; ui= i; si = i;
    cout << "i: "<<  i<< ", " << "ui: "<<  ui<< ", " << "si: "<<  si << endl;

    i = -1; ui= i; si = i;
    cout << "i: "<<  i<< ", " << "ui: "<<  ui<< ", " << "si: "<<  si << endl;

    cout << (short signed int)  80000 << endl;
}

void t3() {
    std::cout << "int:  "<< sizeof (int)<< endl;
    std::cout << "unsigned int:  "<< sizeof(unsigned  int)<< endl;
    std::cout << "signed int:  "<< sizeof(signed  int ) << endl;

    std::cout << "short:  "<< sizeof (short int)<< endl;

}

void t4() {
    int v = 025; // 2*8 + 5 = 21
    int w = 0x15 ;// 16 +5 = 21
    std::cout << v << endl ;
    std::cout << w << endl ;
    std::cout << v +  w << endl ;
}

int  main(int arg, char **argv){
    t4();
    return  0;

}

