//
// Created by tyyp- on 11/7/2020.
//

#include <iostream>
#include <string>
#include "CNodeStatic.h"


using namespace std;

CNodeStatic::~CNodeStatic()
{
}

void CNodeStatic::vAddNewChild(){
    CNodeStatic toAdd = CNodeStatic();
    toAdd.parent = this;
    v_children.push_back(toAdd);
}

void CNodeStatic::vAddNewChild(CNodeStatic* newChild) {

    newChild->parent = this;

    v_children.push_back(*newChild);

}
void CNodeStatic::removeChild(CNodeStatic* oldChild) {
    int i;

    for (i = 0; i < iGetChildrenNumber(); i++)
        if (v_children[i].i_val == oldChild->i_val) {
            v_children.erase(v_children.begin() + i);
        }
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset) {
    if ((iChildOffset < 0) || (iChildOffset >= v_children.size())) {
        return nullptr;
    }

    return &v_children[iChildOffset];
}

void CNodeStatic::vPrintAllBelow() {
    vPrint();

    for (int i = 0; i < v_children.size(); i++)
        this->pcGetChild(i)->vPrintAllBelow();

}
void CNodeStatic::vPrintUp()
{
    vPrint();
    if (parent != nullptr)
        parent->vPrintUp();
}

