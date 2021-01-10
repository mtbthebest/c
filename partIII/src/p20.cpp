//
// Created by mtb on 1/10/21.
//
#include<iostream>
#include <bits/std_function.h>
using namespace std;

class Adder
{

public:
    Adder()=default;

    int operator()(int a, int b){
        return a + b;
    }

    ~Adder(){}
};

int accumulate(int *ls, int size, std::function<int(int, int)> f) {
    int d =0;
    for(int i=0; i<size - 1; i++){
        d +=f(ls[i] , ls[i+1]);
    }
    return d;
}

int main(int argc, char *argv[]){
    int ls[] = {1,2,-3, -4,5,6};
    Adder add{};
    int acc = accumulate(ls, 6, add);
    cout << acc;
    return 0;
}