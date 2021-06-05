//
// Created by mtb on 1/3/21.
//


#include<iostream>

using namespace std;

class Point
{
    int x,y,z;
    mutable int v = 0;
    int *cache;

public:
    explicit Point(int x=0, int y=0, int z=0);
    ~Point(){}
    int get_x() const {
        return  x;
    }

//    int set_x(int _x) const  {
//        x = _x;
//    } //----------Error-----------------

    int set_v(int _x) const  {
        v = _x;
        return _x;
    }

    int set_y() const {
//        cache = &x; Error pointer
         *cache = 7;

        return 7;

    }

};



Point ::Point(int x, int y, int z):  x{x}, y{y}, z{z}{}

int main(int argc, char *argv[]){

//    Point p{1,2,3}; Ok
//    Point p; // ok
    Point p{4,2}; // Ok
    Point p2 = p; // Copy the members by default

//    Point p3= -5; // Ok without explicit
    Point p3 {-5}; // ok

    const Point p4{10};

    cout << p.get_x() << endl;
    cout << p3.get_x() << endl;
    cout << p.set_v(10) << endl;
    cout << p.set_y() << endl;


    cout << "Done";

    return 0;
}
