//
// Created by mtb on 1/1/21.
//

#include <iostream>
#include <bits/unique_ptr.h>
#include <cstring>
#include <bits/std_function.h>
#include <cmath>
using namespace std;



int add_constant(int x, const int v) {
    return x + v;

}

class List {
    int elm[3];
public:
    List(const int v[]){
        for(int i=0;i<3; i++) {
            elm[i] = v[i];
        }
    }
    List(const List &l) {
        for(int i=0;i<3; i++) {
            elm[i] = l.get_elem(i);
        }

    }

    int get_elem(int i) const{
        return elm[i];
    }

    int *begin() {
        return &elm[0];
    }

    int *end() {
        return elm + 3;
    }

    void set_value(int i, int value) {
        elm[i] = value;
    }
};

ostream &operator<<(ostream& os, const List &l) {
    cout << "[" ;
    for(int i=0; i<3; i++){
        cout << l.get_elem(i);
        if(i<=1)
            cout<<", ";
    }
    cout << "]";

    cout << endl;


    return  os;
}
template <typename T>
using Func = std::function<T(T)>;

template<class T>
void map(T l, const std:: function<void(int *, int)>& q){
    int *p;
    int i = 0;
    for(int x:l){
        p =&x;
        q(p, (long )i);
        i++;
    }
}

void t1() {
    int a[] = {1,-2,3};
    List l(a);
    cout << l;

    std::function <void(int *, int )> filter= [&l](int *x, int i) mutable {
            *x = *x<0 ? 0 : *x;
            l.set_value(i, *x);
    };
    std::function <void(int *, int )> square= [&l](int *x, int i) mutable {
        *x = pow(*x, 2);
        l.set_value(i, *x);
    };
    map<List>(l,filter);
    map<List>(l,square);

    double (*p3)(int) = [](int a) { return sqrt(a); };

    cout << l;
    cout << p3(4);

}

int main() {
    t1();
    return 0;
}
