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
    Base *pb = &b;
    Derived &d2 = dynamic_cast<Derived&>(d);
//    Derived *d2 = dynamic_cast<Derived*>(pb); // Downcast Base must be polymorphic

 /*
    Derived *pd = &d2;
    Base *pb1 = dynamic_cast<Base*>(pd);
    // Ok upcast without polymorphism
    */
    try{
        d2.getView();
    }
    catch(bad_cast &b){
        cout << "Error " << b.what();
    }
}

int main(){
    t1();
    return 0;
}