//
// Created by mtb on 6/20/21.
//TODO
#include<iostream>

using namespace std;


template<typename Iter, typename Val>
Val sum(Iter first, Iter last)
{
    Val s = 0;
    while (first!=last) {
        s = s + (*first);
        ++first;
        break;
    }
    return s;
}

struct Node {
        Node *next;
        int data;


};

Node header{nullptr, 0};

Node insert(int val, Node *h){
    Node n = Node{h, val};
   return n;
}


ostream& operator<<(ostream& out , const Node &p){
    cout << "Node(" << p.data <<")";
    return out;
}

Node& operator++(Node& p) {
    cout << "Pp " << p.next->data<< endl;
    return *(p.next);
}
int operator+(Node&n, int z){
    return n.data + z;
}

int operator+(int z, Node&n){
    cout <<"V " << endl;
    return n+z;
}

int operator*(Node &p){
    return p.data;
}
bool operator!= (const Node&n, const Node&h){
    return n.next == nullptr;
}

int main() {
    double ad[] ={1,2,3,4};
//    double s = sum<double *, double>(ad, ad + 4);

    Node n1 = insert(1, &header);
    Node n2 = insert(2, &n1);
    Node n3 = insert(3, &n2);
    Node n4 = insert(4, &n3);

    cout << sum<Node ,int>(n4, header);
    cout << *n1;
    cout << ++n2;
    return 0;
}