//
// Created by mtb on 6/6/21.
//
#include <iostream>
using namespace std;


struct B{
    int m;
    private:
    int a;
    protected:
        int b;
};

struct D1: public B{
    int n;

};

struct D2: public B{};

struct D: D1, D2{};

struct DD1: public virtual B{
    public:
        using B::b; // Make b access public

};
struct DD2: public virtual B{};
struct DD: DD1, DD2{};

void t1(){
    D d{};
//    d.m = 4; // Amigupus
    d.n = 20;

    DD dd{};
    dd.m = 4; // Non ambiguous
    dd.b = -5;
}

int main(int argc, char **argv){
    t1();

    return 0;
}
