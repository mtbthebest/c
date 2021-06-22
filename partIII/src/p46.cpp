//
// Created by mtb on 6/20/21.
//
#include<iostream>
#include <vector>
using namespace std;

class Record: public string{};
template<typename T, int max>
struct Buffer {
    T buf[max];
public:
// ...
};

template<typename T, int max>
T &lookup(Buffer<T, max> &b, const char *p){
    return b.buf[0];
};

string &f(Buffer<string, 128> &buf, const char* p)
{
return lookup(buf, p); // use the lookup() where T is string and i is 128
}

template<typename T>
T *create();

void f() {
    vector<int> v;
    int *p = create<int>();
//    int *q = create(); // Error argument cannot be deduced
}

template<typename T, typename U>
void f(const T*, U(*)(U));

int g(int);

void h(const char *p){
    f(p, g);
//    f(p, h); // Error can't deduce U

}
template<typename T>
void f(T i, T* p);

void gg(int i)
{
    f(i,&i);
//    f(i,"Remember!"); // Ambiguous T is int or const char
}

int main() {

    return 0;
}