//
// Created by mtb on 7/7/21.
//

#include<iostream>

using namespace std;

void f(int){
    cout << "f() function int" << endl;
};
namespace N{
    class X{};
    void g(X, int){
        cout <<"g() function int" << endl;
    };
}

template<typename T>
void* ff(T t, double d){
    f(static_cast<int>(d));
    g(t, d);
    return &d;
}
auto x1 = ff(N::X{}, 1.1); // Bound to double

namespace N
{
    void g(X, double){
        cout <<"g() function double" << endl;

    }
}
int main() {

    ff(N::X{}, 1.1);
    return 0;
}


