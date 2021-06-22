//
// Created by mtb on 6/20/21.
//
#include<iostream>
#include <vector>
using namespace std;

template<typename T>
class complex {
    T re, im;

public:
    complex(T rr, T ii): re{rr}, im{ii}{}

    template<typename U>
    friend complex<U> square (const complex<U> &b);

    template<typename U>
    friend ostream& operator << (ostream& out, const complex<U> & a);
};

template<typename T>
T square(T a){
    return a * a;
}

template<typename T>
complex <T>  square(const complex<T> &a) {
    return complex<T>{a.re * a.re , a.im* a.im};
}



template<typename T>
ostream& operator << (ostream& out, const complex<T> &a) {
    cout << "Complex(re=" << a.re <<", im="<< a.im << ")" << endl;
    return out;
}

int main() {
    cout << square(4)<< endl;
    cout << square(5.2) << endl;

    complex<double> z{2.1, 4.0};
    cout << square(z);

    cout << z ;
    return 0;
}