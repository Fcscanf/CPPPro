//
// Created by fcsca on 2019-03-07/0007.
//
#include <iostream>

using namespace std;

template <typename T> void counts();
template <typename T> void report(T &);

template <typename TT>
class HasFriendT{
private:
    TT item;
    static int ct;
public:
    HasFriendT(const TT & i) : item(i){ ct++; }
    ~HasFriendT();
    friend void counts<TT>();
    friend void report<>(HasFriendT<TT> &);
};

template<typename T>
int HasFriendT<T>::ct = 0;

// template friend functions definitions
template <typename T>
void counts(){
    cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
    cout << "template counts()" << HasFriendT<T>::ct << endl;
}

template <typename T>
void report(T & hf){
    cout << hf.item << endl;
}

void test(){
    counts<int>();
    HasFriendT<int> hfil(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double > hfdb(10.5);
    report(hfil);
    report(hfi2);
    report(hfdb);
    cout << "counts<int>() output:\n";
    counts<int>();
    cout << "counts<double >() output:\n";
    counts<double >();
}

