//
// Created by mtb on 7/7/21.
//

#include<iostream>
#include <cstring>

using namespace std;

void g(int){
    static int i=0;
    cout << "g(int) " << i << endl;
    i++;
}
void h(int);

template<typename T>
void f(T a){
    g(a); // Called general int
    if(a)h(a-1);
}


void h(int i){
    extern void g(double);
    f(i);
}
// Instantiation of f<int>

void t1(){
    h(4);
}

void m(int){
    cout << "m(int) "  << endl;
}

template<typename T>
class Container{
public:
    using value_type = T;
    T operator[](T a){
        return a;
    }
    void sort() {
        ::m(0);
    }
};


// Instantiation of Container<int>
void t2(){
    Container<int> c;
    struct S {int a, b;};
     c.sort();
     Container<S> {};
}
int main() {
    t2();


    return 0;
}


