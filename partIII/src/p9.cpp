//
// Created by mtb on 1/6/21.
//

#include<iostream>
#include <cstring>
#include<vector>
using namespace std;

struct X{
    X(int){}
};

struct Y{
    X m;
    Y(int a): m{X(a)}{};
};

int main(int argc, char *argv[]){
    Y y{1};
    Y y1(1);

    return 0;
}