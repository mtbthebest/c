//
// Created by mtb on 1/10/21.
//

#include<iostream>
#include <utility>
using namespace std;
class Variable
{
    string name;
    double value;
public:
    Variable(string n, double v=0);

    Variable operator*(double) const;
    Variable operator/(double) const;
    Variable operator++(int) const;
    bool operator=(const Variable&)=delete;

    ~Variable()= default;

    string get_name() const {
        return name;
    }

    double get_value() const {
        return value;
    }
    void set_value(double v){
        value = v;
    }

};

Variable::Variable(string n, double v): name{std::move(n)}, value{v} {}

Variable Variable::operator*(double c) const {
//    cout << "Hello";
    return Variable(this->get_name(), c * this->get_value());
}

Variable Variable::operator/(double c) const {
   return Variable(this->get_name(),  this->get_value() / c);
}

Variable Variable::operator++(int i) const {
    return  Variable(this->get_name(),  this->get_value()+ ++i);
}

Variable operator+=(Variable a, const Variable &b){
    a.set_value(a.get_value() + b.get_value());
    return a;
}

ostream& operator<<(ostream&os, const Variable&v) {
    cout << "Variable(" << v.get_name() << "=" << v.get_value() << ")" <<endl;
}

Variable operator*(double c, const Variable& v){
    return Variable(v.get_name(), c * v.get_value());
}
//Variable operator*( const Variable& v, double c) {
//    return Variable(v.get_name(), c * v.get_value());
//}

int main(int argc, char *argv[]){
    Variable x1{"x", 2};

    Variable x2 = 2*x1;
    cout << x2;
    Variable x3{x2*(double )2.};
    Variable x4{x1/2};
    cout << x3;
    cout << x4;
//    x4= x3; // Error Deleted
    const Variable x5 = x2++;
    cout << x5;
    Variable x6={x1+=x2}; // temp = x1, temp +=x2

    cout << x1;
    cout << x6;

    return 0;
}