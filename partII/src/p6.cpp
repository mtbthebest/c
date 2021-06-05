//
// Created by mtb on 12/30/20.
//

#include <iostream>
#include "cstring"
using  namespace std;

int sum(const int *);

void t1() {
    int b[] = {1,2,3};
    int c = sum(b);

    cout << c << endl;
}

int sum(const int *a) {
    int d =0;
    for(int i=0; i<3; i++){
        d += a[i];
    }
    return d;

}

void t2() {
    int v1[3]{1,2,3};
    const int v2[3] {1,2,3}; // v2[i] is a const
    v1[0] = -1;
    for(int i=0; i<3; i++){
        cout << v1[i]<< ",";
    }
    // v2[2] = -1;Error
    cout << endl;
}

void t3() {
    char s[]{"Hello"};
    const char *p = s; // Pointer to constant object
    char *q = s; // Pointer to constant object
//    p[0] = 'P'; // Error
    q[0] = 'D';
    cout << q[0] << endl;

    char *const r = s; // r is constant
    r[0] ='H';
    cout << s;
//    r= p;// Error

}

void t4() {
    int a = 1;
    const int aa= 2;

    int *p= &a;
    cout << p << "," << &a <<", " <<*p << endl;
//    p = &aa;// Error

    const int *pp = &a ; //Ok point to constant or int allowed
//    *pp =4;//Error
    cout << pp << "," << &a << ", " <<*pp << endl;

    pp = &aa;
    cout << pp << "," << &aa << ", " <<*pp << endl;

    int *const ppp = &a;
//    *ppp=5; //Ok
    cout << ppp << "," << &aa << ", " <<*ppp << endl;
//    ppp = &aa;Error constant pointer


}

int  main(int arg, char **argv){
    t4();
    return  0;
}

