//
// Created by mtb on 7/7/21.
//Hierarchy

#include<iostream>
using namespace std;
struct DefaultBalance{};

template<typename N, typename Balance=DefaultBalance>
struct Node_base {
    N* left_child;
    N* right_child;
    Node_base(){
        left_child=right_child=nullptr;
    };
    void add_left(N *p){
        if(left_child == nullptr)
            left_child = p;
        else
            throw std::runtime_error{"Left child assigned"};
    }
    void add_right(N *p){
        if(right_child == nullptr)
            right_child = p;
        else
            throw std::runtime_error{"Right child assigned"};
    }
};

template<typename Val>
struct Node: Node_base<Node<Val>>{
    Val v;
    Node(Val vv): v{vv}{}
};


void t1(){
    using My_node = Node<int>;
    My_node root{5};
    int i =0;
    for( ; i<2; ++i){
        cout << i << endl;
        auto p = new My_node{i};
        if(i % 2)
            root.add_left(p);
        else
            root.add_right(p);
    }

}

template<typename Val, typename Balance>
struct SearchNode: public Node_base<SearchNode<Val, Balance>, Balance>{};

struct Red_black_balance {};

template<typename T>
using Rbnode = SearchNode<T, Red_black_balance>;

void t2() {
    Rbnode<double> my_root;

}


template<typename N>
struct X_base: N::type{

};

template<typename H>
struct Y{
    using type = H;
};

struct Z{
    Z(){
        cout << "Z" << endl;
    }
    static void getItem(){
        cout << "Getting item";
    }
};

void t3(){
    X_base<Y<Z>> xb{};
    xb.getItem();
}


int main() {
    t3();
    return 0;
}
