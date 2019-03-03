//
// Created by fcsca on 2019-03-02/0002.
//

#ifndef PRO1_VECTOR_H
#define PRO1_VECTOR_H

#include <iostream>

using namespace std;

namespace VECTOR{

    class Vector {
    private:
        double x;
        double y;
        double mag;
        double ang;
        char mode;

        // private methods for setting values
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();

    public:
        Vector();
        Vector(double n1, double n2, char form = 'r');
        ~Vector();
        void set(double n1, double n2, char form = 'r');
        double xval()const { return x;}
        double yval()const { return y;}
        double magval()const { return mag;}
        double angval()const { return ang;}
        void polar_mode();
        void rect_mode();
        // operator overloading
        Vector operator+(const Vector & b)const ;
        Vector operator-(const Vector & b)const ;
        Vector operator-()const ;
        Vector operator*(double n)const ;
        // friends
        friend Vector operator*(double n, const Vector & a);
        friend ostream &operator << (ostream & os, const Vector & vector);
    };
}



#endif //PRO1_VECTOR_H
