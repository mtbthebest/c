//
// Created by mtb on 1/1/21.
//

#include <iostream>
using namespace std;


void t1() {
    float i= 5;
    int j= 5;
    double c = double{i};
//    float d{j}; // Error

    char x = 'z';
    int b = static_cast<int>(x);

    cout << b << endl;

//    int *p1 = &x; Error
//    int *p1 = static_cast<int*>(&x);  Error
    int *p1 = reinterpret_cast<int*>(&x);
    *p1 = 74;
    cout << p1 <<" - " << x << endl;

}

struct M{};

struct N:M{};

void t2() {
    M *m = new N; // Ok
//    N *n = m ; // Error
    N *n = static_cast<N*>(m) ; // Error

}

int main() {
    t2();
    return 0;
}
