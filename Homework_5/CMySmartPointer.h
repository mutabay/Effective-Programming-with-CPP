//
// Created by tyyp- on 12/11/2020.
//

#ifndef HOMEWORK_5_CMYSMARTPOINTER_H
#define HOMEWORK_5_CMYSMARTPOINTER_H

#include <iostream>
#include "CRefCounter.h"

using namespace std;

template <typename T>
class CMySmartPointer {
private:
    T * pc_pointer = NULL;
    CRefCounter * pc_counter = NULL;
public:
    CMySmartPointer(): pc_pointer(NULL), pc_counter(NULL){}

    CMySmartPointer(T * pc_pointer):pc_pointer(pc_pointer), pc_counter(new CRefCounter())
    {
        pc_counter->iAdd();
        cout << " Created smart_ptr! Ref count is " << pc_counter->iGet() << endl ;
    }
    CMySmartPointer( const CMySmartPointer<T> & pc_other):pc_pointer(pc_other.pc_pointer), pc_counter (pc_other.pc_counter)
    {
        pc_counter->iAdd();
        cout << " Copied smart_ptr! Ref count is " << pc_counter->iGet() << endl;
    }
    ~CMySmartPointer()
    {
        if(pc_counter->iDec())
        {
            delete pc_counter;
            delete pc_pointer;
            pc_counter = NULL;
            pc_pointer = NULL;
            cout << "Destructor worked....." << endl;
        }
    }

    int Get_RefCounter()
    {
        return  pc_counter->iGet();
    }

    T & operator*(){return *pc_pointer;}

    T * operator->(){return pc_pointer;}

    T & operator[](int index) { return pc_pointer[index]; }
    const T & operator[](int index) const { return pc_pointer[index]; }

    CMySmartPointer<T>& operator=(const CMySmartPointer<T> & c_other)
    {
        if (this != &c_other)
        {
            if (pc_counter && pc_counter->iDec() == 0)
            {
                delete pc_counter;
                delete pc_pointer;
            }
            pc_pointer = c_other.pc_pointer;
            pc_counter = c_other.pc_counter;
            pc_counter->iAdd();
        }
        cout << "Assigning smart_ptr! Ref count is " << pc_counter->iGet() << endl;

        return *this;
    }


};


#endif //HOMEWORK_5_CMYSMARTPOINTER_H
