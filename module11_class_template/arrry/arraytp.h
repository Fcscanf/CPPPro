//
// Created by fcsca on 2019-03-06/0006.
//

#ifndef PRO1_ARRAYTP_H
#define PRO1_ARRAYTP_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T, int n>
class ArrayTP {
private:
    T ar[n];
public:
    ArrayTP(){};
    explicit ArrayTP(const T & v);
    virtual T &operator[](int i);
    virtual T operator[](int i) const ;
};

template <class T, int n>
ArrayTP<T, n>::ArrayTP(const T &v) {
    for (int i = 0; i < n; i++) {
        ar[i] = v;
    }
}

template <class T, int n>
T & ArrayTP<T, n>::operator[](int i){
    if (i < 0 || i >= n) {
        cerr << "Error in array limits: " << i << "is out of range\n";
        exit(EXIT_FAILURE);
    }
    return ar[i];
}

template <class T, int n>
T ArrayTP<T, n>::operator[](int i) const {
    if (i < 0 || i >= n) {
        cerr << "Error in array limits: " << i << "is out of range\n";
        exit(EXIT_FAILURE);
    }
    return ar[i];
}

#endif //PRO1_ARRAYTP_H
