//
// Created by mtb on 7/7/21.
//Metaprogramming

template<bool B, typename T, typename F>
struct conditional {
    using type = T;
};
template<typename T, typename F>
struct conditional<false, T, F>{
    using type = F;
};
template<bool B, typename T, typename F>
using Conditional = typename conditional<(sizeof(int) > 4), T, F>::type;

struct X{};

struct Y{};


int main() {

    typename  conditional<(sizeof(int) > 4), X, Y>::type z;
    Conditional<(sizeof(int) > 4), X, Y> z1;

    return 0;
}
