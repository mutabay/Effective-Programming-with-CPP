//
// Created by tyyp- on 12/11/2020.
//

#ifndef HOMEWORK_5_CREFCOUNTER_H
#define HOMEWORK_5_CREFCOUNTER_H

#include <iostream>

using namespace std;

class CRefCounter {
private:
    int i_count;
public:
    CRefCounter(){ i_count = 0; }

    int iAdd() { return ++i_count;}
    int iDec() { return --i_count;}
    int iGet() const { return i_count;}

};


#endif //HOMEWORK_5_CREFCOUNTER_H
