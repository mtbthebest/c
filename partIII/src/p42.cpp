//
// Created by mtb on 6/19/21.
//

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Node{
    T val;
public:
    Node(): val{0}{}

    Node(const Node<T> &n){
        val =n.val;
    }
    template<typename T1>
    explicit Node(T1 v){
        val = v;
    }
    template<typename T1>
    Node(const Node<T1> &);
    T getValue()const {
        return val;
    }

};
template<typename T>
ostream& operator<<(ostream& out, const Node<T> &node){
    cout << node.getValue();
}

template<typename T>
template<typename T1>
Node<T>::Node(const Node<T1> &n): val{n.getValue()}{};

int main(){

    Node<int> n;
    cout << n << endl;

    Node<float>n1(5.0f);
    cout << n1 << endl;

    Node<double>n2;

    n2 = n1;
    cout << n2 << endl;

    return 0;
}