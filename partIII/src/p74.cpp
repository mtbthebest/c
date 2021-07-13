//
// Created by mtb on 7/7/21.
//Metaprogramming

#include <iostream>
#include<memory>
#include <complex.h>

using namespace std;

template <bool B, typename T=void>
using Enable_if = typename std::enable_if<B, T>::type;

template<typename T>
constexpr bool Is_arithmetic(){
    return std::is_arithmetic<T>::value;

}
// Enable_if is only for template functions
template <typename T>
class Comparable{
    public:
    T value;
    Comparable(T val=T()): value{val}{};
    Enable_if<Is_arithmetic<T>(), T> compare(Comparable b){
        return this->value > b.value;
    }

};

struct X{
    int x;
};


void t1(){
    Comparable<int> a{5}, b{2};
    bool s = a.compare(b);
    cout << s;

    int x=2, y=3;
    int *p =&x, *q=&y;
//    Comparable<int *> c{p}, d{q}; // Error because not comparable
//    Comparable<X> e{}, f{}; // Error because not comparable
    Comparable<float> g{5}, h{2}; // Ok
}

template<typename T>
Enable_if<Is_arithmetic<T>(), T> cmp(T a, T b){
    return a> b;
}
template<typename T>
Enable_if<!Is_arithmetic<T>()> cmp(T a, T b){
    return ;
}
void t2(){
    cout << cmp(5, 6) << endl;
    cout << cmp<int>(5, 6.) << endl;

   cmp( std::complex<int> {},  std::complex<int> {}); // Error but fixed with second ENable_if<false, void>
}

int main() {
    t1();
    return 0;
}
