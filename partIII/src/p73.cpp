//
// Created by mtb on 7/7/21.
//Metaprogramming

#include <iostream>
using namespace std;


template<int N>
constexpr int fact(){
    return N * fact<N-1>();
}

template<>
constexpr int fact<0>(){
    return 1;
}
template<int N>
struct Fac{
    static const int value = N*Fac<N-1>::value;
};

template<>
struct Fac<1>{
    static const int value = 1;
};
void t1(){
    constexpr int x = fact<5>();
    cout << x << endl;
}

int main() {
    t1();
    constexpr int x = Fac<5>::value;
    cout << x;
    return 0;
}
