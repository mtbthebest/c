//
// Created by mtb on 7/7/21.
//Metaprogramming

#include <iostream>
using namespace std;
template<typename... Types>
void f(Types... args){}
template<typename... Bases>
class X : public Bases...{
public:
    X(const Bases&... b): Bases(b)...{
        cout << "X is initialized" << endl;
    }
};

struct Bx{
    Bx(int k){
        cout << "Bx " << k << endl;
    }
};
struct By{
    By(int k){
        cout << "By " << k << endl;
    }
};
int main() {
    f();f(1);f(1,'c');
    X<>x0;
    X<Bx>x1(Bx{1});
    X<Bx, By>x2(Bx{1}, By{2});

    return 0;
}
