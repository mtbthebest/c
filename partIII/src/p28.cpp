//
// Created by mtb on 6/6/21.
//
#include <iostream>
using namespace std;
class C2;
class C1{
    private:
    int a;
    int getValue() {
        return a;
    };
    friend class C2;
protected:
    int b;
public:
    C1(int _a=0, int _b=1): a{_a}, b{_b} {};

    string getClass() {
        return string{"C1"};
    }

    ~C1() =default;

};

class D1: public C1 {
private:
    int c;
protected:
    int getValueofC() {
        return c;
    }
public:
    int d;
    D1(int _a=0, int _b=1, int _c=2):C1{_a, _b}, c{_c}{
        d = c*2;
    }
    int getValueofB(){
        return b;
    }
//    int getValueofA(){
//        return a;
//    } Error
};

class C2 {
public:
    int getValueofA(C1 c) {
        return c.a;
    }
};

void t1(){
    D1 d1{4, -2, 3};

    cout << d1.d << endl;
//    cout << d1.c << endl; Error

    cout << d1.getClass() << endl;
//    cout << d1.getValueofC() << endl; // Error
    C2 c2 ;
    cout << c2.getValueofA(d1);

}


int main(int argc, char **argv){
    t1();

    return 0;
}
