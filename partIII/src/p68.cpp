//
// Created by mtb on 7/7/21.
//Metaprogramming

#include<iostream>
#include<array>
using namespace std;

constexpr int on_stack = sizeof(string);

template<typename T>
struct OnHeap{
    T *p;
    public:
    OnHeap(): p(new T{}){}
    ~OnHeap(){delete p;};

    OnHeap(const OnHeap& hp) = delete; // No copy
    OnHeap operator=(const OnHeap& ) = delete;   // No Copy

    T &operator*(){return*p;}
    T * operator->(){return p;}
};

template<typename T>
struct Scoped{
    T x;
public:
    Scoped(const Scoped& hp) = delete; // No copy
    Scoped operator=(const Scoped& ) = delete;   // Copy

    T& operator*(){return x;}
    T* operator->(){return &x;}
};

template<typename T>
struct Obj_Holder{
    using type = typename std::conditional<sizeof(T) <= on_stack,
                                            Scoped<T>,
                                            OnHeap<T>
                                            >::type;



};



void t1(){
    typename Obj_Holder<double>::type v1{};
    typename Obj_Holder<array<double,  200>>::type v2;

//    OnHeap<array<double, 200>> v3{v2};

//    Scoped<double> v3{v1};
//    Scoped<double> v3 {};
//    v3 = v1; // Error
    *v1 = 10;
    cout << *v1 << endl;
    (*v2)[10] = 5;
    cout << (*v2)[10] << " "<< (*v2)[0] << endl;
}

template<typename T>
constexpr bool is_big() {
    return 100 < sizeof(T);
}

template<typename T>
using Obj_holder2 = std::conditional<is_big<T>(), Scoped<T>, OnHeap<T>>;

void t2(){
     Obj_holder2<double> v1;

}

int main() {
//    cout << on_stack << " " << sizeof(Obj_Holder<char>);

    t2();
    return 0;
}
