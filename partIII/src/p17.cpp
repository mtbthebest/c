//
// Created by mtb on 1/10/21.
//

#include<iostream>
using namespace std;
class X
{

public:
    X()=default;

    explicit operator bool() const {
//    operator bool() const {
        return true;
    }

    ~X()= default;
};
int main(int argc, char *argv[]){

    X x{};
    if(x)
        cout << "True";
//    bool q = x; // Error with explicit

    return 0;
}