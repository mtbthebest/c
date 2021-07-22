//
// Created by mtb on 7/14/21.
// STL containers

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
#include<list>
#include<forward_list>
#include <complex>
#include <forward_list>
#include <unordered_map>
#include <unordered_set>
#include<set>
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

class NoCase{
    public:
        bool operator()(const string &x, const string &y ) const{
            auto p= x.begin(), q=y.begin();

            while(p!=x.end() && q!=y.end() && toupper(*p) == toupper(*q)){
                ++p;
                ++q;
            }
            if(p==x.end()) return q!= y.end();
            if(q==y.end()) return false;
            return toupper(*p) < toupper(*q);
        }

};
// For comparing c strings
struct Cstring_less {
    bool operator()(const char *p, const char *q) const{
        return strcmp(p, q) < 0;
    }
};

void t1(){
    vector<int> v1{4,6,2,3};
    vector<int> v2{v1};
    cout << v1;

    vector<string> v3{"apple", "pear", "Apple", "Pear", "Lemon"};
    sort(v3.begin(), v3.end(), NoCase());
    cout << v3;
}

void t2() {
    map<char *, int, Cstring_less> m;
    m["f"] = 4;
    cout << m["f"] <<" ------------ " << m["d"];
}

void t3(){
    vector<float> v1(4, 2.0f);
    cout << v1[0] << endl;

    list<int> l1;
    l1.push_front(1);
    l1.push_front(2);
    cout << l1.back();
    l1.pop_back();
    cout << l1.back();

    vector<float> v2{&v1[0], &v1[2]};
    cout << endl << v2 << endl;
    vector<float>v3{};
    v3.reserve(2);
    for(int o=0; o<10; o++){
        v3.push_back(o);
    }
    cout << v3 << endl;

    v3.assign(&v2[0], &v2[2]);
//    v3 = v2;
//    v3[0] = 3;
    cout << v3 << v3.size() << " capacity: " << v3.capacity() << " " << v3.max_size() << endl;

    v3.assign({3,4,5,7});

    cout << v3;
    auto x = &v3[3];
    cout << "Address before resize: " << &x << endl ;
    v3.resize(2);
    cout << v3 << " " ;  // << v3.size();
    x=&v3[3];

    cout << "Address after resize: " << &x  << " " <<v3.size() << " " << v3.capacity()<< " " << v3[3] << endl ;


}

void t4() {
    vector<float>v1(10);
    int i = 0;
    for(auto &x: v1){
        x = i;
        i++;
    }
    cout << v1 << endl;

    string s{"Hello"};
    for(auto x=s.begin(); x!= s.end(); ++x ){
        if(x != s.begin() && *x == *(x-1)){
            cout << "Duplicate: " << *x << endl;
        }
    }
    for(auto x=s.crbegin(); x!=s.crend(); ++x){
        cout << *x << " ";
    }

}

void t5(){
    vector<float>v1(10);
    int i = 0;
    for(auto &x: v1){
        x = i;
        i++;
    }

    cout << "Front: "<< v1.front() << ",  Back: " << v1.back() << endl;
    cout << v1[100] << endl; // Unauthorized access
    cout << v1.at(8) << endl;
//    cout << v1.at(100) << endl; // Throw error. Out of range
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    cout << v1.back() << endl;
    vector<vector<int>> v4{
            {1,2},
            {3,4}
    };
    vector<std::complex<int>> vc;
    int j=0;
    while(j<2){
        vc.emplace_back(v4[j][0], v4[j][1]);
        j++;
    }
    --j;
    cout << "Complex: " << vc[j].real() << " " << vc[j].imag() << endl;
}

void t6(){
    vector<float>v1(10);
    int i = 0;
    for(auto &x: v1){
        x = i;
        i++;
    }

    auto q = v1.insert(v1.begin(), -1);
    v1.insert(v1.begin(), 5, 3);
    cout << v1;
    vector<float>v2={9,4,6};
    v1.insert(v1.begin(), &v2[0], &v2[v2.size() - 1]);
    cout << v1;

    cout << "q: " << *q << (void *)&q<< endl;
    v1.erase(q);
    cout << "q: " << *q << (void *)&q << endl;
    cout << v1;
    auto z2 = v1.begin() + 6;
    auto z1=v1.begin() + 2;
    auto z3 = *z1;
    v1.erase(z1, z2);
    cout  << "Value of z3: " << z3 << endl;
    cout  << "Value of v3 erased 14: " << v1[11] << " " << v1[12] << " " << v1[17] << " " << v1[18] << endl;
    cout << v1;
}

void t7(){
    vector<int> v{4,3,5,1};
    using it = typename vector<int>::iterator;
    it p = v.begin() + 2;
    cout << *p << endl;
    v.push_back(6);

    auto p2 = v.begin() + 3;
    // p is invalid withput auto p = v.begin() + 2
    cout << *p << " " <<*p2  << ": " << &p2<< endl;
    v.erase(v.begin() + 3);
    // p2 is still valid
    cout << *p2 <<" "  <<  &p2 << " "  << *p << " " << v[2] << ", " << v[3] << " , " << v[4] <<  " , " << v[5] << endl;
    cout << v << endl;

}

void t8(){
    vector<char> v;
    v.reserve(10);
    auto p = v.begin() + 2;
    cout << "p: " << *p << endl;
    for(auto&x: {'a', 'b', 'c', 'd', 'e', 'f'}){
        v.push_back(x);
    }
    cout << v << *p << endl; // p is not invalidated like in t7
    v.shrink_to_fit();
}

