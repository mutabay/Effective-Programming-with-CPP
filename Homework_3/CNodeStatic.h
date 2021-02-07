//
// Created by tyyp- on 11/7/2020.
//

#ifndef HOMEWORK_3_CNODESTATIC_H
#define HOMEWORK_3_CNODESTATIC_H
#include <iostream>
#include <vector>


using namespace std;

class CNodeStatic
{
private:
    vector<CNodeStatic> v_children;
    int i_val;
    CNodeStatic* parent;
public:
    CNodeStatic() { i_val = 0; parent = nullptr; };
    ~CNodeStatic();
    void vSetValue(int iNewVal) { i_val = iNewVal; };
    int iGetChildrenNumber() { return(v_children.size()); };
    void vAddNewChild();
    CNodeStatic* pcGetChild(int iChildOffset);
    CNodeStatic* getParent() { return parent; };
    void vPrint() { cout << " " << i_val; };
    void vPrintAllBelow();
    void vPrintUp();
    void vAddNewChild(CNodeStatic* newChild);
    void removeChild(CNodeStatic* oldChild);

};//class CNodeStatic

#endif //HOMEWORK_3_CNODESTATIC_H
