//
// Created by tyyp- on 11/7/2020.
//

#include "CTreeStatic.h"


CTreeStatic::CTreeStatic()
{
    c_root = CNodeStatic();
}

CTreeStatic::~CTreeStatic()
{
}

void CTreeStatic::vPrintTree()
{
    c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode, CNodeStatic* pc2ParentNode)
{
    pcParentNode->vAddNewChild(pcNewChildNode);
    pc2ParentNode->removeChild(pcNewChildNode);

    return true;
}
