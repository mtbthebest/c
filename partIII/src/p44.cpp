//
// Created by mtb on 6/19/21.
// Friends templates

#include<iostream>

using namespace std;

template<typename T> class Matrix;

template<typename T>
class Vector {
    T v[4];
public:
    friend Vector operator+(const Matrix<T>&, const Vector&);
// ...
};
template<typename T>
class Matrix {
    Vector<T> v[4];
public:
    friend Vector<T> operator+(const Matrix&, const Vector<T>&);
// ...
};


template<typename T>
Vector<T> operator+(const Matrix<T>& m, const Vector<T>& v)
{
Vector<T> r{};

return r;
}



int main(){


    return 0;
}