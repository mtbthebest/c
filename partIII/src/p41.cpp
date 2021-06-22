//
// Created by mtb on 6/19/21.
//

#include<iostream>
#include<vector>
using namespace std;

template<class T>

struct X {
    enum E1 {a, b};
//    enum E2; // Error no type
    enum E2:char;

    enum class E3;
    struct X2;
};

template<typename T>
enum X<T>::E2: char{x, y};

template<typename T>
enum class X<T>::E3{a, b};

template<typename T>
struct X<T>::X2{
    X2()=default;
};
int main(){


    return 0;
}