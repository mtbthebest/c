//
// Created by mtb on 12/30/20.
//

#include <iostream>
using  namespace std;

enum class Color{
    red, green=5, blue='A', orange
};

constexpr Color operator&(Color a, Color b) {
    return static_cast<Color>(static_cast<int>(a) & static_cast<int>(b));
}


void t1() {
//    Color c = 2;// Error
    Color c = Color::blue;

    int cc = static_cast<int>(c);
    cout << cc << endl;
    cout << (int )Color::orange << endl;
    cout << static_cast<int>( Color::red & Color::orange) << endl;
    cout << static_cast<int>( Color::blue & Color::orange) << endl;
}

enum class Flag: char {
    x=1, y=2, z=8
};

bool operator==(Flag a, Flag b) {
    return static_cast<bool>(static_cast<int>(a) == static_cast<int>(b));
}

ostream& operator<<(ostream &o, Flag a){
    cout << static_cast<int>(a);
}

void t2(){
    Flag f0{};
    cout << static_cast<int>(f0);
    Flag f1{f0};
    Flag f2 = static_cast<Flag>(2);
    f0 = static_cast<Flag>(2);

    cout << (f1 == f2) << endl;
    cout << (f0 == f2) << endl;

    Flag f3 = static_cast<Flag>(326); // Character 70

    cout << f3 << endl;

    int i = static_cast<int>(Flag::y);

    char d = static_cast<char>(f3);
    cout << i << endl;
    cout << d << endl;

    Flag t = Flag::x;
}

int  main(int arg, char **argv){
    t2();
    return  0;
}

