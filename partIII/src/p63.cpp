//
// Created by mtb on 7/7/21.
// ADL

#include<iostream>



#include<vector>
#include<algorithm>
using namespace std;


namespace User {
    class Customer { /* ... */ };
    using Index = std::vector<Customer *>;
    void copy(const Index&, Index&, int deep){

    };
    // deep or shallow copy depending on the value of deep
    void algo(Index& x, Index& y)
    {
//        copy(x,y,false);// ADL error. Calls algo copy not User::copy
        User::copy(x, y, false); // Ok
    }
}

template<typename Range, typename Op>
void apply(const Range& r, Op f)
{
    using std::begin;
    using std::end;
    for (auto& x : r)
        f(x);
    // Now, the standard begin() and end() are in the overload set used by the range-for to traverse the
    //Range (unless Range has members begin() and end(); §9.5.1).
}



int main() {
    return 0;
}


