//
// Created by mtb on 7/7/21.
//Metaprogramming

#include<iostream>
using namespace std;

template<typename T, int N>
struct Array_type{
    using type = T;
    static const int dim = N;
};


void t1(){
    if(is_polymorphic<int>::value)cout << "Big Surprise!";
}

void t2(){
    using Array = Array_type<int, 3>;
    Array::type x = 5;
    constexpr int s = Array::dim;
    cout << x << " "  << s << endl;
    typename Array_type<int, 2>::type y = 10;
}


int main() {
    t2();
    cout << sizeof(char);


    return 0;
}
