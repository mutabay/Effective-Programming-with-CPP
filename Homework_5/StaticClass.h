//
// Created by tyyp- on 12/19/2020.
//

#ifndef HOMEWORK_5_STATICCLASS_H
#define HOMEWORK_5_STATICCLASS_H

#include <iostream>
using namespace std;

#define DEFAULT_SIZE 10

class StaticClass {
private:
    int * arr;
public:
    StaticClass()
    {
        arr = new int[DEFAULT_SIZE];
        for (int i = 0; i < DEFAULT_SIZE; ++i) {
            arr[i] = i*i;
        }
    }

    friend ostream& operator<< (ostream& out, const StaticClass& staticArray)
    {
        for (int i = 0; i < DEFAULT_SIZE; ++i)
            out <<"--" <<staticArray.arr[i] << "--" ;

        return out;
    }
};


#endif //HOMEWORK_5_STATICCLASS_H
