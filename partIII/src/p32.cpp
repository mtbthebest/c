//
// Created by mtb on 6/6/21.
//
#include<iostream>
using namespace std;

struct Pos {
    double lat, longi;
};

class Satellite{
    public :
        virtual Pos  center() const = 0;
        virtual void debug(){
            cout << "Debug Satellite" << endl;

        };
    void transmit() {
        cout << "Satellite Transmit" << endl;
    }

};

class Displayed {
    public :
    virtual void draw() = 0;
    virtual void debug(){
        cout << "Debug Displayed" << endl;
    };
    void transmit() {
        cout << "Displayed Transmit" << endl;
    }
};

class Comm_sat: public Satellite, public Displayed {
    public :

    Pos  center() const override{
        return {0.0, 0.0};
    };
    void draw() override{
        cout << "Comm satellite" << endl;
    };
    void transmit() {
        cout << "Comm satellite Transmit" << endl;
    }

};

class Radio_sat: public Satellite, public Displayed {
public :

    Pos  center() const override{
        return {0.4, 0.4};
    };
    void draw() override{
        cout << "Radio Satellite" << endl;
    };
    void transmit() {
        cout << "Radio Transmit" << endl;
        Satellite::debug();

    }
};

void highlight(Displayed *d){
    d->draw();
}
Pos center_of_grav(const Satellite *s){
    s->center();
}
void f(Comm_sat &s) {
    s.draw();
    Pos p = s.center();
    s.transmit();
}

void t1() {
    Comm_sat c;
    Radio_sat r;
    f(c);
    highlight(&c);
    center_of_grav(&c);
    highlight(&r);

//    r.debug(); // Ambiguous
    r.Displayed::debug();
    r.Satellite::debug();
    r.transmit();
}

int main(int argc, char **argv){
    t1();
    return 0;
}
