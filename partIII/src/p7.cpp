//
// Created by mtb on 1/5/21.
//
#include<iostream>
using namespace std;

class Number {
    int value;
public:
    virtual ~Number()=default;

    virtual void mul_(int constant) = 0;


};


class Integer: Number {
    int value;
public:
    Integer(int v=0): value{v}{
        cout << "Init 2" << endl;
    };
    ~Integer()
    {
        cout << "Integer called " << value << endl;

    }

    void mul_(int constant){
        value * constant;
    }
};

int main(int argc, char *argv[]){
    Integer x{2};
    x.mul_(2);

    return 0;
}

