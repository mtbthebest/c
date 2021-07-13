//
// Created by mtb on 7/7/21.
//Metaprogramming

#include <iostream>

using namespace std;

struct Square{
    constexpr int operator()(int i){return i*i;}
};

struct Cube{
    constexpr int operator()(int i){return i*i*i;}
};

template<bool B, typename T, typename F>
using Conditional = typename std::conditional<B, T, F>::type;

inline bool is_positive(int i){
    return i >0;
}

int main() {
    auto i= Conditional<(true), Square, Cube>{}(2);
    cout << i;

//    auto j = is_positive(i)? Square{}: Cube {}; // Error incompatible args for ?:
    auto j = is_positive(i)? Square{}(i): Cube {}(i); // Error incompatible args for ?:
    cout << endl;

    cout << j;
    return 0;
}
