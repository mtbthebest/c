//
// Created by mtb on 1/1/21.
//

#include <iostream>
#include <math.h>
using namespace std;

constexpr int square_root(int d){
    return sqrt(d) ;
};

void t1() {
    int x1 = 4;
//    constexpr int x2 = x1; // error
    const int x3 = 4;
    constexpr int x2 = 10; // error
    constexpr int x4 = x3;

//    constexpr int x5 = square_root(x1) // error;
    constexpr int x5 = square_root(x2);

    cout << x5 << endl;

    int x6 = square_root(x1);

    cout << x6 << endl;


}

double square_func(double d) {
    return pow(d, 2);
}

void t2() {
    const double t = square_func(4.);
    cout << t << endl;
    double t1 = 2.0;
    const double t2 = t1; // Ok for constants

    const string ss = "Hello";
    const string s1 = ss;
//    constexpr string s2 = ss;//Error

//    constexpr double y = square_func(t2); Error not constant
//    constexpr double y = t2; // Error

}

struct Point {
    int x, y, z;

    constexpr Point up(int d) const {
        return {x,y, z+d};
    }
    constexpr Point move(int dx, int dy) const{
        return {x+dx, y+dy};
    }

    Point move_left(int dx, int dy) const{
        return {x, y+dy};
    }

    constexpr int get_z() const{
        return z;
    }

};

ostream &operator<<(ostream &os, Point p) {
    cout << "Point(" << p.x << "," << p.y << "," << p.z << ")" << endl;
}

void t3() {
    Point t1{};
    cout << t1;
//    constexpr Point t2{t1}; // Error
    constexpr Point t2{3, 2, 4};
    cout << t2;
//    constexpr int z1 = t1.z; //Error
    constexpr int z2 = t2.z; //Error

    cout << z2 << endl;

    constexpr Point a[] = {
//            t1,
            t2,
            {1, 2, 3}
    };

    cout << a[1];
//    a[1] = 5; Error

    constexpr Point xy{0, square_root(4)};
    constexpr Point yz{t2.up(4)};

    cout << xy;
    cout << yz;

    const Point t5{t1.move(4,5)};

    cout << t5;
    cout << t5.move_left(3, 10);

    t1.move_left(4,5);

    constexpr int z3 = xy.get_z();
    cout << z2 + 5;

}

int main() {
    t3();
    return 0;
}
