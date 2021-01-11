//
// Created by mtb on 1/10/21.
//

#include<iostream>
#include <utility>
using namespace std;
class Line;
class Point {
    double x, y;
public:
    Point(double _x=0, double _y=0){
        x =_x;
        y=_y;
    }
    double get_x()  const{
        return x;
    }
    double get_y() const {
        return y;
    }

    Point operator+(Point p) const{
        return Point {x + p.x, y+p.y };
    }
    ~Point()=default;
};

ostream &operator<<(ostream& os, const Point &p){
    cout << "Point(x="<< p.get_x() << ",y=" << p.get_y() << ")";

    return os;
}

class Line;
class Points
{
    Point *pts;
    int size;
    friend class Line;
public:
    Points(std::initializer_list<Point> _pts, int _size): size{_size}{
         pts = new Point[size];
         int i=0;
         for(auto p: _pts){
             pts[i] = p;
         }
    };

    Points (const Points& points){
        size = points.size;
        pts = new Point[size];
        for(int i=0; i<size; i++){
            pts[i] = points.pts[i];
        }
    }

    Point get_first() {
        return pts[0];
    }

    Point ship_right(Point p, int shift) {
        return p + Point({2, 0});
    };

    ~Points(){
        delete[] pts;
    }
};

class Figure{
public:
    enum Type {Line, Circle, Square, Rectangle};
    ~Figure(){}

    virtual void  print_properties() const
    {
        cout << "Undefined" << endl;
    };

    virtual Type get_type() = 0;
};


class Line: public Figure{
Point p1, p2;

public:
    Line(Point _p1, Point _p2){
        p1=_p1;
        p2=_p2;
    }
    Line(Points _pts){
        p1 = _pts.pts[1];
        p2 = _pts.pts[1];
    }
    void print_properties() const {
        cout << "Line(P1=" << p1 << ", P2=" << p2 << ")" << endl;
    }
    Type get_type() {
        return Type::Line;
    }

};

class Circle: public Figure
{
    Point center;
    double radius;
public:
    Circle(Point c, double r): center{c}, radius{r} {};

    void print_properties() const{
        cout << "Circle(radius=" << radius << ", center=" << center << ")" << endl;
    }
    Type get_type() {
        return Type::Circle;
    }

    ~Circle(){}
};


int main(int argc, char *argv[]){
    Point p1 {2.0, 3.0};
    Point p2 {2.0, 6.0};

    Points pts{{p1, p2}, 2};

    Point p3 = pts.ship_right(p1, 2);

    cout << p3 << endl;

    Figure *fg;
    Line ln{pts};
    Circle c{p1, 0.5};
    fg = &c;
    ln.print_properties();
    fg->print_properties(); // Without virtual Figure::print_properties

    return 0;
}