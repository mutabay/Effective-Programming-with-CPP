//
// Created by tyyp- on 11/7/2020.
//

#ifndef HOMEWORK_3_CTREESTATIC_H
#define HOMEWORK_3_CTREESTATIC_H
#include <iostream>

using namespace std;
#include "CNodeStatic.h"

class CTreeStatic
{
private:
    CNodeStatic c_root;
public:
    CTreeStatic();
    ~CTreeStatic();
    CNodeStatic* pcGetRoot() { return(&c_root); }
    void vPrintTree();
    bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode, CNodeStatic* pc2ParentNode);

};//class CTreeStatic




#endif //HOMEWORK_3_CTREESTATIC_H
