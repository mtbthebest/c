//
// Created by mtb on 12/30/20.
//

#include <iostream>
using  namespace std;

struct Point {
    int x, y, z;

    void print(){
        cout << "Point(" << x << ", " <<  y << ", " << z << ")"<< endl;
    }

};

void t1() {
    Point p{1,2,3};
    p.print();

    using pPoint = Point *;
    pPoint pp = &p;
    pp->print();
    Point p2{3,3,4};
    p2.print();
    p2 = p; // Possible for structure but not for array
    p2.print();

    Point p3;
    Point p4{}; // 0,0,0
    Point p5{1}; // 1,0,0
    p5.print();
}

ostream& operator<<(ostream& os, Point p){
    cout << "Printing: ";
    cout << "Point(" << p.x << ", " <<  p.y << ", " << p.z << ")"<< endl;

}

class Node {
    const Node *parent, *child;
//    Node child; // Error
public:
    void set_parent(const Node *p) {
        parent = p;
    }
};

void t2() {
    Node c{};
    Node *p = &c;
    c.set_parent(p);
}

struct Points {
    Point p[10];
};

void t3(){
    Points pt{{{4,5,6}, {1}, Point()}};
    pt.p[0].print();
    pt.p[1].print();
    cout << pt.p[2];
}

struct Student {
    int id:1;
    bool res: 1;
    int : 3;
};

void t4() {
    Student t{1, false};
}

enum Type {str, num};

union Value {
    char *s{"Hello"};
    int i;
};

struct Entry {
    char *name;
    Type t;
    Value v;
};

void t5() {
    Value v{};
    cout << v.i << endl;
    cout << v.s << endl;

    v.i=7;

    Value v2 = v;
    Entry e{"Entry", num, v};
    cout << e.v.i << endl;
    cout << v2.i << endl;

}

class Entry2 {
    enum Tag {number, text};
    Tag type;
    union {
        int i;
        string s;
    };
public:
    struct E{};

    string name;

    Entry2();
    ~Entry2();

    void set_number(int n){
        if(type == Tag::text)
        {
            s.~string();
            type = Tag::number;
        }
        i = n;
    }

    void set_text(const string &ss){
        if(type == Tag::text)
        {
            s = ss;
        }
        else {
            new(&s) string{ss};
            type = Tag::text;
        }
    }

    Entry2 & operator=(const Entry2 &e) {
        if(type == Tag::text && e.type == Tag::text){
            s = e.s;
            return *this;
        }

        if(type == Tag::text)
            s.~string();

        switch (e.type) {
            case Tag::number:
                i = e.i;
                break;
            case Tag::text:
                new(&s) string{e.s};
                type = e.type;
        }

        return *this;
    }
};

void t6() {
    Entry2 e;
}

int  main(int arg, char **argv){
    t6();
    return  0;
}

