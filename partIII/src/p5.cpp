//
// Created by mtb on 1/3/21.
//

#include<iostream>
using namespace std;

namespace Graph
{
    template<typename T>
    class Node{
        using value_type = T;
        enum Type {Add, Sub, Mul, Div};
        class Operations {
            Node<T> *left;
            Node<T> *right;

        public:
            Node<value_type>* app_op(Node<value_type> *a, Node<value_type> *b, Node<value_type> *c);

            ~Operations() {

                if(!left->is_leaf ){
                    cout <<"ddddddd" << endl;
                }
                cout << "Operations deleted " << endl;
            }

        };

        Operations *op;
        Type type;
        value_type value;
        bool is_leaf= false;

    public:
        Node(int _default){
            value= static_cast<T>(_default);
        }
        Node<T> operator+(Node<T> &b){
            return add(*this, b);
        }

        Node<T> add(Node<T> &l, Node<T>&r);
        value_type get_value();
        void set_value(value_type v);

        ~Node(){

                std::cout << op<< ", " << value << endl;
                if(op!= nullptr)
                    op->~Operations();
        }
        void initialize_op(){
            op = new Operations{};
        }


    };


};

using namespace Graph;

using NodeInt = Node<int>;

template<typename T>
T Node<T>::get_value(){
    return value;
}

template<typename T>
void Node<T>::set_value(T v){
    this->value = static_cast<value_type>(v);
}

template<typename T>
Node<T> Node<T>::add(Node<T> &l, Node<T>&r){
    cout << "t" << endl;
    auto *n = new Node<T>{0};

    n->type= Type::Add;
    n->initialize_op();

    n->op->app_op(&l, &r, n);

    return *n;
}

template<typename T>
Node<T>* Node<T>::Operations::app_op(Node<T> *a, Node<T> *b, Node<T> *c)

{
        c->op->left = a;
        c->op->right = b;
        c->value = left->value + right->value;
        return c;
};


template<typename T>
ostream &operator<<(ostream& os, Node<T>n){
    cout << "Node(value="<< n.get_value() <<")" << endl;
    return os;
}

int main(int argc, char *argv[]){
    NodeInt a{5}, b{4};
    a.set_value(15);
    NodeInt c = a + b;
    cout << c;
    cout << "Done";
    cout << a;



    return 0;
}

