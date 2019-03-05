//
// Created by fcsca on 2019-03-05/0005.
//

#ifndef PRO1_DMA_H
#define PRO1_DMA_H

#include <iostream>

using namespace std;

class baseDMA {
private:
    char *label;
    int rating;

public:
    baseDMA(const char* l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA &operator = (const baseDMA & rs);
    friend ostream &operator << (ostream & os, const baseDMA & rs);
};

class lacksDMA:public baseDMA{
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
    lacksDMA(const char * c, const baseDMA & rs);
    friend ostream&operator<<(ostream & os, const lacksDMA & rs);
};

class hasDMA:public baseDMA{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null", int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA &hs);
    hasDMA &operator=(const hasDMA &rs);
    ~hasDMA();
    friend ostream &operator<<(ostream & os, const hasDMA & rs);
};

#endif //PRO1_DMA_H
