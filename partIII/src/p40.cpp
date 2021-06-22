//
// Created by mtb on 6/19/21.
//

#include<iostream>
#include<vector>
using namespace std;

template<class T>

class Array{
    T *elements;
    int size;
    T *current;

public:
    int length=0;
    static constexpr char *name = "Array";
//    static const char *name = "Array"; // Error
//    const char *name =(const char *) "Array"; //Ok
//    static int ninstances = 0; // Error. Non constant initialized out of line
    static int ninstances;
    static int a; // Ok need only definition

    Array();
    ~Array(){
        delete elements;
        ninstances -=1;
    }

    void append(T val){
        *current = val;
        ++current;
        ++length;
    }

    int get_length() const{
        return length;
    };
};
template<class T>
Array<T>::Array(){
    size = 10;
    elements = new T[size];
    current = &elements[0];
    ++ninstances;

}

//class Array; Error Double Definition


template<typename T> int Array<T>::ninstances = 0;

int main(){

    Array<int>a1{};
    using IntArray = Array<int>;
    IntArray a2{};

    using F = float;
    using FloatArray = Array<F>;
    Array<F> a3;
    cout << Array<F>::name;

    const char *z = "Po";


    return 0;
}