//
// Created by mtb on 12/30/20.
//

#include <iostream>
#include "cstring"
using  namespace std;


void t1() {
    int v = 5;
    int &x = v;
    int &y = v;
    v = x -1 ;
    const int z = x+ y;
    cout  << z << endl;

    int *w = &x;
//    w = &v;
    x -= 5;
//    &x = v; Error
    cout << w << endl;
    *w -= 3;
    cout << x << endl;

}

int t(int n =1){
    const int a = 5*n;
    cout << &a << endl;
    return a;
}

void t2() {
    int&& x = 10;
    int y= 5;
//    int &z{10}; // Error
//    int &&z{y}; // Error lvalue
    int &&z{t()};
    cout << z << ", "<< &z << endl;

    int *w ;
    int q = t();
    w = &q;
    cout << w << endl;
}

double t(double &&q){
    return q;
}

void t3(){
    double &&z = t(5.);
    cout << z << endl;
}


class Point {
    int x{}, y{};
public:
    Point() : x{0}, y{0}{};
    Point(const Point &p): x{p.x}, y{p.y}{
        cout << "Initialized" << endl;
    }

    void add(int _x=0, int _y=0) {
        x += _x;
        y += _y;
    }

    void print() {
        cout << "X: " << x << " , " << "Y: "<< y<< endl;
    }
    Point(Point &&p) {
        x = p.x;
        y= p.x;
        cout << "Moving";
        p.x = p.y = 0.0;
    }
    Point operator+(int b){
        x +=b;
        y += b;
        cout << "Adding" << endl;
        return *this;
    }
    ~Point()= default;;
};

void t(Point &&r) {
    r.print();
}

void t(Point &r) {
    cout << "Left ";
    r.print();
    cout << endl;
}

void t4(){
    Point p1 = Point();

    p1.add(5);
    p1.print();

    Point p2 {p1};
    p2.print();
    Point p3(p2 + 10);

    t(Point() + 6);
    t(p3);

}

void t5() {
    using lr_i = int &;
    int v = 5;
    int &x = v;
    lr_i y=x;
    y = 10;
    cout << v;
    cout << endl;
//    int &p[] = {1,2}; // Error references cannot be set for arrays
    int *p[] = {&v};
    cout << p[0] << endl;
}

int  main(int arg, char **argv){
    t5();
    return  0;
}

