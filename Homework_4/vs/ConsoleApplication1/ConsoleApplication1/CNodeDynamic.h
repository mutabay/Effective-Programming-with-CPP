#pragma once

#include <iostream>
#include <vector>
using namespace std;

template <typename T> class CNodeDynamic
{
public:
    CNodeDynamic() { i_val = 0; };
    ~CNodeDynamic();
    void vSetValue(T iNewVal) { i_val = iNewVal; };
    int iGetChildrenNumber() { return (v_children.size()); };
    void vAddNewChild();
    void vAddNewChild(CNodeDynamic* newChild);
    void removeChild(CNodeDynamic* oldChild);
    CNodeDynamic* pcGetChild(int iChildOffset);
    void vPrint() { cout << " " << i_val; };
    void vPrintAllBelow();
private:
    vector<CNodeDynamic*> v_children;
    T i_val;
};

template <typename T> class CTreeDynamic
{
public:
    CTreeDynamic();
    ~CTreeDynamic();
    CNodeDynamic<T>* pcGetRoot() { return c_root; }
    void vPrintTree();
    bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode, CNodeDynamic<T>* pc2ParentNode);
private:
    CNodeDynamic<T>* c_root;
};


template <typename T>
CNodeDynamic<T>::~CNodeDynamic() {

    if (iGetChildrenNumber() == 0) {
        return;
    }
    else {
        for (int i = 0; i < iGetChildrenNumber(); i++) {
            //cout << "delete";
            v_children[i]->~CNodeDynamic();
            delete v_children[i];
        }
    }
}
template <typename T>
void CNodeDynamic<T>::vAddNewChild() {

    CNodeDynamic* newNode;
    newNode = new CNodeDynamic();
    v_children.push_back(newNode);
}
template <typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic* newChild) {
    v_children.push_back(newChild);
}
template <typename T>
void CNodeDynamic<T>::removeChild(CNodeDynamic* oldChild) {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        if ((*v_children[i]).i_val == oldChild->i_val)
            v_children.erase(v_children.begin() + i);
    }
}
template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetChild(int iChildOffset) {

    if (iChildOffset >= iGetChildrenNumber() || iChildOffset < 0)
        return NULL;
    return v_children[iChildOffset];
}
template <typename T>
void CNodeDynamic<T>::vPrintAllBelow() {

    vPrint();

    if (iGetChildrenNumber() == 0) {
        return;
    }
    else {
        for (int i = 0; i < iGetChildrenNumber(); i++) {
            v_children[i]->vPrintAllBelow();
        }
    }
}

//
template <typename T>
CTreeDynamic<T>::CTreeDynamic() {
    CNodeDynamic<T>* root;
    root = new CNodeDynamic<T>();
    c_root = root;
}
template <typename T>
CTreeDynamic<T>::~CTreeDynamic() {
    c_root->~CNodeDynamic();
}
template <typename T>
void CTreeDynamic<T>::vPrintTree() {
    c_root->vPrintAllBelow();
}
template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode, CNodeDynamic<T>* pc2ParentNode) {
    pcParentNode->vAddNewChild(pcNewChildNode);
    pc2ParentNode->removeChild(pcNewChildNode);

    return true;
}