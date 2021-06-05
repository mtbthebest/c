//
// Created by mtb on 1/1/21.
//

#include <iostream>
#include <cstdint>
using namespace std;

class NoCopy {
    NoCopy(const NoCopy&) = delete;
};

class MyError{};

void f(int n)
{
    switch (n) {
        case 0: throw MyError{};
//        case 1: throw NoCopy{}; // error
//        case 2: throw MyError; // Error

    }
}

void t1() {

    f(0);

}

void h(){
    cout << "h";
    throw MyError{};
    cout << "No error";
}

void g() {
    cout << "g";
    h();
}

void t2() {
    string name{"Hello"};
    try {
        g();
    }
    catch(MyError){
        cout << "Error detected in h";
    }
    cout << " End";
}
void foo() {cout << "Foo Top" << endl ;throw MyError{}; cout << "Foo Down" << endl;}
void boo() {cout << "Boo" << endl; };
void dd() {
    throw -1;
}
void goo() noexcept {cout << "Goo" << endl; dd() ; cout << "Goo End" << endl;}; // Call std::terminate

void test() {
        boo();
//        foo();
        goo();

}

void t3(){

    struct S{};

    constexpr bool b1{ noexcept(5 + 3) }; // true; ints are non-throwing
    cout << "b1" << b1 << endl;
    constexpr bool b2{ noexcept(foo()) }; // false; foo() throws an exception
    cout << "b2" << b2 << endl;

    constexpr bool b3{ noexcept(boo()) }; // false; boo() is implicitly noexcept(false)
    cout << "b3" << b3 << endl;

    constexpr bool b4{ noexcept(goo()) }; // true; goo() is explicitly noexcept(true)
    cout << "b4" << b4 << endl;

    constexpr bool b5{ noexcept(S{}) };   // true; a struct's default constructor is noexcept by default
    cout << "b5" << b5 << endl;
    try{
        test();
    }
    catch(MyError){
        cout << "Error";
    }
    catch(...){
        cout << "Dead";
    }

}

int sum()
try{
    throw MyError{};
}
catch(...){
    return 5;
}
void t4(){
    cout << sum();
}

void t5() {
    char a = 0x4A;
    cout << a;
}


int main() {
    t5();
    return 0;
}
