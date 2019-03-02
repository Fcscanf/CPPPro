//
// Created by fcsca on 2019-03-02/0002.
//

#ifndef PRO1_FCTIME_H
#define PRO1_FCTIME_H

#include <iostream>

using namespace std;

class FcTime {
private:
    int hours;
    int minutes;
public:
    FcTime();
    FcTime(int h, int m = 0);
    void AddMin(int m);
    void AddHou(int h);
    void Reset(int h = 0, int m = 0);
    FcTime operator+(const FcTime & t)const;
    FcTime operator-(const FcTime & t)const;
    FcTime operator*(double n)const;
    // 友元函数的定义
    friend FcTime operator*(double m, const FcTime & t){
        return t * m;
    }
    friend ostream &operator << (ostream & os, const FcTime & t);
};


#endif //PRO1_FCTIME_H
