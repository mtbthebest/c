//
// Created by mtb on 1/7/21.
//

#include<iostream>
#include <vector>
using namespace std;

struct Student {
    int id;
    int *major;
    const char *name;
    string school;
    vector<int>grades;
};

int main(int argc, char *argv[]){
    int major = 5;
   Student s{1, &major,"Alex", "MIT",{70,80,90} };
    Student s1 = s;
    cout << s1.major << endl;
    Student s2= move(s);
    cout << s.grades.size() << s2.grades.size() <<endl;
    cout << s.name << s2.name <<endl;
    cout << s.school << " , " << s2.school <<endl;
    cout << s.major << " , " << s2.major <<endl;


    return 0;
}
