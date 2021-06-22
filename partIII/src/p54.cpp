//
// Created by mtb on 6/20/21.
// Specialization

#include<iostream>
using namespace std;

template<typename T>
class List{
    T *v;
    int size;
public:
    List(){}
    explicit List(int){};
    T &elem(int i){
        return v[i];
    }
    T &operator[](int i){
        return elem(i);
    }

};

template<>
class List<void *>{
    void **p;
public:
    List() {
        cout << "Void Pointer" << endl;
    }
    explicit List(int){};

    void * &operator[](int i){
        return p[i];
    }

    void* &elem(int i){
        return p[i];
    }
};



template<typename T>
class List<T *>: private List<void *>{
public:
    using Base = List<void *>;
    List() {
        cout << "T Base Pointer" << endl;
    }
    explicit List(int i): Base(i){};
    T* &elem(int i){
        return reinterpret_cast<T*&>(Base::elem(i));
    }
    T* &operator[](int i){
        return reinterpret_cast<T*&>(Base::operator[](i));
    }
};


void t1(){
    cout << "t1 " << endl;

    List<int> t1;
    cout << "No specialization above" << endl;
    cout << "t2 " << endl;

    List<int *> t2; // Specialization
    cout << "t3 " << endl;

    List<void *> t3;

    cout << "t4 " << endl;

    List<int **> t4;
}

int main() {
    t1();
    return 0;
}