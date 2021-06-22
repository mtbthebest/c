//
// Created by mtb on 6/20/21.
//
#include<iostream>
#include <vector>

using namespace std;

template<typename T, typename C>
T get_nth(C& p,int n){
    return p[n];
}

struct Index{
    int val =0;
    operator int() const{
        return val;
    }
};

void f(vector<int>& v, short s, Index i){
    int i1 = get_nth<int>(v, 2);
    int i2 = get_nth<int>(v, s);
    int i3 = get_nth<int>(v, i);
    cout << i1 << " " << i2 << " " << i3 << endl;
}

int main() {
    vector<int> v{1,2,3,4};
    Index in{2};
    short int i = 2;
     f(v, i, in);
    return 0;
}