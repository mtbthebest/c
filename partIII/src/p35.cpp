//
// Created by mtb on 6/6/21.
//
#include<iostream>

using namespace std;


struct Base{
    int x;
    Base(int a): x{a}{}
    virtual void print(){
        cout << "Base print " << endl;
    };


};

class Derived : public Base{
public:
    int y;

    Derived(int a, int b): Base{a},y{b}{}

    void print() override{
        cout << "Derived print " << endl;
    }

    void getView() {
        cout << " view " << endl;
    }

};

class Geometry{
public:
    virtual void get_element(){}
};


struct Point {
    double x, y;
};



void t1(){
    Base b{1};
    Derived d{3,2};

    Base *pb = &b;
    pb = &d;
//    pb->y = 4; Error
//    pb->print();

    pb = &b;

    Derived *pd = &d;

    pd->y = 10;

//    pd = &b; // Error Upcast
//    pd = pb;  // Error

    Base *pb2 = pd;
    pb = dynamic_cast<Base *>(pd); // Base must be polymorphic if downcast(not always check t2 where the target is not polymorphic). Same as     pb = pd;
    if(pb){
        pb->print();

        cout << "PB2: " <<endl;
        pb2->print();
        cout << "*****" << endl;
//        pb2->getView(); // Error no access except to virtual function
    }
    else{
        cout << "Error casting from derived to base" << endl;
    }


}

void t2() {
    Geometry *g1 = new Geometry{};
    Point *p = dynamic_cast<Point *>(g1);
//    p->x = 10;
//    p->y = 50;
    if(p){
        cout << "P is se" << endl ;
    }
    void *pg = dynamic_cast<void *>(g1);
//    void *pp = dynamic_cast<void *>(p); // Not possible
    delete g1;

}

int main(){
    t1();
    return 0;
}