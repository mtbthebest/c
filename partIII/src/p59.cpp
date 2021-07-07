//
// Created by mtb on 7/7/21.
//

#include<iostream>
#include <cstring>

using namespace std;

int global;


template<typename T>
T f(T a){
    global ++; // Ok in scope
//    ++u; // Error not in scope
//    return a; // Ok
    return g(a); // Ok. Dependent name. Definition of g position is irrelevant

}

int u;
template<typename T>
T ff(T a){
//    return g(X{}); // Error not g and X in scope
    return a;
}
struct X{};


X g(X&a){
    return a;
};
void t1(){
    f(X{});
    ff(X{});

};

template<typename T>
class Container{
    public:
    using value_type = T;

    T operator[](T a){
        return a;
    }
};

template<typename Q>
using Value_type = typename Q::value_type;

template<typename T>
void fct(T & c){
//    T::value_type z = 7; // c is a dependant name. Needs typename. See below
    typename T::value_type z = c[2];
    auto q = c[-1];
    Value_type<T> v1 = c[7];

    cout << z << " " << q << "  " << v1;


}




class Pool {
public:
    template <typename T>
    T *get() {
        T *z = new T{5};
        return z;
    }
    template <typename T>
    void release(T *z) {
        delete z;
        cout << "Deleted allocated z";
    }



};


void t3(){
   Container<int> x{};
    fct(x);
}

void t4() {
    Pool p{};
//    int *p1 = p.get(); // Error because member template

//    int *p1 = p.template get<int>(); // Ok
    int *p1 = p.get<int>(); // Ok
    cout  << *p1 << endl;

//    p.release(p1); // Ok
    p.template release(p1);

};


void h1(double){
    cout << "h1() function" << endl;
}
void h2(double ){
    cout << "h2() function double" << endl;

}

template <typename T>
int h(T a){
    h1(2);
    h2(10);
//    h3(10); // Error h3 not in scope
    h2(10); // Not int function but double
    return 0;
}

void h3(int ){
    cout << "h3() function "<< endl;
}
void h2(int ){
    cout << "h2() function int" << endl;

}

void t5(){
    h(4);
}
int main() {
    t5();


    return 0;
}


