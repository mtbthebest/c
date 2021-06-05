//
// Created by mtb on 1/10/21.
//
#include<iostream>
using namespace std;
struct X{
    int m = 1;
};

class Ptr
{

public:
    X *x;
    Ptr() {
        x = new X{};
    }
    X *operator->(){
        return x;
    }


    ~Ptr(){
        delete x;

    }
};
int main(int argc, char *argv[]){
    Ptr p{};
    p->m = 8;
    cout << p.x->m << endl;

    X *x1 = p.operator->();
    cout << x1 << endl;
    return 0;
}