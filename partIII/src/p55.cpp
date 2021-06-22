//
// Created by mtb on 6/20/21.
// Specialization

#include<iostream>
#include <cstring>

using namespace std;


template<typename T, int N>
class Matrix{
public:
    Matrix(){
        cout << "Global initialization"<< endl;
    }
};
template<typename T>
class Matrix<T, 0> {
    T val;
public:
    Matrix(){
        cout << "Initialization for N=0"<< endl;
    }
};
template<typename T>
class Matrix<T, 1> {
    T *val;
    int sz;
public:
    Matrix(){
        cout << "Initialization for N=1"<< endl;
    }
};
template<typename T>
class Matrix<T, 2> {
    T *elem;
    int dim1;
    int dim2;
public:
    Matrix(){
        cout << "Initialization for N=2"<< endl;
    }
};

template<typename T>
bool maximum( T a,  T b){
    return a >b;
}
template<>
bool maximum<int *>( int *a,  int *b){
    return (*a)> (*b);
}
template<>
bool maximum<>( const char *a,  const char *b){
    return (*a)> (*b);
}
bool maximum( const char *a,  const char *b){
    return strcmp(a, b) < 0;
}
int main() {
    Matrix<double, 5> m2{};
    Matrix<int,0> m1{};
    Matrix<int,2> m3{};

    return 0;
}