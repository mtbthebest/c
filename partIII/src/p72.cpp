//
// Created by mtb on 7/7/21.
//Metaprogramming

#include <iostream>
using namespace std;
class Nil {};
template<int I, typename T1 =Nil, typename T2 =Nil, typename T3 =Nil, typename T4 =Nil>
struct number;

template<int I, typename T1 =Nil, typename T2 =Nil, typename T3 =Nil, typename T4 =Nil>
using Number = typename number<I,T1,T2,T3,T4>::type;
// Specializations for 0-3:
template<typename T1, typename T2, typename T3, typename T4>
struct number<0,T1,T2,T3,T4> { using type = T1; }; // specialize for N==0
template<typename T1, typename T2, typename T3, typename T4>
struct number<1,T1,T2,T3,T4> { using type = T2; }; // specialize for N==1
template<typename T1, typename T2, typename T3, typename T4>
struct number<2,T1,T2,T3,T4> { using type = T3; }; // specialize for N==2
template<typename T1, typename T2, typename T3, typename T4>
struct number<3,T1,T2,T3,T4> { using type = T4; }; // specialize for N==3


// General case Varidic templates
template<unsigned int N, typename... Cases>
struct _select;

template<unsigned int N,typename T,typename... Cases>
struct _select<N, T, Cases...>: _select<N-1, Cases...>{};

template<typename T,typename... Cases>
struct _select<0, T, Cases...>{
    using type = T;
};
template<unsigned int N, typename... Cases>
using Select = typename _select<N,Cases...>::type;

void t1(){
   Number<0, bool, int, float, double> n = 1;
//   Number<5, bool, int, float, double> nn = 1; // Invalid for this N

   cout << n;

}

int main() {
    t1();
    return 0;
}
