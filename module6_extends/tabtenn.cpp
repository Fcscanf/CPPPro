//
// Created by fcsca on 2019-03-03/0003.
//

#include "tabtenn.h"
#include <iostream>
#include <cstring>

using namespace std;

TableTennisPlayer::TableTennisPlayer(const char *fn, const char *ln, bool ht) {
    strncpy(firstname, fn, LIM - 1);
    firstname[LIM - 1] = '\0';
    strncpy(lastname, ln, LIM -1);
    lastname[LIM - 1] = '\0';
    hasTable = ht;
}

void TableTennisPlayer::Name() const {
    cout << lastname << " , " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const char *fn, const char *ln, bool ht):TableTennisPlayer(fn, ln, ht){
    rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp):TableTennisPlayer(tp), rating(r) {}