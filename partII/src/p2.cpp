//
// Created by mtb on 12/29/20.
//

#include <iostream>
using  namespace std;

void t1(){

    // Char is signed   -128 ~ 127

    char c = 72;
    std::cout <<c << endl;
    char cc = 128;
    cc = -129;
    cc = 325; // E truncating
    std::cout <<cc << endl;

//
//    // Unsigned char is between  0 ~ 255
//
    unsigned  char d =   127;
    d = -125;
    d = -256;
    std::cout << d << "  " << static_cast<int>(d) << endl;
//
    // Unsigned char is between  -128 ~ 127
    signed   char  e = 127;
    std::cout <<  e << endl;


}

void  t2() {
    wchar_t  p =69;
    std::cout <<  p << endl;
    std::cout << sizeof(p) << endl;

    char16_t  z =72;
    std::cout <<  z << endl;
    std::cout << sizeof(z) << endl;
}

void t3() {
    for (int i=0; i<10; i++){
        std::cout << '0' + i << ", ";
    }
    std::cout  << endl;
    for (int i=0; i<10; i++){
        std::cout << static_cast<char >('0' + i) << ", ";
      }
    std::cout << endl;
    std::cout << static_cast<char >(49) << endl;
    std::cout << (char )50 << endl;

}

void t4() {
    char c = 255; // -1 int
    c= 128; // -128 int
    c = 257  ; // 1 int

    int i = c;

    std::cout << i;
}

void  t5() {
    char c = 'a';
    unsigned char uc = 'a';
    signed char sc = 'a';
    char *p ;
    p = &c;
//    p = &uc; // No pointer conversions
//    p = &sc; // No pointer conversions

    unsigned  char *pp = & uc;
    cout << &p << ", " << *p << endl;
    cout << &pp << ", " << *pp << endl;

}

void  t6() {
    char c; unsigned  char  uc ; signed  char  sc;
    c =-120;
    sc = c;
//    sc= -190; // 256 - 190
    uc = c;
//    uc =sc;
    cout << c  << ", " << uc << "," << sc << endl;
    cout << c  << ", " << static_cast<int> (uc) << "," << sc << endl;
    cout << c  << ", " << (uc) << "," << sc << endl;
}

void t7() {
        std::cout << '0' << "," <<int('0') << endl;
        std::cout << (char )48;
}


void t8() {
    char t[] ="\137";
    char t2[] ="a\x1f\6955\x01";
    char t3[] ="\x30";  //48 in decimal 'a' in ascii
    char t4[] ="\x4a";  //
    char t5[] ="\xah";  //
    char t6[] ="\1202";  //48 in decimal 'a' in ascii 6* 8 + 0*0

//    cout << t << endl;
//    cout << t2 << endl;
//    cout << t3 << endl;
//    cout << t4 << endl;
    cout << t5 << endl;
    cout <<"t6:    " << t6 << endl;
}

int  main(int arg, char **argv){
//    t1();

//    t2();

//    t4();

//    t5();

    t6();

    t8();

    return  0;

}

