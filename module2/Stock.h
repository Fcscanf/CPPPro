//
// Created by fcsca on 2019-03-02/0002.
//

#ifndef PRO1_STOCK_H
#define PRO1_STOCK_H


class Stock {
private:
    char company[30];
    int shares;
    double share_val;
    double total_val;
    void set_toto(){total_val = shares * share_val;}

public:
    Stock();
    Stock(const char* co, int n = 0, double pr = 0.0);
    ~Stock(){};
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
    void show()const;
    const Stock & topval(const Stock & s)const;
};


#endif //PRO1_STOCK_H
