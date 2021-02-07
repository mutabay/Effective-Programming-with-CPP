#pragma once

#include <iostream>
#include "CNodeDynamic.h"

using namespace std;
class CTreeDynamic
{
private:
    CNodeDynamic* pc_root;
    vector<int> v_elements;
public:
    CTreeDynamic();
    ~CTreeDynamic();
    CNodeDynamic* pcGetRoot() { return pc_root; }
    void vPrintTree();
    bool bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode, CNodeDynamic* pc2ParentNode);
    void vSetElementsVector(CNodeDynamic* pc_node);
    void vPrintElementsVector();
    vector<int> vGetElementsVector() { return v_elements; }

};


