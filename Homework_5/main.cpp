#include <iostream>
#include "CMySmartPointer.h"
#include "Car.h"
#include "StaticClass.h"
#include "CTab.h"
#include "CTable.h"
#include "vector"

using namespace std;


void TestSmartPointer()
{
    // Create two car objects.
    /*CMySmartPointer<Car>eclipsePointer(new Car()); //Ref Counter for eclipsePointer = 1
    eclipsePointer.Get_RefCounter();

    eclipsePointer->SetCarFields("Mitsubishi","Eclipse",1996); // Changing year using pointer access operator.
    cout << *eclipsePointer;

    (*eclipsePointer).SetCarFields("Mitsubishi","Eclipse",2004); // Changing year using pointer deference operator.
    cout << *eclipsePointer;

    CMySmartPointer<Car>skylinePointer( new Car("Nissan","Skyline", 1999)); //Ref count for skyline = 1

    eclipsePointer = skylinePointer; // eclipsePointer now points to "Nissan Skyline".Ref count for skyline is 2. "Mitsubishi Eclipse" is destroyed. Ref count for skyline is 2

    cout << "Results !!! ";*/

    /*CMySmartPointer<int> static1( new int[2]{1,2});
    CMySmartPointer<int> static2( new int[3]{3,4,5});

    for (int i = 0; i < 2; ++i) {
        cout<< (*static1)[i];
    }*/

    /*CMySmartPointer<StaticClass> static3 ( new StaticClass());
    cout << *static3<< endl;*/


    CMySmartPointer<int>int_mySmartPointer(new int[5]{1,2,3,4,5});
    CMySmartPointer<int>int_mySmartPointer2(new int[5]{5,6,7,8,9});

    int_mySmartPointer = int_mySmartPointer2;

    CMySmartPointer<char>char_mySmartPointer(new char[5]{'a','b','c','d','e'});
    CMySmartPointer<char>char_mySmartPointer2(new char[5]{'f','g','h','j','k'});

    cout << "Before assigning "<< char_mySmartPointer[1] << endl;
    char_mySmartPointer = char_mySmartPointer2;

    cout << "After assigning "<< char_mySmartPointer[2] << endl;
}


CTab CloneDoubledTab(CTab & c_tab)
{
    CTab d_tab(c_tab.iGetSize());
    for (int i = 0; i < c_tab.iGetSize(); ++i)
        d_tab[i] = c_tab[i] * 2;

    return d_tab;
}

void TestMoveSemantics_CTab()
{
    /*CTab c_tab(1000000);
    for (int i = 0; i < c_tab.iGetSize(); ++i)
        c_tab[i] = i;

    cout << "Before Copying"<< endl << c_tab << endl ;

    c_tab = CloneDoubledTab(c_tab);

    cout << "After Copying"<< endl << c_tab <<endl;*/

    vector <CTab> vec;
    vec.push_back(CTab(10));
    for (int i = 0; i < vec[0].iGetSize(); ++i)
        (vec[0])[i] = i * i;
    cout << vec[0];
}

CTab CloneDoubledTable(CTab  c_tab)
{
    CTab d_tab(c_tab.iGetSize());
    for (int i = 0; i < c_tab.iGetSize(); ++i)
        d_tab[i] = c_tab[i] * 2;
    return d_tab;
}
void TestMoveOperator_CTab()
{
    CTab c_tab( 10);
    for (int i = 0; i < c_tab.iGetSize(); ++i)
        c_tab[i] = i;
    cout << "Before Moving c_tab => "<< endl << c_tab << endl ;

    c_tab = CloneDoubledTab(c_tab);
}


void TestMoveSemantics_CTable()
{

    vector <CTable> vec;
    vec.push_back(CTable("Effective Programming" , 10));
    for (int i = 0; i < vec[0].iGetSize(); ++i)
        (vec[0])[i] = i * i;
    cout << vec[0];

}

CTable CloneDoubledTable(CTable  c_table)
{
    CTable d_table("Database Management System", c_table.iGetSize());
    for (int i = 0; i < c_table.iGetSize(); ++i)
        d_table[i] = c_table[i] * 2;
    return d_table;
}
void TestMoveOperator_CTable()
{
    CTable c_table("Effective Programming" , 10);
    for (int i = 0; i < c_table.iGetSize(); ++i)
        c_table[i] = i;
    cout << "Before Moving c_table => "<< endl << c_table << endl ;

    c_table = CloneDoubledTable(c_table);
}

int main() {

    TestSmartPointer();

    //TestMoveSemantics_CTab();

    //TestMoveOperator_CTab();

    //TestMoveSemantics_CTable();

    //TestMoveOperator_CTable();
    return 0;
}
