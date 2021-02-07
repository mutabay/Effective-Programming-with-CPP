//
// Created by tyyp- on 10.10.2020.
//

#include "CTable.h"

CTable::CTable()
{
    s_name = NAME;
    i_size = DEF_SIZE;
    piTable = new int[i_size];
    cout << "Default Constructor worked ------ s_name : " << s_name << " Size : " << i_size << endl;
}
CTable::CTable(string sName, int iTableLen)
{
    s_name = sName;
    i_size = iTableLen;
    piTable = new int[i_size];
    cout << "Parametric Constructor worked ------ s_name : " << s_name << " Size : " << i_size << endl;

}
CTable::CTable(CTable &pcOther)
{
    s_name = pcOther.s_name + "_copy";
    i_size = pcOther.i_size;
    piTable = new int[i_size];
    for (int i = 0; i < i_size; ++i)
        piTable[i] = pcOther.piTable[i];
    cout << "Copy Constructor worked ------ s_name : " << s_name << " Size : " << i_size << endl;
}

CTable::~CTable() {
    s_name.erase(); // It is not necessary.
    i_size = 0;
    delete piTable;
}



// TODO
bool CTable::bSetNewSize(int iTableLen) 
{

    assert(iTableLen > 0);
    i_size = iTableLen;
    int* pi_newTable = new int[i_size];
    memcpy( pi_newTable, piTable, sizeof(char ) * i_size);
    delete piTable;
    piTable = pi_newTable;

    return true;
}


CTable *CTable::pcClone() {
    CTable * clone = new CTable(s_name, i_size);
    return clone;
}


void CTable::vPrintTable() 
{
    for (int i = 0; i < i_size; ++i) {
        cout << piTable[i] << " ";
    }
    cout << endl;
}







