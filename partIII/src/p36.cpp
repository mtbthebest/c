//
// Created by mtb on 6/6/21.
//

#include<iostream>

using namespace std;


struct Base{
    int x;
    Base(int a): x{a}{}

};

class Derived : public Base{
public:
    int y;

    Derived(int a, int b): Base{a},y{b}{}

    void getView() {
        cout << " view " << endl;
    }

};

class Derived2: public Base{

};

void t1(){
    Base b = Base(1);
    Derived d=Derived(0, 2);

//    Derived &d2 = dynamic_cast<Derived&>(b); // Error not possible downcast
    Derived &d2 = dynamic_cast<Derived&>(d);


}

int main(){
    t1();
    return 0;
}