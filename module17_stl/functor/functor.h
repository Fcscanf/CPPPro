//
// Created by fcsca on 2019-03-10/0010.
//

#ifndef PRO1_FUNCTOR_H
#define PRO1_FUNCTOR_H

template <class T>
class TooBig {
private:
    T cutoff;
public:
    TooBig(const T & t):cutoff(t){}
    bool operator()(const T & v){ return v > cutoff; }
};


#endif //PRO1_FUNCTOR_H
