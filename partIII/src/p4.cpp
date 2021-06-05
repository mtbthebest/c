//
// Created by mtb on 1/3/21.
//

#include<iostream>

class X
{
    int x;
};

void f(X x){
    class Y{};
}

int main(int argc, char *argv[]){

    X xx;
    f(xx);
    printf("10");


    return 0;
}

