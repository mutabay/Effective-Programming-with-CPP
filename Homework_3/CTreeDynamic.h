//
// Created by tyyp- on 11/7/2020.
//

#ifndef HOMEWORK_3_CTREEDYNAMIC_H
#define HOMEWORK_3_CTREEDYNAMIC_H

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
    vector<int> vGetElements() { return v_elements; }

};




#endif //HOMEWORK_3_CTREEDYNAMIC_H
