//
// Created by mtb on 1/6/21.
//

#include<iostream>
#include <cstring>
using namespace std;

class Location {
    string location;
public:
    Location(string loc=""){
        cout << "Location";
        location = loc;
    }
    ~Location(){};
};

struct School {

    string name;
    Location location;
    unsigned int number_students;

};

struct Exam {
    Exam(int){};
//    Exam(Exam const &e) = delete; // disallow copy constructor
};



int main(int argc, char *argv[]){
    School s;
    cout << s.name << endl;
    cout << s.number_students << endl;

//    Exam ex; // Error

    Exam ex{1}; // ok
    Exam ex1{ex}; // Ok copy constructor
    return 0;
}