//
// Created by mtb on 1/3/21.
//

#include<iostream>

using namespace std;

struct Link {
    Link *pre;
    Link *suc;
    int data;

    Link *insert(int x){
        return pre = new Link{pre,this, x};
    }
};


int main(int argc, char *argv[]){
    Link *ln;
    Link *ln2 = ln->insert(4);
    cout << ln2;
    cout << ln->pre;

    return 0;
}