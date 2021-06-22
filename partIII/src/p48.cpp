//
// Created by mtb on 6/20/21.
//
#include<iostream>
#include <vector>

using namespace std;

template<typename T>
T maximum(T a, T b) {
    return a > b ? a:b;
};

const int s = 7;

double maximum(char a, double b){
    return maximum<double>(a, b);

}

void k() {
    cout << maximum(2,5) << endl;
    cout << maximum("a", "b")<< endl;
    cout << maximum(2.0, 4.0)<< endl;
    cout << maximum(s, 8)<< endl;

//    cout << maximum('a', 8)<< endl; // Ambiguous without overloading
    cout << maximum<int>('a', 8) << endl;
    cout << maximum<char>('a', 8) << endl;
    cout << maximum('a', 8.) << endl;
//    cout << maximum(2.7, 8)<< endl; // Ambiguous
    cout << maximum(2.7, static_cast<double>(8))<< endl;


}

template<typename Iter>
typename Iter::value_type mean(Iter first, Iter last) {
    return 0;
}



void g(){
    int k = 0, n = 4;
    int *p = &k;
    std::vector<int> v(5, 0);
    auto x = mean(v.begin(), v.end());
//    auto y = mean(p, p+n); // int *p does not have value type member. For fixing declare T mean(T∗,T∗);


}

template<typename Iter>
Iter meanx(Iter first, Iter last) //call 1
{
    typename Iter::value_type{*first};
// ...
}

template<typename T>
T*meanx(T*, T*);

void h()
{
    int k = 0, n = 4;
    int *p = &k;
    std::vector<int> v(5, 0);
    auto x = meanx(v.begin(),v.end()); // call 1
//    auto y = meanx(p,p+n); // RunTimeError ambiguous
}

template<typename T>
class B{/* */};

template<typename T>
class D: public B<T>{/* */};

template<typename T>
void f2(B<T>*){};

void ff(B<int> *pb, D<int>*pd){
    f2(pb);
    f2(pd);
}

void l(){
    B<int> *b = new B<int>{};
    D<int> *d = new D<int>{};

    ff(d, d);
    delete b;
    delete d;
}

int main() {
//    k();
//    g();
//    h();
    l();
    return 0;
}