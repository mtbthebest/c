//
// Created by mtb on 7/7/21.
//

#include<iostream>
using namespace std;

void g(int){
    cout << "g() global function" << endl;
}

struct B {
    void g(char){
        cout << "B::g() function" << endl;
    }
    void h(char){
        cout << "B::h() function" << endl;
    }

};

template<typename T>
class D: public B {
public:
    void h(int){
        cout << "D::h() function" << endl;
    }
    void f(){
        g(2);
        h(2);
    }
};

template<typename T>
class D2: public T {
public:
    void h(int){
        cout << "D2::h() function" << endl;
    }
    void f(){
        g(2); // Careful
        h(2);
    }
};
void g2(int){
    cout << "g2() global function" << endl;
}


struct B2 {
    using Type = int;
    void g(char){
        cout << "B2::g() function" << endl;
    }
    void h(char){
        cout << "B2::h() function" << endl;
    }
    void g2(char){
        cout << "B2::g2() function" << endl;
    }
};

template<typename T>
class D3: public T {
public:
    typename T::Type m;
//    Type m2; // Error
    void h(int ){
        cout << "D::h() function" << endl;
    }
    using T::g2; // Fix confusion with line 74
    void f(){
        this->g(2); // Fix confusion with line 74
        g(2); // Careful
        h(4);
        g2(2);
    }
};

int main() {
    (D<int>{}).f();
    std::cout << "------------" << endl;
    (D2<B>{}).f();
    std::cout << "------------" << endl;

    (D3<B2>{}).f();
    return 0;
}


