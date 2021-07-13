//
// Created by mtb on 7/7/21.
//Metaprogramming

#include<iostream>
#include<array>
using namespace std;

template<bool B, typename T, typename F>
using Conditional =typename std::conditional<B, T, F>::type;

struct X {
    void operator()(int x){
        cout << "X: " << x << endl;
    }
};
struct Y {
    void operator()(int x){
        cout << "Y: " << x << endl;
    }
};

void t1(){
    Conditional<(sizeof(int) > 4), X, Y>{}(7);
    using Z = Conditional<(is_polymorphic<X>()),X, Y>;
    Z zz{};
    zz(7);
}

template<typename Iter, typename Val>
Iter search(Iter p, Iter q, Val val){
    auto x = *p;
    auto m = q -p ;
    using value_type = typename Iter::value_type;
    using value_type = decltype(*p);
    using difference_type = decltype(q-p);
}

void t2() {

}

int main() {
//    t1();
    t2();
    return 0;
}
