//
// Created by tyyp- on 11/15/2020.
//

#ifndef HOMEWORK_4_CTABLE_H
#define HOMEWORK_4_CTABLE_H

#include <iostream>
#include <atlstr.h>

template < typename T> class CTable {
private:
    int i_size;
    T* pt_table;
public:
    CTable() :i_size(0), pt_table(nullptr) {};
    ~CTable() { if (pt_table != nullptr) delete[] pt_table; }

    bool bSetLength(int iNewSize);

    T* ptGetElement(int iOffset);
    bool bSetElement(int iOffset, T tVal);

    CString sGetKnownType();
};

template <typename T>
bool CTable<T>::bSetLength(int iNewSize)
{
    if (iNewSize <= 0)
        return false;
    T* pt_new_table = new T[iNewSize];

    if (pt_table != nullptr)
    {
        int i_min_len;
        if (iNewSize < i_size)
            i_min_len = iNewSize;
        else
            i_min_len = i_size;
        for (int i = 0; i < i_min_len; ++i)
            pt_new_table[i] = pt_table[i];
        delete pt_table;
        pt_table = pt_new_table;
        return true;
    }
}

template <typename T>
T* CTable<T>::ptGetElement(int iOffset)
{
    if ((0 > iOffset) || (iOffset >= i_size))
        return nullptr;
    return (&(pt_table[iOffset]));
}

template <typename T>
bool CTable<T>::bSetElement(int iOffset, T tVal)
{
    if ((0 >= iOffset) && (iOffset < i_size))
        return false;
    pt_table[iOffset] = tVal;
    return true;
}

template <typename T>
CString CTable<T>::sGetKnownType()
{
    CString s_type = "Unknown";
    return(s_type);
}//CString CTable<T>::sGetKnownType()
template <>
CString CTable<int>::sGetKnownType()
{
    CString s_type = "INT";
    return(s_type);
}//CString CTable<int>::sGetKnownType()

#endif //HOMEWORK_4_CTABLE_H
