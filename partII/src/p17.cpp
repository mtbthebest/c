//
// Created by mtb on 1/1/21.
//

#include <iostream>
using namespace std;

struct Range_error{};
class X {
public:
    X(){
        cout << "Constructor" << endl;
    };
    ~X(){
        cout << "Destructor" << endl;
    }
};

void t1() {
    int n=6, limit=5;
    X x{};
    if(n>limit) throw Range_error{};
    cout << "No error";
}

int main() {
    t1();
    return 0;
}
