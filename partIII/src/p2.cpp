//
// Created by mtb on 1/3/21.
//

#include<iostream>

using namespace std;

class List
{
    int size;
    int *elements;
public:
    List(int s, int _default=0): size{s}{
        elements = new int[s];
        for (int i = 0; i < s; ++i) {
            elements[i] = _default;
        }
    };

    ~List(){delete [] elements;}

    int index (int i) const {
        if(i>= size) throw range_error("Above the size");
        return elements[i];
    }

    void update(int i, int value) const{
        if(i>= size) throw range_error("Above the size");
        elements[i] = value;
    }

    int *begin() const{
        return elements;
    }

    int *end() const{
        return elements + size;
    }
    int get_size() const{
        return size;
    }
};

ostream& operator<<(ostream &os, const List &l) {
    cout << "List(";
    int size = l.get_size();
    int i = 0;
    for(auto v: l){
        cout << v;
        if(i<size -1)
            cout << ",";
        i +=1;

    }
    cout <<")";
    cout << endl;

    return os;
}

int main(int argc, char *argv[]){
    List l{4};

    List l1 = l;
    List l2{l};

    l1.update(0, 2);
    l2.update(1, 5);

    l2 = l;
    cout << l1;
    cout << l;
    cout << l2;



    return 0;
}