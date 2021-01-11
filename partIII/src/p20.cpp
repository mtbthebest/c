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
//int (*func)(int, int){
//    return 0;
//}
//int accumulate(int *ls, int size, std::function<int(int, int)> f) {
int accumulate(int *ls, int size, int(*f)(int, int)) {
    int d =0;
    for(int i=0; i<size - 1; i++){
        d +=f(ls[i] , ls[i+1]);
    }
    return d;
}

typedef int(*mul)(int, int);
int reduce(int *ls, int size, mul f );

int sub(int a, int b) {
    return a -b;
}

int main(int argc, char *argv[]){
    int ls[] = {1,2,-3, -4,5,6};
    mul f = [](int a, int b){return a*b;};
    Adder add{};
//    int acc = accumulate(ls, 6, add);
    int acc2 = accumulate(ls, 5, &sub);
//    cout << acc << endl;
    cout << f(2,4) << endl;
    cout << acc2 << endl;
    return 0;
}