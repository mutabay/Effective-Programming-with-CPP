#include <iostream>
#include "CNodeStatic.h"
#include "CTreeStatic.h"
#include "CNodeDynamic.h"
#include "CTreeDynamic.h"

void v_tree_test();
void v_dynamic_tree_test();
void testMovingStaticTree();
void testMovingDynamicTree() ;
void testPrintUp();
void v_CountNumbersInTree(vector<int> vTreeElements);


int main() {

    //v_tree_test();
    //v_dynamic_tree_test();
    //testMovingStaticTree();
    //testMovingDynamicTree();
    testPrintUp();
    return 0;
}
void v_tree_test()
{
    CNodeStatic c_root;
    c_root.vAddNewChild();
    c_root.vAddNewChild();
    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    c_root.vPrintAllBelow();
}//void v_tree_test()


void v_dynamic_tree_test()
{
    cout << "\n\nTesting Dynamic Tree";
    cout << "\n Creating tree 1\n";
    CTreeDynamic c_tree;
    CNodeDynamic* c_root = c_tree.pcGetRoot();
    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue(11);
    c_root->pcGetChild(1)->vSetValue(12);
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(13);
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(13);
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(15);
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(16);

    /*cout << "Print Below: ";
    c_root->vPrintAllBelow();


    cout << "Print Below: ";*/
    c_tree.vSetElementsVector(c_root);
    v_CountNumbersInTree(c_tree.vGetElements());

}


void v_CountNumbersInTree(vector<int> vTreeElements)
{
    int counter = 0;
    for (int i = 0; i < vTreeElements.size() ; i++)
    {
        for (int j = 0; j < vTreeElements.size(); j++)
        {
            if (vTreeElements[i] == vTreeElements[j])
                counter++;

        }
        cout << vTreeElements[i] << " elements count => " << counter << endl;
        counter = 0;
    }
}

void testMovingStaticTree() {
    cout << "\n\nTesting Move Static Tree";
    cout << "\n tree 1\n";
    CTreeStatic c_tree;
    CNodeStatic c_root = *c_tree.pcGetRoot();
    c_root.vAddNewChild();
    c_root.vAddNewChild();
    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    cout << "Print Below: ";
    c_root.vPrintAllBelow();
    cout << "\nPrint Up: ";
    c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();

    cout << "\n\tree 3\n";
    CTreeStatic c_tree3;
    CNodeStatic c_root3 = *c_tree3.pcGetRoot();
    c_root3.vAddNewChild();
    c_root3.vAddNewChild();
    c_root3.pcGetChild(0)->vSetValue(31);
    c_root3.pcGetChild(1)->vSetValue(32);
    c_root3.pcGetChild(0)->vAddNewChild();
    c_root3.pcGetChild(0)->vAddNewChild();
    c_root3.pcGetChild(0)->pcGetChild(0)->vSetValue(33);
    c_root3.pcGetChild(0)->pcGetChild(1)->vSetValue(34);
    c_root3.pcGetChild(1)->vAddNewChild();
    c_root3.pcGetChild(1)->vAddNewChild();
    c_root3.pcGetChild(1)->pcGetChild(0)->vSetValue(35);
    c_root3.pcGetChild(1)->pcGetChild(1)->vSetValue(36);

    cout << "Print Below";
    c_root3.vPrintAllBelow();

    cout << "\n\n Moving tree 3 to tree 1 \n";
    c_tree.bMoveSubtree(&c_root, c_root3.pcGetChild(0), &c_root3);

    cout << "\nTREE1 after moving subtree: ";
    c_root.vPrintAllBelow();
    cout << "\nTREE3 after moving subtree:";
    c_root3.vPrintAllBelow();
    cout << "\n";
}


void testMovingDynamicTree() {
    cout << "\n\nTesting Move Dynamic Tree";
    cout << "\n Creating tree 1\n";
    CTreeDynamic c_tree;
    CNodeDynamic c_root = *c_tree.pcGetRoot();
    c_root.vAddNewChild();
    c_root.vAddNewChild();
    c_root.pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(1)->vSetValue(12);
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(13);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(14);
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(15);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(16);

    cout << "Print Below: ";
    c_root.vPrintAllBelow();

    cout << "\n\nCreating tree 3\n";
    CTreeDynamic c_tree3;
    CNodeDynamic pc_root3 = *c_tree3.pcGetRoot();
    pc_root3.vAddNewChild();
    pc_root3.vAddNewChild();
    pc_root3.pcGetChild(0)->vSetValue(31);
    pc_root3.pcGetChild(1)->vSetValue(32);
    pc_root3.pcGetChild(0)->vAddNewChild();
    pc_root3.pcGetChild(0)->vAddNewChild();
    pc_root3.pcGetChild(0)->pcGetChild(0)->vSetValue(33);
    pc_root3.pcGetChild(0)->pcGetChild(1)->vSetValue(34);
    pc_root3.pcGetChild(1)->vAddNewChild();
    pc_root3.pcGetChild(1)->vAddNewChild();
    pc_root3.pcGetChild(1)->pcGetChild(0)->vSetValue(35);
    pc_root3.pcGetChild(1)->pcGetChild(1)->vSetValue(36);

    cout << "Print Below";
    pc_root3.vPrintAllBelow();

    cout << "\n\nMoving tree 3 to tree 1 \n";
    c_tree.bMoveSubtree(&c_root, pc_root3.pcGetChild(0), &pc_root3);

    cout << "\nTREE1 after moving subtree: ";
    c_root.vPrintAllBelow();
    cout << "\nTREE3 after moving subtree:";
    pc_root3.vPrintAllBelow();
    cout << "\n";
}


void testPrintUp()
{
    CNodeStatic c_root;

    c_root.vAddNewChild();
    c_root.vAddNewChild();
    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    cout << "\n\nTesting Print up";
    cout << "\nPrint Down:\n";
    c_root.vPrintAllBelow();
    cout << "\nPrint Up:\n";
    c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
}

