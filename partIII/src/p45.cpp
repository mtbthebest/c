//
// Created by mtb on 6/19/21.
// Friends templates

#include<iostream>

using namespace std;

class C;
using C2 = C;

template <class T>
class A{
    T a = 5;
    friend class C; // Ok
    friend C; // Ok
    friend C2;
//    friend C3; // Error not in scope
    friend class C4;// Ok introduces new class

};

class C4 {
    public:
    int getVal(A<int> a){
        return a.a;
    }
};

template<typename T>
class B {
    friend T;
    friend A<T>;
//    friend class T; // Error redundant class
    // Comment: C is not a friend. No transitive
};

template<typename T, typename A>
class List;

template<typename T>
class Link {
    template<typename U, typename A>
    friend class List;

};


int main(){
    A<int> a{};
    C4 c{};
    cout << c.getVal(a) << endl;
    return 0;
}