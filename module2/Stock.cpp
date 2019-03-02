//
// Created by fcsca on 2019-03-02/0002.
//

#include "Stock.h"
#include <iostream>
#include <cstring>

using namespace std;

class Stocks{
private:
    char company[30];
    int shares;
    double share_val;
    double total_val;

    // 在内部定义内联函数
    void set_tot(){
        total_val = shares * share_val;
    }

public:
    // 默认构造函数
    Stocks();
    // 折构函数——用来释放内存
    ~Stocks();
    void acquire(const char *co, int n, double pr);
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
    void show();
};

void Stocks::acquire(const char *co, int n, double pr) {
    std::strncpy(company, co, 29);
    company[29] = '\0';
    if (n < 0){
        cerr << "Number of shares cant's be negative." << company << "shares set to 0.\n";
        shares = 0;
    } else
        shares = n;
    share_val = pr;
    set_tot();
}

void Stocks::buy(int num, double price) {
    if (num < 0){
        cerr << "Number of shares purchased can't be negative." << "Transaction is aborted.\n";
    } else{
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stocks::sell(int num, double price) {
    if(num < 0){
        cerr << "Number of shares sold can't be negative." << "Transaction is aborted.\n";
    } else if (num > shares){
        cerr << "You can't sell more than you have!" << "Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stocks::update(double price) {
    share_val = price;
    set_tot();
}

void Stocks::show() {
    cout << "Company:" << company << " Shares: "<< shares << endl
    << "Share Price:$" << share_val << " Total Worth:$" << total_val << endl;
}

// 在外部定义内联函数
//inline void Stocks::set_tot(){
//    total_val = shares * share_val;
//}

// 声明类变量
//Stocks kate, joe;

Stocks::~Stocks() {
    cout << "折构函数调用结束" << endl;
}
