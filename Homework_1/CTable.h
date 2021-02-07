//
// Created by tyyp- on 10.10.2020.
//
#ifndef HOMEWORK_1_CTABLE_H
#define HOMEWORK_1_CTABLE_H

using namespace std;

#include <iostream>
#include <string>
#include <assert.h>

class CTable {
private:
    string s_name;
    int i_size;
    int* piTable;

    const int DEF_SIZE =0;
    const string NAME = "Name";

public:
    //Default Constructor
    CTable ();
    //Parametric Constructor
    CTable (string sName, int iTableLen);
    //Copy Constructor
    CTable (CTable & pcOther);

    //Mutator methods
    void vSetName (string sName){s_name = sName;}
    void vSetTable (int index, int value) { piTable[index] = value;}
    //Accessor methods
    string sGetName(){return s_name;}
    int iGetSize(){return i_size;}
    int * piGetTable() { return piTable;}


    bool bSetNewSize (int iTableLen);
    CTable * pcClone ();

    void vPrintTable();

    //Destructor
    ~CTable();

};


#endif //HOMEWORK_1_CTABLE_H
