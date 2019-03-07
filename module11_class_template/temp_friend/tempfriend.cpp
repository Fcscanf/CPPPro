//
// Created by fcsca on 2019-03-07/0007.
//

#include <iostream>

using namespace std;

template <typename T>
class HasFriend{
private:
    T item;
    static int ct;
public:
    HasFriend(const T & i):item(i){ ct++; }
    ~HasFriend();
    friend void counts();
    friend void reports(HasFriend<T> &);
};

// each specialization has it's own static data member
template <typename T>
int HasFriend<T>::ct = 0;

// non-template friend to all HasFriend<T> classes
void counts(){
    cout << "int count: " << HasFriend<int >::ct << "; ";
    cout << "double count: " << HasFriend<double >::ct << endl;
}

// non-template friend to the HasFriend<int> class
void reports(HasFriend<int> & hf){
    cout << "HasFriend<int>: " << hf.item << endl;
}

// non-template friend to the HasFriend<double> class
void reports(HasFriend<double> & hf){
    cout << "HasFriend<double>: " << hf.item << endl;
}

void test(){
    cout << "No objects declared: ";
    counts();
    HasFriend<int > hfil(10);
    cout << "After hfil declared: ";
    counts();
    HasFriend<int > hfi2(20);
    cout << "After hfi2 declared: ";
    counts();
    HasFriend<double > hfdb(10.5);
    cout << "After hfdb declared: ";
    counts();
    reports(hfil);
    reports(hfi2);
    reports(hfdb);
}