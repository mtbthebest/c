//
// Created by mtb on 1/6/21.
//

#include<iostream>
using namespace std;

template<class T>
class Tensor{
    T *elem;
    int dim[2]{};
public:
    Tensor(int d1, int d2): dim{d1, d2}, elem{new T[d1 * d2]}{
        cout << "initialization" << endl;
    }
    int size() const {
        return dim[0] * dim[1];
    }

    Tensor(const Tensor &);
    Tensor &operator=(const Tensor& );

//    Tensor(Tensor&&);
//    Tensor &operator=(Tensor&&);

    ~Tensor(){
        delete[] elem;
    }
};

template<class T>
Tensor<T>::Tensor(const Tensor &t) {
    cout << "Copy initialization" << endl;
    const int *_dims = t.dim;
    dim[0]=t.dim[0];
    dim[1]=t.dim[1];
    int size = dim[0] * dim[1];
    elem = new T{size};
    for(int i=0; i<size; i++) {
        elem[i] = t.elem[i];
    }
}

template<class T>
Tensor<T> & Tensor<T>::operator=(const Tensor &t) {
    if(t.dim[0] != dim[0] || t.dim[1] != dim[1])
    {
        throw std::range_error{"Range error"};
    }
    cout << "Copy assignment" << endl;

    int size = dim[0] * dim[1];
    for(int i=0; i<size; i++) {
        elem[i] = t.elem[i];
    }

}


int main(int argc, char *argv[]){

    Tensor<int> t1{10,10};
    Tensor<int> t3{10,10};

    Tensor<int> t2{t1};
    t3=t2;
    return 0;
}