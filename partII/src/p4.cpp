//
// Created by mtb on 12/30/20.
//

#include <iostream>
using  namespace std;

void t1(){
    constexpr  int max = 1024;
    char buf[max]{};
    for(const char &i : buf){
        cout << i + 2 << endl;
    }
}

template <typename T>
class List {
    T *val;
    unsigned int size;
public:
    List(const std::initializer_list<T> lst): size {static_cast<unsigned int>(lst.size())}  {
        val = new T[lst.size()];
        int i =0;
        for(const auto l:lst){
            val[i] = l;
            i ++;
        }
    }

    void print() {
        for(int i=0; i<size; i++){
            cout << val[i];
        }
    }
    ~List(){
        delete[] val;
    }


};


void t2() {
 using IntList = List<int>;
 IntList lst = {1, 2};
 lst.print();
}

void t3() {
    typedef int I;
    I a = 10.0;
    cout << a;
}


int  main(int arg, char **argv){
    t1();

    return  0;

}

