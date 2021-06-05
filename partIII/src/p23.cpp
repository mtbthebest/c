//
// Created by mtb on 1/11/21.
//
#include<iostream>
using namespace std;
class F;
class B
{
private:
    int x=3;
    friend class F;
    void print_x() {
        cout << x << endl;
    }
protected:
    const char *day="Monday";

    void print_char() {
        cout << day << endl;
    }
public:
    int y = 1;

    void print_y() {
        cout << y << endl;
    }


};

class D1: B
{
private:

public:

    void print(){
//        B::print_x(); // Error
        B::print_char();
    }

};

class D2 : public D1 {
public:
    void print() {
//        B::print_char(); //Error
//        B::print_char();
    }
};


class D3: protected B {
public:
    void print(){
        B::print_char();
        B::print_y();
//        B::print_x();
    }
};

class D4: D3 {
public:
    void print() {
        B::print_char();
        B::print_y();
    }
};

class D5: public B {
public:
    void print() {
        B::print_char();
        B::print_y();
    }
};

class D6: public D5 {
public:
    void print() {
        B::print_char();
    }
};

class F {
public:
    void print_x(B &b) {
        cout << b.x;
    }
};
int main(int argc, char *argv[]){
    D1 d;
    d.print();
    return 0;
}

