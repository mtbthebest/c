//
// Created by mtb on 6/19/21.
// Friends templates

#include<iostream>

using namespace std;

template<typename T> class  A;

template<typename T>
class B{
    T a;
    string getClass() const{
        return "B";
    };
    int z = -1;
    friend class A<T>;
public:
    B(T aa){
        a = aa;
    }
    T getVal(){
        return a;
    }

};
template<typename T>
class  A{
public:
     B<T> buildClass(T aa){
        B<T> b{aa};
        b.a -= 1;
        return b;
    }


};




int main(){
    B<int> b{{50}};
    cout << b.getVal() << endl;
    A<int> a{};
    B<int> bb = a.buildClass(10);
    cout << bb.getVal() << endl;

    return 0;
}