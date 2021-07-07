//
// Created by mtb on 7/7/21.
//

#include<iostream>

using namespace std;


namespace N {
    class A{};
    char f(A){
        return 'a';
    }

}
char f(int){
    return 'b';
};
template<typename T>
char g(T t){
    return f(t);
}

char f(double) {
    return 'c';
}

void t1() {
        char c1 = g(N::A());
        char c2 = g(2);
        char c3 = g(2.2); // Call g(int)


        cout << c1 <<  endl;
        cout << c2<<  endl;
        cout << c3 <<  endl;
}

int main() {
    t1();
    return 0;
}


