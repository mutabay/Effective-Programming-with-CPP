//
// Created by tyyp- on 12/14/2020.
//

#ifndef HOMEWORK_5_CTAB_H
#define HOMEWORK_5_CTAB_H

#include <iostream>

using namespace std;

#define DEF_TAB_SIZE 10
class CTab
{
private:
    void v_copy(const CTab &cOther);
    int *pi_tab;
    int i_size;
public:
    CTab() { pi_tab = new int[DEF_TAB_SIZE]; i_size = DEF_TAB_SIZE;}
    CTab(int i_size) { pi_tab = new int[i_size]; this->i_size = i_size;}
    CTab(const CTab &cOther);
    CTab(CTab &&cOther) noexcept ;
    ~CTab();

    CTab operator=(const CTab &cOther);
    CTab operator=( CTab &&cOther) noexcept ;
    int & operator[](int index) { return pi_tab[index]; }
    const int & operator[](int index) const { return pi_tab[index]; }
    friend ostream& operator<< (ostream& out, const CTab& c_tab);


    bool bSetSize(int iNewSize);
    int iGetSize() { return(i_size); }

};//class CTab


CTab::CTab(const CTab &cOther)
{
    v_copy(cOther);
    cout << "Copy Constructor worked " << endl;
}//CTab::CTab(const CTab &cOther)

//Move Ctor
CTab::CTab(CTab &&cOther) noexcept
{
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;

    cOther.pi_tab = NULL;
    cOther.i_size = 0;

    std::cout << "Move Constructor worked " <<endl;
}

CTab::~CTab()
{
    if (pi_tab != NULL) delete pi_tab;
    cout << endl << "Destructure worked " << endl;
}//CTab::~CTab()


CTab CTab::operator=(const CTab &cOther)
{
    if(&cOther == this)
        return *this;

    if (pi_tab != NULL) delete pi_tab;
    v_copy(cOther);
    cout << "op= " << endl;
    return(*this);
}//CTab CTab::operator=(const CTab &cOther)

CTab CTab::operator=( CTab &&cOther) noexcept
{
    //Self assignment detection
    if(&cOther == this)
        return *this;

    //Release any resource we are holding
    if(pi_tab != NULL) delete pi_tab;

    //Copy new resource
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;


    cOther.pi_tab = NULL;
    cOther.i_size = 0;

    std::cout << "MOVE OPR " << endl;

    return(*this);
}//CTab CTab::operator=(const CTab &cOther)

void CTab::v_copy(const CTab &cOther)
{
    pi_tab = new int[cOther.i_size];
    i_size = cOther.i_size;
    for (int ii = 0; ii < cOther.i_size; ii++)
        pi_tab[ii] = cOther.pi_tab[ii];
}//void CTab::v_copy(CTab &cOther)


bool CTab::bSetSize(int iNewSize) {
    if(iNewSize > 0)
    {
        int* pi_newTable = new int[iNewSize];
        for (int i = 0; i < i_size; ++i)
            pi_newTable[i] = pi_tab[i];
        i_size = iNewSize;
        delete pi_tab;
        pi_tab = pi_newTable;

        return true;
    }
    return false;
}

ostream& operator<< (ostream& out, const CTab& c_tab)
{
    for (int i = 0; i < DEFAULT_SIZE; ++i)
        out <<"--" <<c_tab[i] << "--" ;

    return out;
}
//CTab::CTab(CTab &&cOther)
#endif //HOMEWORK_5_CTAB_H
