//
// Created by mtb on 1/1/21.
//

#include <iostream>
#include <cstdarg>
#include <cstring>
using namespace std;


long long int fact(int n){
    return n>1 ? n * fact(n -1 ):1;
}


void t1() {
    long long int z = fact(15);
    cout << z << endl;
}

int *addr(int &&x){
    return &x;
}

[[noreturn]] void *sum(){
};

void t2() {
    int x =5;
    int *z= addr(6);
    cout << z;

//    int *s =static_cast<int *>(sum());
//    cout << s;

//    cout << s;
}

void update(float &g){

}
void t3(){
    double q = 2.0L;
    float qq = 2.0f;
//    update(2.0f); // Error need constant for update argument
//    update(q);// Error need constant for update argument
    update(qq); // Ok
}

// Pass array as reference
void f(const int(&r)[4]){
    cout << r[0];
//    r[0] = 2;
}

void t4() {
//    int a[] = {1,2,3,4};
    f({1,2,3,4});
//    f(a);
    cout << endl;
//    cout << a[0];

}


int accumulate(int v...){
    va_list ap;

    va_start(ap, v);

    int total = v;
    while(1){
        int p = va_arg(ap, int);
        if(!p) break;
        total += p;
    }

    va_end(ap);
    return  total;
}

void t5(){
    int a[] = {1,2,3};

    int z = accumulate(1,2,3,4,5);

    cout << "Accumulated: " << z;
}

class X{
public:
    static int x;

    void f(int=x){
        cout << "Default: " << x << endl;
    }
};

int X::x = 7;


void t6(){
    X x;
    x.f();
    X::x = 10;

    x.f();
}

int add(int a, int b) {
    return a+b;
}

int mul(int a, int b) {
    return a*b;
}

int reduce( int *arr,int size ,int (*func)(int, int), int init=0)
{
    int total = init;
    for(int i=0; i<size; i++){
        total = func(total, arr[i]);
    }
    return total;
}

void t7() {
    int arr[] = {1,2,3, 4  };
    int size = sizeof(arr) / sizeof(arr[0]);
    int adder = reduce(arr, size, &add);
    int multiplier= reduce(arr, size, &mul, 1);
    cout << adder << endl;
    cout << multiplier << endl;
}

enum Grade : char {
    A='A', B= 'B', C='C', D='D', E='E', F='F'
};

struct Student {
    char *name;
    int id;
    Grade grade;

};

ostream &operator<<(ostream &os, Student s){
    cout << "Student(id=" << s.id << ",grade=" << static_cast<char>(s.grade)

     << ",name=" << s.name << ")"<<endl;
    return os;
}

void print(Student st[]){
    for(int i=0; i<4; i++) {
        cout << st[i];
    }
}

using CFT = int(const void *, const void *);

void sort(Student st[], CFT cmp) {
    for(int j=0; j<3; j++ ){
        for(int i=1; i<4;i++){
            if(cmp(&st[j], &st[i] ) < 0)
            {
                char *p = reinterpret_cast<char *>(&st[j]);
                char *q = reinterpret_cast<char *>(&st[i]);
                char *z = new char[sizeof p] ;
                *z = *p;
                // #TODO
            }
        }
    }
}

int cmp1(const void *p, const void *q) {
    return strcmp(static_cast<const Student *>(p)->name,
                  static_cast<const Student *>(q)->name
    );
}

void t8() {
    struct Student st[] ={
                    {"Ana DaSilva", 1, Grade::F},
                    {"Eliza Hanz", 3, Grade::D},
                    {"Alice Bash", 2, Grade::E},
                    {"James Stewart", 4, Grade::A}
    };
    sort(st,cmp1);
    print(st);

}

int main() {
    t8();
    return 0;
}
