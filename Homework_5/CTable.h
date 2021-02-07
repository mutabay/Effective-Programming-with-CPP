//
// Created by tyyp- on 12/12/2020.
//

#ifndef HOMEWORK_5_CTABLE_H
#define HOMEWORK_5_CTABLE_H

#define DEF_SIZE 0
#define  NAME "Name"

using namespace std;

#include <iostream>
#include <string>

class CTable {
private:
    string s_name;
    int i_size;
    int* piTable;


public:
    //Default Constructor
    CTable ();
    //Parametric Constructor
    CTable (string sName, int iTableLen);
    //Copy Constructor
    CTable (const CTable & pcOther);
    //Move Constructor
    CTable(CTable &&cOther) noexcept;
    //Destructor
    ~CTable();

    //Mutator methods
    void vSetName (string sName){s_name = sName;}
    void vSetTable ();

    void vSetValueAt(int iOffset, int iNewVal);

    //Accessor methods
    string sGetName(){return s_name;}
    int iGetSize(){return i_size;}
    int * piGetTable() { return piTable;}

    bool bSetNewSize (int iTableLen);
    CTable * pcClone ();

    void vPrintTable();

    //Operator Overloadings
    //Copy operator
    CTable operator=(const CTable & c_tab_1 );
    //Move operator
    CTable operator=( CTable &&cOther) noexcept;
    CTable operator+(const CTable & c_tab_1 );
    CTable operator++();

    int & operator[](int index) { return piTable[index]; }
    const int & operator[](int index) const { return piTable[index]; }
    friend ostream& operator<< (ostream& out, const CTable& c_tab);

};
#endif //HOMEWORK_5_CTABLE_H
