//
// Created by mtb on 12/30/20.
//

#include <iostream>
#include "stdio.h"
#include "cstring"
using  namespace std;

void t1(){
    char c = 'a';
    cout << c << endl;
    char *p = &c;
    cout  << (void *) p << endl;
    cout  << &p << endl;
}

void t2(){
    int i = 10;
    int *p = &i;

    cout << p;
}

void t3() {
    int a[] ={1,2,3};
    int *p;
//    p = a;
    p = &a[0];
    for(int i=0; i<3; i++){
        *p = *p + 3;
        cout <<p << " " <<&a[i] << " " << *p << endl;
        p++;
        cout <<p << endl;
    }
    for(int i=0; i<3; i++){
        cout <<a[i] << ", ";
    }
    cout <<p << endl;
};

void t4(){
    char* a[] ={"J", "u", "l", "y", "\0"};
    for(auto c: a){
        cout << c;
    }
    cout << endl;
    for(char *c: a){
        cout << &c;
    }
    cout << endl;
    char b[10] = {'c','p', '\0'};

    for(char c:b){
        cout << c;
    }

    char *p ="Central";
    // char pp = 'c'; "c" is error is a string not a character
    cout << endl;

    cout << *p;
    cout << endl << strlen(p);

}

void t5() {
    char *t = "Bohr"; // Each character is a constant
//    t[0] = 'e'; // Error
    cout << t << endl;

    char p[] ="Bohr";
    p[0] ='P';
    cout << p << endl;
}
void t6() {
    string s ="\w"; // print(w) not \w;
    cout << s << endl;

    string ss, sss, p;
    ss = R"(\w\\w)";
    sss = R"("Quotes")";
    cout << ss << ", " << sss << ", " <<"\"Quotes\"" << endl;

    p = u8R"(***(" hdhdh"))";
    cout << p;
}

void t7() {
    char x= 'x', y='y', z = 'z';
    char *p, *q, *r;
    p = &x;
    q = &y;
    r = &z;

    cout << (void *) p << ", " << (void *) q << endl;
    printf("%p", p);
    cout << (void *) (q-p) << endl;
    cout <<  (q-p) << endl;
    cout << (r - p) << endl;
    cout << (void *)(r - p) << endl;
}

int  main(int arg, char **argv){
    t7();
    return  0;
}

