//
// Created by mtb on 6/19/21.
// Multiple Inheritance

#include<iostream>

using namespace std;


class CommonBase{
public:

    CommonBase()= default;;
    virtual void print() const{
        cout << "Base print " << endl;
    };

};

class SeparateBase: public virtual CommonBase {
public:

    SeparateBase()= default;

    void print() const override{
        cout << "SeparateBase print " << endl;

    }
};

class D1: public SeparateBase{

};
class D2: public SeparateBase{

};

class D3: public D1, public D2{
public:
    void print() const override {
        cout << "D3 print " << endl;
    }
};



void t1(){
    CommonBase cb{};
//    D1 *d1 = dynamic_cast<D1*>(&cb); // Downcast polymormisph required error
    D1 d1{};

    CommonBase *pcb = & cb;
    pcb = &d1;
    pcb = &cb;

    pcb = dynamic_cast<CommonBase*>(&d1); // Ok. Upcast
    pcb = dynamic_cast<CommonBase*>(&cb);

    D3 d3{};
    pcb = &d3; // Ok

    pcb = dynamic_cast<CommonBase *>(&d3); // ok
    if(pcb){
        cout << "D3 conversion ok" << endl;
    }

//    SeparateBase *sb = dynamic_cast<SeparateBase *>(pcb); // CommonBase is not polymorphic. Remove virtual for test

    pcb = &d3;
    SeparateBase *sb;

//   sb = dynamic_cast<SeparateBase *>(pcb);
//    if(sb){
//        cout << "SB conversion ok" << endl;
//    }
//    else{
//        cout << "SB conversion not ok. Because 2 sub-objects SeparateBase" << endl;
//    }
//     D3 *dd3 = dynamic_cast<D3*>(sb);

}

void t2(D3 &d3){
    D1 *d1 = &d3;
    cout << (void *) d1 << endl;

    D3 *dd3 = static_cast<D3*>(&d3);
    dd3 = dynamic_cast<D3*>(&d3); //Ok Run time checked

    CommonBase *b = &d3;
    D1 *dd1 = &d3;
    b = static_cast<CommonBase*>(&d3);
    b->print();
//    dd3 = static_cast<D3*>(b); // Error casting because virtual base
//    dd1 = static_cast<D3*>(b); Error
    dd3 = dynamic_cast<D3*>(b); // Must be polymorphic;
}
void t3(void *p){
    CommonBase *b = static_cast<CommonBase *>(p);

    b->print();
    SeparateBase *sb = static_cast<SeparateBase*>(p);
//    sb = dynamic_cast<SeparateBase*>(p);// Error for dynamic cast
    sb->print();

    const D3* dd3 = const_cast<D3*>(static_cast<D3*>(p));
    dd3->print();
}
int main(){
    t1();

    D3 d3{};
    t2(d3);
    t3(&d3);
    return 0;
}