//
// Created by mtb on 6/6/21.
// Pointer member function
#include<iostream>
using namespace std;
class Integer;

enum Op {
    add, sub, mul
};


class Integer{
    int val;
public:
    Integer(int v=0);

    Integer(const Integer& v){
        val = v.val;
    }

    Integer& operator=(const Integer& v)= default;

    int getValue() const{
        return val;
    }
    void setValue(const int t){
        val = t;
    }
};

Integer::Integer(int v){
    val = v;
}

ostream& operator<<(ostream& os, const Integer &v) {
    cout << "Integer(" << v.getValue() << ")" <<  endl;
    return os;
}
class Session{
public:
    Integer add(const Integer&a , const Integer&b){
       return Integer{a.getValue()+ b.getValue()};
    }

    Integer run(Op op, const Integer& a, const Integer& b) {
        using op_func= Integer(Session::*)(const Integer& , const Integer& );
        Integer(Session::*pmt )(const Integer& , const Integer& );
        op_func f;
        switch(op){
            case Op::add:
                pmt = &Session::add;
//                f = &Session::add;
                break;
            default:
                throw std::runtime_error{"Error"};
        }
        return (this->*pmt)(a, b);
//        return (this->*f)(a, b);

    }
};

int main(int argc, char **argv){
    Integer i1{5};
    Integer i2{};
    Session sess;
    i2 = i1;
    i2.setValue(-3);
    cout << i1 << i2 << endl;

    Integer i3 = sess.run(Op::add, i1, i2);

    cout << i3;
    return 0;
}
