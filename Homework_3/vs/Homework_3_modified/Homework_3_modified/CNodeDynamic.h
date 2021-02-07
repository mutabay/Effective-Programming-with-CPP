#pragma once
#include <iostream>
#include <vector>

using namespace std;


class CNodeDynamic
{
public:
    CNodeDynamic() { i_val = 0; }
    ~CNodeDynamic();
    void vSetValue(int iNewVal) { i_val = iNewVal; };
    int iGetChildrenNumber() { return(v_children.size()); };
    void vAddNewChild();
    void vAddNewChild(CNodeDynamic* newChild);
    void removeChild(CNodeDynamic* oldChild);
    CNodeDynamic* pcGetChild(int iChildOffset);
    void vPrint() { cout << " " << i_val; };
    void vPrintAllBelow();
    //void vPrintUp2();
    int iGetVal() { return i_val; }
   
private:
    vector<CNodeDynamic*> v_children;
    int i_val;
};


