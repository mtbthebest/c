//
// Created by mtb on 1/10/21.
//

#include<iostream>
using namespace std;


class Complex
{
double re, im;
public:
    Complex(double cr=0, double ci=0);

    ~Complex(){
//        cout << &re <<"Destroyed " << endl;
    }
    Complex operator+(const Complex &b);

    double get_real() const {
        return re;
    }
    double get_im() const {
        return im;
    }
};

Complex::Complex(double cr, double ci): re{cr}, im{ci}  {
//    cout << &re <<"Constructed " << endl;
}

Complex Complex::operator+(const Complex &b) {
//    cout << "op +" << endl;
    return Complex(re+b.re, im+b.im);
}

ostream &operator<<(ostream&os, const Complex &c){
    double im = c.get_im();
    string sgn = im >=0 ?"+": "-" ;

    cout <<  c.get_real() << sgn << abs(im) <<"i" << endl;
}

int main(int argc, char *argv[]){

    Complex c1{-1, 1};
    Complex c2{2,3};
    Complex c3{c1};
    Complex d{c1+c2 };
    cout << d;



    return 0;
}
