//
// Created by fcsca on 2019-03-06/0006.
//

#include "tempmemb.h"
#include <iostream>

using namespace std;

template <typename T>
class beta{
private:
    template <typename V>
    class hold{
    private:
        V val;
    public:
        hold(V v = 0):val(v){}
        void show()const {cout << val << endl; }
        V Value()const { return val;}
    };
    hold<T> q;
    hold<int> n;
public:
    beta(T t, int i):q(t), n(i){}
    template <typename U>
    U blab(U u, T t){ return (n.Value() + q.Value()) * u / t; }
    void Show()const {q.show(); n.show();}
};

void test(){
    beta<double> guy(3.5, 3);
    guy.Show();
    cout << guy.blab(10, 2.3) << endl;
    cout << "Done\n";
}
