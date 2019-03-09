//
// Created by fcsca on 2019-03-09/0009.
//

#ifndef PRO1_STACK_RESOLUTION_H
#define PRO1_STACK_RESOLUTION_H

#include <iostream>
#include <cmath>
#include <cstring>
#include "../error_class/exc_mean.h"

using namespace std;

class stack_resolution {
private:
    char word[40];
public:
    stack_resolution(const char * str){
        strcpy(word, str);
        cout << "Stack resolution : " << word << " created\n";
    }
    ~stack_resolution(){
        cout << "Stack resolution : " << word << " destroyed\n";
    }
    void show()const {
        cout << "Stack resolution : " << word << " lives!\n";
    }
};

// function prototypes
double mean_h(double a, double b) throw(bad_hmean);
double mean_g(double a, double b) throw(bad_gmean);
double mean_s(double a, double b) throw(bad_hmean, bad_gmean);

double mean_h(double a, double b) throw(bad_hmean){
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double mean_g(double a, double b) throw(bad_gmean){
    if (a < 0 || b < 0) {
        throw bad_gmean(a, b);
    }
    return sqrt(a * b);
}

double mean_s(double a, double b) throw(bad_hmean, bad_gmean){
    double am, hm, gm;
    stack_resolution d2("found in means()");
    am = (a + b) / 2.0;
    try {
        hm = mean_h(a, b);
        gm = mean_g(a, b);
    } catch (bad_hmean &bg) {
        bg.mesg();
        cout << "Caught in means()\n";
        throw ;
    }
    d2.show();
    return (am + hm + gm) / 3.0;

}

// 堆栈解退
void useStackResolution(){
    double x, y, z;
    stack_resolution d1("found in main()");
    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
        try {
            z = mean_s(x, y);
            cout << "The mean of " << x << " and " << y << " is " << z << endl;
            cout << "Enter next pair: ";
        }catch (bad_hmean & bg) {
            bg.mesg();
            cout << "Try again.\n";
            continue;
        }catch (bad_gmean & hg) {
            cout << hg.mesg();
            cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
            cout << "Sorry , you don't get to play any more.\n";
            break;
        }
    }
    d1.show();
    cout << "Bye!\n";
}

#endif //PRO1_STACK_RESOLUTION_H
