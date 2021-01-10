//
// Created by mtb on 1/7/21.
//

#include<iostream>
#include <vector>
using namespace std;

class Handle {
    int *p;
public:
    Handle(int *pp): p{pp}{}
    ~Handle(){
        cout << "deleted" << endl;
        delete p;}
    Handle(const Handle& a): p{new int{*a.p}}{};
};

int main(int argc, char *argv[]){
    Handle h{new int{99}};

//    Handle h1 = h; Deleted twice
//    Handle h1 = move(h); //Error Deleted twice

    Handle h1{h}; //Error Deleted twice

    return 0;
}

