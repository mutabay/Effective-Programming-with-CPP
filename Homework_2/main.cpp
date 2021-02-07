#include <iostream>
#include <assert.h>
#include "CTable.h"

// Allocates 1D array and print it.
// Arguments: integer iSize = defines the size dynamically allocating array.
// Return type: void
void v_alloc_table_add_5 (int iSize);
//Reverse Order
void v_alloc_table_add_5_ReverseOrder (int iSize);



// Allocates 2D array(matrix).
// Arguments: int *** piTable = defines pointer of pointer to pointer for pass by reference====> *(**piTable)
// Arguments: integer iSizeX = defines the size of x axis(row) dynamically allocating array.
// Arguments: integer iSizeY = defines the size of y axis(column) dynamically allocating array.
// Return type: bool
bool b_alloc_table_2_dim (int *** piTable, int iSizeX, int iSizeY);
// Deallocates 2D array(matrix) .
bool b_dealloc_table_2_dim (int *** piTable, int iSizeX, int iSizeY); //iSizeY parameter is unnecessary.


// Call by value is unnecessary. It will not change anything.
// Modifying objects.
void v_mod_tab(CTable *pcTab, int iNewSize);
void v_mod_tab(CTable cTab, int iNewSize);


// Allocates 1D array and print it.
// Arguments: integer iSize = defines the size dynamically allocating array.
// Return type: void
void v_alloc_table_add_5 (int iSize);

int main() {
    CTable cTable ("abc",6);
    cTable.vSetValueAt(0,0);
    cTable.vSetValueAt(1,1);
    cTable.vSetValueAt(2,2);
    cTable.vSetValueAt(3,3);

    cTable.vPrintTable();


    cTable = cTable.operator++();

    cTable.vPrintTable();


    return 0;
}

void v_alloc_table_add_5 (int iSize)
{
    assert(iSize > 0);
    int * arr = new int[iSize];

    for (int i = 0; i < iSize; i++)
        arr[i] = i + 5 ;

    for (int i = 0; i < iSize; i++)
        std::cout << "Elements are: " << arr[i]  << std::endl;

    int * reverseArr = new int[iSize];
    for (int i = 0; i < iSize; ++i)
        reverseArr[i] = arr[iSize - 1 - i];

    for (int i = 0; i < iSize; i++)
        std::cout << "Reverse array Elements are: " << reverseArr[i]  << std::endl;

    delete[] arr;
    delete [] reverseArr;
}

void v_alloc_table_add_5_ReverseOrder (int iSize)
{
    assert(iSize > 0);
    int * arr = new int[iSize];

    for (int i = iSize - 1; i >= 0; i--)
        arr[i] = i + 5 ;

    for (int i = 0; i < iSize; i++)
        std::cout << "Elements are: " << arr[i]  << std::endl;

    delete[] arr;
}

bool b_alloc_table_2_dim (int *** piTable, int iSizeX, int iSizeY)
{
    assert(iSizeX > 0 && iSizeY > 0);

    *piTable = new int*[iSizeX];
    if (*piTable == nullptr) //Cannot allocating memory-Heap overflow
        return false;
    for (int i = 0; i < iSizeX; ++i)
    {
        (*piTable)[i] = new int[iSizeY];
        if ((*piTable)[i] == nullptr)  //Cannot allocating memory-Heap overflow
        {
            //Free-Delete allocated memory if there is no empty space.
            b_dealloc_table_2_dim(piTable,iSizeX,iSizeY);
            return false;
        }
    }
    return true;
}
bool b_dealloc_table_2_dim (int *** piTable, int iSizeX, int iSizeY)
{
    assert(iSizeX > 0 && iSizeY > 0);
    for (int i = 0; i < iSizeX; ++i)
        delete (*piTable)[i];

    delete[] *piTable;
    return true;
}
void v_mod_tab(CTable *pcTab, int iNewSize) {
    pcTab->bSetNewSize(iNewSize);
}
void v_mod_tab(CTable cTab, int iNewSize) {
    cTab.bSetNewSize(iNewSize);
}

