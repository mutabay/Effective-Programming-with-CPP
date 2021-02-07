#include <iostream>
#include <assert.h>
#include "CTable.h"

// Allocates 1D array and print it.
// Arguments: integer iSize = defines the size dynamically allocating array.
// Return type: void
void v_alloc_table_add_5 (int iSize);


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

int main() {

//Testing 1st question
/*
    int iSize = 5;
    v_alloc_table_add_5(iSize);
*/

//Testing 2nd and 3rd question
/*
 #pragma region TestMatrix
    int iSizeX = 5;
    int iSizeY = 3;
    int ** piTable;
    // Calling with pass by reference solution.
    if ( b_alloc_table_2_dim(&piTable ,iSizeX ,iSizeY ) )
    {
        std::cout<< "2D array dynamic memory allocation is successful."<< std::endl;
    }
    //Filling in
    for (int i = 0; i < iSizeX; ++i) {
        for (int j = 0; j < iSizeY; ++j) {
            piTable[i][j] = i + j;
        }
    }
    //Print 2d array.
    for (int i = 0; i < iSizeX; ++i) {
        for (int j = 0; j < iSizeY; ++j) {
            std::cout << piTable[i][j] ;
        }
        std::cout<< std::endl;
    }
    // Free the memory against memory leak.
    b_dealloc_table_2_dim(&piTable, iSizeX, iSizeY);
#pragma endregion TestMatrix
 */



#pragma region CtableTest
    CTable defTable;

    CTable parTable("PAR_NAME", 4);

    CTable copyTable( parTable);

    for (int i = 0; i < copyTable.iGetSize(); ++i) {
        copyTable.vSetTable(i, i * i);
    }
    copyTable.vPrintTable();

    // CALL BY VALUE
    v_mod_tab(copyTable ,8 );
    cout << "v_mod_tab pass by value is worked " << " Size : " << copyTable.iGetSize() << endl;  // This method cannot change

    // CALL BY REF
    v_mod_tab(&copyTable ,8 );
    cout << "v_mod_tab pass by ref is worked " << " Size : " << copyTable.iGetSize() << endl;  // This method can change


#pragma endregion CtableTest //Testing 4th question

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

