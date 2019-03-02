//
// Created by fcsca on 2019-03-02/0002.
//

#include <iostream>
#include "FcTime.h"

FcTime::FcTime() {
    hours = minutes = 0;
}

FcTime::FcTime(int h, int m) {
    hours = h;
    minutes = m;
}

void FcTime::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void FcTime::AddHou(int h) {
    hours += h;
}

void FcTime::Reset(int h, int m) {
    hours = h;
    minutes = m;
}

FcTime FcTime::operator+(const FcTime &t) const {
    FcTime sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

FcTime FcTime::operator-(const FcTime &t) const {
    FcTime diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

FcTime FcTime::operator*(double n) const {
    FcTime result;
    long totalminutes = hours * n * 60 + minutes * n;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

ostream & operator<< (ostream & os, const FcTime & t){
    os << t.hours << "hours, " << t.minutes << "minutes";
    return os;
}