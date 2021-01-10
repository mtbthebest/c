//
// Created by mtb on 1/10/21.
//
#include<iostream>
#include <vector>
#include <utility>
using namespace std;
struct Assoc
{
    vector<pair<string, int>> vec;
    const int& operator[](const string &) const;
    int &operator[](const string&);

};

int &Assoc::operator[](const string &s) {
    for(auto x:vec)
        if(s==x.first) return x.second;
    vec.push_back({s, 0});
    return vec.back().second;

}

int main(int argc, char *argv[]){
    Assoc values;
    string buff;
    int i=0;
    while (cin.good()){
        cin>>buff;
        ++values[buff];
        i++;
        if (i >2) break;
    }
    for(auto x:values.vec){
        cout << '{' << x.first << ',' << x.second << "}\n";
    }
    return 0;
}

