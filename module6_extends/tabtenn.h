//
// Created by fcsca on 2019-03-03/0003.
//

#ifndef PRO1_TABTENN_H
#define PRO1_TABTENN_H


class TableTennisPlayer {
private:
    enum {LIM = 20};
    char firstname[LIM];
    char lastname[LIM];
    bool hasTable;
public:
    TableTennisPlayer(const char* fn = "none", const char* ln = "none", bool ht = false);
    void Name()const ;
    bool HasTable()const { return hasTable;};
    void ResetTable(bool v){hasTable = v;};
};


#endif //PRO1_TABTENN_H