void t9(){
    array<int, 3> a;
//    vector<int> a(3);
    for(auto &x: a)
        cin >> x;
    for(auto &x: a)
        cout << "Val: " << x << endl;
}

template<typename R>
void print_list(R lst){
    cout << "List(";
    for(auto &x: lst){
        cout << x << "," ;
    }
    cout << ")" << endl;

}

bool is_odd(int val){
    return val % 2 ? true: false;
}

void t10(){
    list<int> lst;
    for(int i=0; i<10; i++){
        lst.push_back(i);
    }
    lst.pop_back();
    lst.pop_front();
    cout << lst.size() << endl;
    auto p = lst.begin();
    *p = 4;
    lst.remove(4); // Remove all values 4
    lst.remove_if(is_odd);

    lst.reverse();
//    lst.sort();
    lst.push_front(1);
    lst.push_front(1);
    lst.push_back(1);
    lst.unique(); // Remove adjacent elements
    print_list(lst);
    cout << lst.size() << endl;

    list<int> lst2{-1,-8,-6,-2, 40}; // Ordered merge using <
    cout << "List 2 Before merge: ";
    print_list(lst2);
    lst.merge(lst2);
    print_list(lst);
    cout << "List 2 After merge: ";
    print_list(lst2);

    list<int> lst3{100,200,300};
     p = lst.begin();
//     p += 1; // Error for list case
     ++p;
    cout << "*p : " << *p << endl;

    lst.splice(p, lst3); // Lst3 is empty;
    print_list(lst);
    lst.insert(p, lst.begin(), p ); // p still point the value before the different insertions
    print_list(lst);
    cout << "*p : " << *p << endl;

}

void t11() {
    forward_list<int> lst{1,2,3,4,5};
//    cout << lst.size() << endl; // error no size attribute
    lst.push_front(6);
    forward_list<int> l2{-5, -3,-4};
    lst.merge(l2);
    auto p = lst.begin();
    ++p;++p;
    cout << "*p : " << *p << endl;
    print_list(lst);

    forward_list<int> l3{100,200, 300,400,500};

    auto q = l3.begin();
    q++; q++; q++; q++;
    lst.splice_after(p, l3, l3.begin(), q);
    print_list(lst);
    cout << "*p : " << *p << endl;
    print_list(l3);
    auto p2 = lst.insert_after(p, -98);
    print_list(lst);
}
template <typename R, typename T>
void print_dict(map<R, T> m){
    cout << "{" ;
    for(auto&x: m){
        cout << x.first << ": " << x.second<< ", ";
    }
    cout << "}" << endl;
}
template <typename R, typename T>
void print_dict(multimap<R, T> m){
    cout << "{" ;
    for(auto&x: m){
        cout << x.first << ": " << x.second<< ", ";
    }
    cout << "}" << endl;
}
void t12(){
    map<char, int> m;
    m['a'] = 1;
    m['b'] = 2;

    map<char, int> m2{m};
    m2['c'] = 3;
    print_dict(m);
    print_dict(m2);
    map<char, int> m3{{'a', 2}, {'0', 4}};
    print_dict(m3);

    cout << m3.at('0') << endl;
    auto p = m2.find('d');
    if(p == m2.end()){
        m2.insert({'d', 5});
    }
    print_dict(m2);
    m.insert(m3.begin(), m3.end());
    print_dict(m);
    print_dict(m3);

    multimap<string, int> mm {{"apple", 2}, {"banana", 4}, {"apple", 1}, {"orange", 9}, {"apple", 10}};
    print_dict(mm);
    cout << mm.count("apple") << endl;

}
struct Record{
    string name;
    int value;

};
bool operator< (const Record &a, const Record &b){
    return a.name < b.name;
}


void t13(){
    set<Record> s{{"duck", 10}, {"orange", 14}};
    s.insert({"bird", 1});
    auto p = s.begin();
    s.erase(p);
}
template <typename R, typename T>
void print_dict(unordered_map<R, T> m){
    cout << "{" ;
    for(auto&x: m){
        cout << x.first << ": " << x.second<< ", ";
    }
    cout << "}" << endl;
}


void t14() {
    unordered_map<string, int> m{{"apple", 7 }, {"orange", 3}, {"apple", 8}}; // apple:8 does not count
    unordered_map<string, int> m2{{"banana", 1 }, {"mango", 2}, {"orange", 8}}; // apple:8 does not count
    print_dict(m);

}

struct Nocase_hash{
    unsigned int d=1;

    size_t operator()(const Record &r) const {
        size_t h = 0;
        for(auto &x: r.name){
            h <<= d;
            h ^=toupper(x);
        }

        return h;
    }
};

struct Nocase_equal{
    bool operator()(const Record&r1, const Record &r2) const{
        if(r1.name.size() != r2.name.size() ) return false;
        for(int i=0; i<r1.name.size(); i ++){
            if(toupper(r1.name[i]) != toupper(r2.name[i]))
                return false;

        }
        return true;
    }
};
bool is_equal(const Record&r1, const Record &r2) {
    if(r1.name.size() != r2.name.size() ) return false;
    for(int i=0; i<r1.name.size(); i ++){
        if(toupper(r1.name[i]) != toupper(r2.name[i]))
            return false;

    }
    return true;
}

void t15(){
//    unordered_set<Record, Nocase_hash, Nocase_equal> m{
    unordered_set<Record, Nocase_hash, decltype(&is_equal)> m{
            { {"apple", 7 }, {"orange", 3}, {"apple", 7}},
            };
    for(auto &x: m)
        cout << x.name << ": " << x.value << endl;
}

int main(int args, char **argv){
    t15();
    return 0;
}