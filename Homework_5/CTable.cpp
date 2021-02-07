//
// Created by tyyp- on 12/19/2020.
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
CTable::CTable(const CTable &pcOther)
{
    s_name = pcOther.s_name + "_copy";
    i_size = pcOther.i_size;
    piTable = new int[i_size];
    //TODO
    for (int i = 0; i < i_size; ++i)
        piTable[i] = pcOther.piTable[i];
    cout << "Copy Constructor worked ------ s_name : " << s_name << " Size : " << i_size << endl;
}


CTable::CTable(CTable &&cOther) noexcept
{
    s_name = cOther.s_name;
    i_size = cOther.i_size;
    piTable = cOther.piTable;

    cOther.s_name.erase();
    cOther.i_size = 0;
    delete cOther.piTable ;
    cout << "Move Constructor worked ------ s_name : " << s_name << " Size : " << i_size << endl;
}


CTable::~CTable() {

    if(NULL != piTable)
        delete piTable;
    s_name.erase();
    i_size = 0;
    cout << endl << "Destructure worked " << endl;
}


bool CTable::bSetNewSize(int iTableLen)
{
    if (iTableLen > 0)
    {
        i_size = iTableLen;
        int* pi_newTable = new int[i_size];
        memcpy( pi_newTable, piTable, sizeof(char ) * i_size);
        delete piTable;
        piTable = pi_newTable;

        return true;
    } else
        return false;

}

CTable *CTable::pcClone()
{
    CTable * clone = new CTable(s_name, i_size);
    return clone;
}


void CTable::vPrintTable()
{
    for (int i = 0; i < i_size; ++i) {
        if(piTable[i] < 100 && piTable[i] > -1 )
            cout << piTable[i] << " ";
    }
    cout << endl;
}

void CTable::vSetTable()
{
    cout << endl << " Please enter elements of table respectively" << endl;

    for (int i = 0; i < i_size; ++i)
    {
        cout << i + 1 << " . element : " ;
        cin >> piTable[i] ;
    }
}

// !!!!!!!!!HW2 !!!!!!!!!!
void CTable::vSetValueAt(int iOffset, int iNewVal)
{
    piTable[iOffset] = iNewVal;
}

//= Copy Operator overloading
CTable CTable::operator=(const CTable &c_tab_1)
{
    if(&c_tab_1 == this)
        return *this;

    if (piTable != NULL) delete piTable;

    s_name = c_tab_1.s_name ;
    i_size = c_tab_1.i_size;
    piTable = new int[i_size];
    for (int i = 0; i < i_size; ++i)
        piTable[i] = c_tab_1.piTable[i];

    cout << "Copy overloading ... " << endl;
    return(*this);
}

// Move operator overloading
CTable CTable::operator=(CTable &&cOther) noexcept {
    //Self assignment detection
    if(&cOther == this)
        return *this;

    //Release any resource we are holding
    if(piTable != NULL) delete piTable;

    //Copy new resource
    s_name = cOther.s_name;
    i_size = cOther.i_size;
    piTable = cOther.piTable;
    /*//TODO
    for (int i = 0; i < i_size; ++i)
        piTable[i] = cOther.piTable[i];*/

    cOther.piTable = NULL;
    cOther.i_size = 0;
    cOther.s_name.erase();
    std::cout << "MOVE OPR " << endl;

    return(*this);


}

//+ Operator overloading
CTable CTable::operator+(const CTable &c_tab_1)
{
    int i_oldSize = i_size;
    int i_newSize = i_oldSize + c_tab_1.i_size;

    i_size = i_newSize;
    int* pi_newTable = new int[i_size];
    for (int i = 0; i < i_oldSize ; ++i)
        pi_newTable[i] = piTable[i];

    delete piTable;
    piTable = pi_newTable;

    // Adding right after the end of the original table
    for (int i = i_oldSize ; i < i_newSize ; ++i)
        vSetValueAt(i ,c_tab_1.piTable[i - i_oldSize] );

    return *this;
}



CTable CTable::operator++() {
    CTable cTable("newTable",i_size + 1);
    for (int i = 0; i < i_size + 1; ++i)
        cTable.piTable[i] = piTable[i];
    cTable.piTable[i_size] = 0;
    return cTable;
}

ostream &operator<<(ostream &out, const CTable &c_tab) {
    for (int i = 0; i < c_tab.i_size; ++i)
        out <<"--" <<c_tab[i] << "--" ;

    return out;
}














