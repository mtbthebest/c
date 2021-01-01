//
// Created by mtb on 1/1/21.
//

#include <iostream>
#include <cstdarg>
using namespace std;


long long int fact(int n){
    return n>1 ? n * fact(n -1 ):1;
}


void t1() {
    long long int z = fact(15);
    cout << z << endl;
}

int *addr(int &&x){
    return &x;
}

[[noreturn]] void *sum(){
};

void t2() {
    int x =5;
    int *z= addr(6);
    cout << z;

//    int *s =static_cast<int *>(sum());
//    cout << s;

//    cout << s;
}

void update(float &g){

}
void t3(){
    double q = 2.0L;
    float qq = 2.0f;
//    update(2.0f); // Error need constant for update argument
//    update(q);// Error need constant for update argument
    update(qq); // Ok
}

// Pass array as reference
void f(const int(&r)[4]){
    cout << r[0];
//    r[0] = 2;
}

void t4() {
//    int a[] = {1,2,3,4};
    f({1,2,3,4});
//    f(a);
    cout << endl;
//    cout << a[0];

}


int accumulate(int v...){
    va_list ap;

    va_start(ap, v);

    int total = v;
    while(1){
        int p = va_arg(ap, int);
        if(!p) break;
        total += p;
    }

    va_end(ap);
    return  total;
}

void t5(){
    int a[] = {1,2,3};

    int z = accumulate(1,2,3,4,5);

    cout << "Accumulated: " << z;
}

class X{
public:
    static int x;

    void f(int=x){
        cout << "Default: " << x << endl;
    }
};

int X::x = 7;


void t6(){
    X x;
    x.f();
    X::x = 10;

    x.f();
}

int main() {
    t6();
    return 0;
}
