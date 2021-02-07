//
// Created by tyyp- on 11/7/2020.
//

#ifndef HOMEWORK_3_CNODEDYNAMIC_H
#define HOMEWORK_3_CNODEDYNAMIC_H

#include <iostream>
#include <vector>
#include "CNodeStatic.h"

using namespace std;


class CNodeDynamic
{
public:
    CNodeDynamic() { i_val = 0;}
    ~CNodeDynamic();
    void vSetValue(int iNewVal) { i_val = iNewVal; };
    int iGetChildrenNumber() { return(v_children.size()); };
    void vAddNewChild();
    void vAddNewChild(CNodeDynamic* newChild);
    void removeChild(CNodeDynamic* oldChild);
    CNodeDynamic* pcGetChild(int iChildOffset);
    void vPrint() { cout << " " << i_val; };
    void vPrintAllBelow();
    int iGetVal(){return i_val;}
    void vSetElementsVector();
    void vPrintElementsVector();
    vector<int> vGetElements(){return v_elements;}
private:
    vector<CNodeDynamic*> v_children;
    int i_val;
    vector<int> v_elements;
};


#endif //HOMEWORK_3_CNODEDYNAMIC_H
