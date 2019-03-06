//
// Created by fcsca on 2019-03-06/0006.
//

#ifndef PRO1_PAIRS_H
#define PRO1_PAIRS_H

#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2>
class Pair {
private:
    T1 a;
    T2 b;
public:
    T1 & first();
    T2 & second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval){}
    Pair(){}
};

template <class T1, class T2>
T1& Pair<T1, T2>::first() {
    return a;
}

template <class T1, class T2>
T2& Pair<T1, T2>::second() {
    return b;
}

#endif //PRO1_PAIRS_H
