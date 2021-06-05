//
// Created by mtb on 1/10/21.
//

#include<iostream>
using namespace std;
class X
{
    char v;
public:
    X(int i){
        cout <<"Setting " << i << endl;
        v = i;
    };

    X& operator=(int i) {
        cout <<"Equal " << i << endl;
        v =i;
    }
    operator int() const { // b-a
        cout << "Int : "<<endl;
        return v;
    }
    ~X()=default;
};
int main(int argc, char *argv[]){
    X a = 1;
    X b = 120;
    X c = b-a;

    int d = c+a;
    cout << "D: "<<  d << endl;
     c= (double )d;
     c = a;
     c=c;

    return 0;
}