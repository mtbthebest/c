//
// Created by mtb on 1/10/21.
//

#include<iostream>
using namespace std;
class Binary
{
public:
    int number;
    Binary(int n){
        number = n;
    };


    ~Binary(){}
};

Binary operator "" _b(unsigned long long int n) {
    return Binary(n);
}

int main(int argc, char *argv[]){

    auto b= 12_b;
    cout << b.number;

    return 0;
}
