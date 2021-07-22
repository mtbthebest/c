//
// Created by mtb on 7/14/21.
// Algorithm

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>
#include <complex>
using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>&v){
    cout << "Vector(";
    for(const auto &x: v){
        cout << x<< ",";
    }
    cout << ")" << endl;
    return out;

}

void t1(){
    vector<int> v{4,-1,2,3, 6, 3};
    for_each(v.begin(), v.end(), [](int& x){return ++x;});
    cout << v;
    bool b = all_of(v.begin(), v.end(), [](int x){return x > 0; });
    cout << "All are positive: " << b << endl;
    const string s ="Hello World Today";
    int space = count(s.begin(),s.end(), ' ') ;
    cout << "Count Space: " <<space << endl;
    auto p = find(s.begin(), s.end(), 'z');
    if(p == s.end()){
        cout << "s is Not found" << endl;
    }
    const string s2 = "Japan";
    auto q = find_first_of(s.begin(),s.end(),s2.begin(),s2.end());
    cout << "First found: " << *q << endl;

    const string s3 = "Good World";
    auto qq = equal(s.begin(),s.end(),s3.begin());

}

void t2(){
    string s="What a waste of time ?";
    string k = "waste";
    auto p = search(s.begin(),s.end(),k.begin(),k.end());
    cout << *p << " "<< (p != s.end())<< endl;
    string s2="";
    auto q = transform(s.begin(), s.end(), s.begin(), [](char &c) { c = toupper(c); return c; });
    cout << s;

    auto r = copy(s.begin(), s.end(), s2.begin());
    cout << s2 << endl;
    string s3 = "";
    move(s.begin(),s.begin() + 5, s.begin());
    cout << s << endl;


}

void t3(){
    vector<int> s{1,1,1,2,4,6};
    auto p = unique(s.begin(), s.end());
    cout << s;
    s.erase(p, s.end());
    cout << s;
}

void t4(){
    string s ="Hello** World* Planet";
    auto p =remove(s.begin(), s.end(),'*');
    cout << s << endl;
    if(p!= s.end()){
        s.erase(p, s.end());
        cout << s << endl;
    }
    replace(s.begin(), s.end(), 'l', 'L' );
    cout << s << endl;
    rotate(s.begin(), s.begin() + 2, s.end());
    cout << s << endl;

    random_shuffle(s.begin(),s.end());
    cout << s;
}

void t5(){
    pair<int, int> p{1,2};
    cout << p.first << " " << p.second << endl;
}

int main(int args, char **argv){
    t4();
    return 0;
}