//
// Created by mtb on 6/20/21.
#include<iostream>
#include<vector>

using namespace std;

template<typename T, template<typename> class C>

class Xrefd{
    C<T>mems;
    C<T *>refs;

public:
    Xrefd(){
        cout << "Initialized" << endl;
    }
};

template<typename T>
using Vec = vector<T>;

template<typename T>
class Container{

};

class Entry{};
class Record{};
void t1(){
    Xrefd<Entry, Vec> x1{};
    Xrefd<Record, Container> x2{};
}

//template<typename T1=int, typename T2> // error
//class X1 {
//
//};
template<typename T1=int, typename T2=double> // error
class X1 {
};

void t2(){
    X1<int,double>v1;
    X1<double>v2;
    X1 v3;
}


template<typename Target=string,typename Source=string>
Target run(Source s){
    Target v{};
    return v;
}

void t3(){
    auto x1 = run<string, double>(1.2);
    auto x2 = run<string>(1.2);
    auto x3 = run(1.2);
}

int main() {
//    t1();
//    t2();
    t3();
    return 0;
}