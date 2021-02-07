#include "CTreeDynamic.h"

CTreeDynamic::CTreeDynamic()
{
    CNodeDynamic* root = new CNodeDynamic();
    pc_root = root;
}

CTreeDynamic::~CTreeDynamic()
{
    delete pc_root;
}


void CTreeDynamic::vPrintTree()
{
    pc_root->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode, CNodeDynamic* pc2ParentNode)
{
    pcParentNode->vAddNewChild(pcNewChildNode);
    pc2ParentNode->removeChild(pcNewChildNode);

    return true;
}

void CTreeDynamic::vSetElementsVector(CNodeDynamic* pc_node)
{
    v_elements.push_back(pc_node->iGetVal());
    for (int i = 0; i < pc_node->iGetChildrenNumber(); i++)
        vSetElementsVector(pc_node->pcGetChild(i));
}

void CTreeDynamic::vPrintElementsVector()
{
    for (int v_element : v_elements)
        cout << v_element << endl;
}

