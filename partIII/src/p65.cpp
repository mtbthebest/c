//
// Created by mtb on 7/7/21.
//Hierarchy

#include<iostream>
using namespace std;

template<class X>
struct set{

};

template<typename T>
class Ptr{
    T *p;
public:
    Ptr(T*){}
    Ptr(const Ptr&){
        cout << "Copying" << endl;
    };
    template<typename T2>
    explicit operator Ptr<T2>(){
        cout << "Conversion from T to T2" << endl;
        return Ptr<T2>{p};
    };

};

struct Point {
    double x,y;
};

class Shape {
    public:
    virtual void draw() = 0;
    virtual ~Shape(){};
};



class Circle: public Shape{
    Point &c;
    double r;
public:
    Circle(Point &p, double radius=0.):c{p}, r{radius} {}

    void draw(){
        cout << "Drawing Circle C" << endl;
    };

    ~Circle(){};

};

class Triangle: public Shape {
    Point a, b, c;
public:
    Triangle(Point aa, Point bb, Point cc) {
        a=aa;b =bb; c=cc;
    }
    void draw()
    {
        cout << "Drawing Triangle T" << endl;
    }
};

void f(set<Shape*>& s){}

void f(Shape* p, int n){
    for(int i=0; i!=n; i++)
        p[i].draw(); // Danger with Derived Circle
}


void t1() {
    Point a{0.0, 1.0};
    Circle c(a, 2.5);
    set<Circle *> cs{};
    set<Shape *> csh{};
//    f(cs); // Error.
    f(csh); // Ok set<Shape*> # set<Circle*>

}

void t2() {
    Point c1{},c2{} ,c3{};
    Circle im[3]={
            {c1, 1.0},
            {c2, 2.0},
            {c3, 3.0}
    };
    f(im, 3);// Im is transformed from: Circle[] -> Circle * -> Shape *
                // Only one circle is drawn
}

void f(Ptr<Circle> pc){
    Ptr<Shape> ps{pc}; // Ok. Circle *(T *) can be converted to Shape * (T2 *)
//    Ptr<Circle> pc2{pc}; // Ok
    cout << "-----" << endl;
//    Ptr<Circle> pc3{ps}; // Error

}
void t3(){
    Point center{};
    Circle *c = new Circle{center, 2.5};
    Ptr<Circle> pc{c};
    f(pc);
    delete c;
}

int main() {
    t3();
    return 0;
}


