//
// Created by mtb on 6/20/21.
#include<iostream>

using namespace std;

template <typename T>
void f(T a){

}
struct Points{
    constexpr Points(){}
};

struct Line{

};

template <typename T, int max>

class Buffer{
public:
    Buffer(){
//        max = 5; // Error max is constant
    }
};

//template <typename T, Line a> class B {}; // Error. Only integer / char as value argument

template<typename T, T default_value=T{}>
class Vec{};

void t1(int i){
    const int z = 6;
//    Buffer<int, i>; // Error i not const
    Buffer<int, z>{};
    f(Line{}); // Ok
    f(Points{}); // ok
}


void t2(){
    Vec<int,42> v{};
//    Vec<string,""> vs{}; // Error string cannot be parameter
//    Vec<float, 42>vf{}; // Error Same as string
//    Vec<Points, Points{}>vf{};
//
    Vec<int> vi{};
    Vec<char> vc{};
//    Vec<string, ""> vs{}; Error

}
template<typename K, typename V, bool(*cmp)(const K&, const K&)> // ok
class map {
public:
    map(){}
};

template<typename K, typename V, typename Compare = std::less<K>> // Default comparison is  std::less<K>
class map2 {
public:
    map2(){}
    map2(Compare c): cmp{c}{};
    Compare cmp{};

};

bool greater_than(const string&x, const string &y){
    return x > y;
}

void t3() {
    map<string, int,greater_than> m{};
    map2<string, int, std::greater<string>> m2{};
    map2<string, int> m3{};

    using Cmp = bool(*)(const string&, const string &);
    map2<string, int, Cmp> mm{greater_than};
    map2<string, int, Cmp> mmm{[](const string&a, const string &b){
        return a > b;
    }};
//    map2<string,int,Cmp> c3 {[](const string& x, const string& y) const { return x<y; }}; // Error because of the conversion lambda to Cmp
    auto cmp = [](const string& x, const string& y) { return x<y; } ;
    map2<string,int, decltype(cmp)> c3 {cmp}; // Fixed

}
int main() {
    t1(5);
    t2();
    t3();
    return 0;
}