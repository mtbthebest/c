//
// Created by mtb on 1/1/21.
//

#include <iostream>
#include <bits/unique_ptr.h>
#include <cstring>
using namespace std;

void t1() {
    int x = 5;
    int y = (x++);
    int z = (++x);
    cout << "X: " << x << ",Y: " << y << ",Z: "<< z << endl;
    int w = (y-=1);
    cout << "W: " << w << ", Y: " << y << endl;


}

struct Point {
    int x, y, z;

};
ostream &operator<<(ostream &os, Point p) {
    cout << "Point(" << p.x << "," << p.y << "," << p.z << ")" << endl;
}
void t2(){
    Point p1{1};

    Point *p2 = new Point{1,2,3};

    cout << p2 << endl;

    int *z = new int{1};

    cout << z << endl;

    delete z;

    int a[] = {1,2,3};
    unique_ptr<int []> q {new int[10]};
    cout << &q << endl;

    auto p = new Point;
    cout << *p ;

    int y = 5;
    auto zz = new int{y};
//    auto *zz = &y;
    cout << zz << " , " << &y << endl;
    *zz = 10;
    cout << *zz << endl << y;

    delete zz;
    delete p, z;
    delete p2;
};

char *copy(const char *p){
    int length = strlen(p);
    char *s = new char[length + 1];
    strcpy(s, p);
    cout << &s << endl;
    return s;
}

void t3(){
    char *p = copy("Hello");
    cout << p << &p << endl;
    delete[] p;

}

int main() {
    t3();
    return 0;
}
