//
// Created by mtb on 6/20/21.
//
#include<iostream>
#include <vector>

using namespace std;

template<int>
struct Int {
    using type = int;
};

template<>
struct Int<8> {
    using type = char;
};

template<>
struct Int<16>{
    using type = short;

};

template<int N>
using TInt = typename Int<N>::type;



int main() {
    TInt<8> a = 77;
    TInt<6> b = 77;
    cout << a ;
    return 0;
}