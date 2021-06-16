//
// Created by mtb on 6/6/21.
//
#include<iostream>

using namespace std;


class W{
public:
    virtual void draw(){
        cout << "Draw W" << endl;
    };

    virtual void prompt() = 0;
    virtual void setVal(int) = 0;
};

class W1: public virtual W{

    protected:
    void on_draw() {
        cout << "On draw W1" << endl;
    }
public:
    void draw() override{
//        cout << "Draw W1" << endl;
        W::draw();
        on_draw();
    }
    void setVal(int) override{

    }

};
class W2: public virtual W{

protected:
    void on_draw() {
        cout << "On draw W2" << endl;
    }
public:
    void draw() override{
//        cout << "Draw W2" << endl;
        W::draw();
        on_draw();
    }
    void prompt()  override{

    }


};

class D: public W1, public W2 {
protected:
    void on_draw() {
        cout << "On draw D" << endl;
    }
public:
    void draw() override{
//        cout << "Draw W2" << endl;
        W::draw();
        W1::draw();
        W2::draw();
        on_draw();
    }
    void prompt()  override{

    }

};

int main(){
//    W1 w1;
//    w1.draw();
    D d;
    d.draw();

//    W2 w2; // Error

    return 0;
}