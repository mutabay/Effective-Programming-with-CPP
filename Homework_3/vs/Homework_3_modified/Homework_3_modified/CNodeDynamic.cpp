#include "CNodeDynamic.h"

CNodeDynamic::~CNodeDynamic()
{
    if (iGetChildrenNumber() == 0) {
        return;
    }
    else {
        for (int i = 0; i < iGetChildrenNumber(); i++) {
            v_children[i]->~CNodeDynamic();
            delete v_children[i];
        }
    }
}

void CNodeDynamic::vAddNewChild()
{
    CNodeDynamic* newNode;
    newNode = new CNodeDynamic();
    v_children.push_back(newNode);
}

void CNodeDynamic::vAddNewChild(CNodeDynamic* newChild)
{
    v_children.push_back(newChild);

    //v_children.insert(v_children.begin(), newChild);
}
void CNodeDynamic::removeChild(CNodeDynamic* oldChild)
{
    int i;

    for (i = 0; i < iGetChildrenNumber(); i++)
        if ((*v_children[i]).i_val == oldChild->i_val)
            v_children.erase(v_children.begin() + i);
}

CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset)
{
    if (iChildOffset >= iGetChildrenNumber() || iChildOffset < 0)
        return nullptr;
    return v_children[iChildOffset];
}

void CNodeDynamic::vPrintAllBelow()
{
    vPrint();

    for (int i = 0; i < iGetChildrenNumber(); i++) {
        v_children[i]->vPrintAllBelow();
    }
}
