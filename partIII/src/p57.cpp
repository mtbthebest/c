//
// Created by mtb on 7/7/21.
//

#include<iostream>
#include <cstring>

using namespace std;

template<typename T>
class vector{
    int dim;
    T *elem;
public:
    vector(){};
    T& operator[](int);
};


template class vector<int>; // Explicit instantiation
//template int &vector<int>::operator[](int);
template<typename T1, typename T2>
T1 convert(T2 a){
    return static_cast<T1>(a);
}

template int convert<int, double>(double); //  Function is instantiated
//template int convert<int>(double); //  Same as top


void t1(){

};

int main() {
    t1();


    return 0;
}