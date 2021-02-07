#include <iostream>
#include "CVector.h"
#include "CMatrix.h"
#include <fstream>


template<typename T>
CVector<T> ReturnRValueVector(CVector<T> c_vector)
{
    return c_vector;
}


void TestIntVectorClass()
{
/*
    CVector<int> def_cVector;
    cout << "def_cVector" << def_cVector << endl;
*/

    CVector<int> par_cVector(3, 2);

    par_cVector.SetVectorElement(2, 5);
    par_cVector.SetVectorElement(1, 1);
    par_cVector.SetVectorElement(3, 8);
    cout <<"par_cVector" <<  par_cVector << endl;


    int arr[] = {1,5,7};
    CVector<int> arr_cVector(arr, 3);
    cout <<"arr_cVector" <<  arr_cVector << endl;
/*
    CVector<int> copy_cVector(arr_cVector);
    cout <<"copy_cVector" <<  copy_cVector << endl;
    CVector<int> move_cVector(ReturnRValueVector(arr_cVector));
    cout <<"move_cVector" <<  move_cVector << endl;
*/

    cout << "Scalar - Dot product result " << par_cVector.ScalarProduct(arr_cVector) << endl;
    cout << "Cross product result " << par_cVector.CrossProduct(arr_cVector) << endl;
}

void TestDoubleVectorClass()
{
/*
    CVector<double> def_cVector;
    cout << "def_cVector" << def_cVector << endl;
*/

    CVector<double> par_cVector(3, 2.2);

    par_cVector.SetVectorElement(2, 5.1);
    par_cVector.SetVectorElement(1, 1.2);
    par_cVector.SetVectorElement(3, 8.3);
    cout <<"par_cVector" <<  par_cVector << endl;


    double arr[] = {1.1,5.5,7.7};
    CVector<double> arr_cVector(arr, 3);
    cout <<"arr_cVector" <<  arr_cVector << endl;
/*
    CVector<double> copy_cVector(arr_cVector);
    cout <<"copy_cVector" <<  copy_cVector << endl;

    CVector<double> move_cVector(ReturnRValue(arr_cVector));
    cout <<"move_cVector" <<  move_cVector << endl;
*/
    cout << "Scalar - Dot product result " << par_cVector.ScalarProduct(arr_cVector) << endl;
    cout << "Cross product result " << par_cVector.CrossProduct(arr_cVector) << endl;
}

void TestFloatVectorClass()
{

    CVector<float> def_cVector;
    cout << "def_cVector " << def_cVector << endl;


    CVector<float> par_cVector(3, 2.2);

    par_cVector.SetVectorElement(2, 5.1);
    par_cVector.SetVectorElement(1, 1.2);
    par_cVector.SetVectorElement(3, 8.3);
    cout <<"par_cVector " <<  par_cVector << endl;


    float arr[] = {1.1,5.5,7.7};
    CVector<float> arr_cVector(arr, 3);
    cout <<"arr_cVector " <<  arr_cVector << endl;
/*
    CVector<float> copy_cVector(arr_cVector);
    cout <<"copy_cVector " <<  copy_cVector << endl;

    CVector<float> move_cVector(ReturnRValueVector(arr_cVector));
    cout <<"move_cVector " <<  move_cVector << endl;
*/
    cout << "Scalar - Dot product result " << par_cVector.ScalarProduct(arr_cVector) << endl;
    cout << "Cross product result " << par_cVector.CrossProduct(arr_cVector) << endl;
}

template<class T>
CMatrix<T> ReturnRValueMatrix(CMatrix<T> c_matrix)
{
    return c_matrix;
}

void TestIntBasicMatrixClass()
{
    //! Constructors
/*
    CMatrix<int> def_cMatrix;
    cout << "def_cMatrix " << endl << def_cMatrix << endl;
*/
    CMatrix<int> par_cMatrix(3,6);
    par_cMatrix.FillAllMatrix(10);
    cout << "par_cMatrix " << endl << par_cMatrix << endl;


    int **arr;
    arr = new int* [6];
    for (int i=0; i < 6; i++)
        arr[i] = new int[3];
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j)
            arr[i][j] = i + j;
    }

    int **arr3;
    arr3 = new int* [6];
    for (int i=0; i < 6; i++)
        arr3[i] = new int[1];
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 1; ++j)
            arr3[i][j] = i + j + 1;
    }

    CMatrix<int> arr_cMatrix(arr, 6, 3);
    cout << "arr_cMatrix " << endl << arr_cMatrix << endl;

    CMatrix<int> arr3_cMatrix(arr3, 6, 1);
    cout << "arr3_cMatrix " << endl << arr3_cMatrix << endl;

/*
    CMatrix<int> copy_cMatrix(arr_cMatrix);

    CMatrix<int> move_cMatrix(ReturnRValueMatrix(arr_cMatrix));
*/

    CMatrix<int> file_cMatrix("C:\\Users\\tyyp-\\Desktop\\Repository\\Effective Programming\\Mini_project\\MatrixExample.txt.txt");
    cout << "file_cMatrix " << endl << file_cMatrix << endl;

    //! Setter and Getters
    /*
    file_cMatrix.SetMatrixElement(0,1,25);
    cout << "new file_cMatrix " << endl << file_cMatrix << endl;

    cout << "Row Size = " << file_cMatrix.GetRowSize() << endl;
    cout << "Col Size = " << file_cMatrix.GetColSize() << endl;

    arr = file_cMatrix.m_GetMatrix();

    cout << "Matrix [2][1] element is = "<<  file_cMatrix.GetMatrixElement(2,1) << endl;
    */

    int arr2[] = {1,2,3,4,5,6};
    CVector<int> arr_cVector(arr2, 6);
    cout <<"arr_cVector" <<  arr_cVector << endl << endl;

    //! Mathematical Methods
    //cout << "Addition Result = " << endl << file_cMatrix.Addition(par_cMatrix) << endl;
    //cout << "Subtraction Result = " << endl << file_cMatrix.Subtraction(par_cMatrix) << endl;
    //cout << "Matrix-Matrix Multiplication Result = " << endl << file_cMatrix.Multiplication(arr_cMatrix) << endl;
    //cout << "Matrix-Vector Multiplication Result = " << endl << file_cMatrix.Multiplication(arr3_cMatrix) << endl;
    //cout << "Matrix-Number Multiplication Result = " << endl << file_cMatrix.Multiplication( 6 ) << endl;

    //! Creating Vectors by selecting row or column.
    CVector<int> rowVector = file_cMatrix.GetRow(1);
    cout <<"rowVector = " <<  rowVector << endl ;
    CVector<int> colVector = file_cMatrix.GetCol(3);
    cout <<"colVector = " <<  colVector << endl << endl ;

    //! Creating Identity Matrix as a static
    CMatrix<int> identityMatrix = CMatrix<int>::CreateIdentityMatrix(3);
    cout <<"Identity Matrix = "<< endl <<  identityMatrix << endl ;

    //! Augment Matrices
    CMatrix<int> augmentedMatrix = CMatrix<int>::Augment(file_cMatrix,identityMatrix);
    cout << "Augment Matrix = " << endl <<  augmentedMatrix << endl;

    //! Transpose Matrix
    cout << "Transposed Matrix = " << endl << file_cMatrix << endl;

    //! SubMatrix
    cout << "Sub Matrix = " << endl << file_cMatrix.SubMatrix(1,1) << endl;

    CMatrix<int> squareMatrix("C:\\Users\\tyyp-\\Desktop\\Repository\\Effective Programming\\Mini_project\\SquareMatrix.txt");
    //! CalculateDeterminant
    cout << "Determinant =  " << squareMatrix.CalculateDeterminant() << endl;

    //! CalculateMinor
    cout << "Minor [1][0] = " << squareMatrix.Minor(1,0) << endl;

    //! Cofactor
    cout << "Cofactor [1][0] = " << squareMatrix.Cofactor(1,0) << endl;

    //! Cofactor Matrix
    cout << "Cofactor Matrix = "<< endl << squareMatrix.CofactorMatrix() << endl;

    //! Adjuate Matrix
    cout << "Adjugate Matrix = "<< endl << squareMatrix.Adjugate() << endl;

    //! Matrix Inversion
    CMatrix<int> InverseMatrix = squareMatrix.Inverse();
    cout << "Inverted Matrix = " << endl << InverseMatrix << endl;



}

void TestDoubleMatrixClass()
{
    //! Constructors

    CMatrix<double> def_cMatrix;
    cout << "def_cMatrix " << endl << def_cMatrix << endl;

    CMatrix<double> par_cMatrix(3,6);
    par_cMatrix.FillAllMatrix(10.5);
    cout << "par_cMatrix " << endl << par_cMatrix << endl;


    double **arr;
    arr = new double* [6];
    for (int i=0; i < 6; i++)
        arr[i] = new double[3];
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j)
            arr[i][j] = i + j + 1.8;
    }

    double **arr3;
    arr3 = new double* [6];
    for (int i=0; i < 6; i++)
        arr3[i] = new double[1];
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 1; ++j)
            arr3[i][j] = i + j + 1.1;
    }

    CMatrix<double> arr_cMatrix(arr, 6, 3);
    cout << "arr_cMatrix " << endl << arr_cMatrix << endl;

    CMatrix<double> arr3_cMatrix(arr3, 6, 1);
    cout << "arr3_cMatrix " << endl << arr3_cMatrix << endl;


    CMatrix<double> copy_cMatrix(arr_cMatrix);

    //CMatrix<double> move_cMatrix(ReturnRValueMatrix(arr_cMatrix));

    CMatrix<double> file_cMatrix("C:\\Users\\tyyp-\\Desktop\\Repository\\Effective Programming\\Mini_project\\MatrixExample-2.txt.txt");
    cout << "file_cMatrix " << endl << file_cMatrix << endl;


    //! Setter and Getters
    file_cMatrix.SetMatrixElement(0,1,25.7);
    cout << "new file_cMatrix [0][1] changed to 25.7" << endl << file_cMatrix << endl;

    cout << "Row Size = " << file_cMatrix.GetRowSize() << endl;
    cout << "Col Size = " << file_cMatrix.GetColSize() << endl;

    arr = file_cMatrix.m_GetMatrix();

    cout << "Matrix [2][1] element is = "<<  file_cMatrix.GetMatrixElement(2,1) << endl;

    double arr2[] = {1.2,2.1,3.9,4.234,5.43,6.74};
    CVector<double> arr_cVector(arr2, 6);
    cout <<"arr_cVector" <<  arr_cVector << endl << endl;

    //! Mathematical Methods
    //cout << "Addition Result = " << endl << file_cMatrix.Addition(par_cMatrix) << endl;
    //cout << "Subtraction Result = " << endl << file_cMatrix.Subtraction(par_cMatrix) << endl;
    cout << "Matrix-Matrix Multiplication Result = " << endl << file_cMatrix.Multiplication(arr_cMatrix) << endl;
    //cout << "Matrix-Vector Multiplication Result = " << endl << file_cMatrix.Multiplication(arr3_cMatrix) << endl;
    //cout << "Matrix-Number Multiplication Result = " << endl << file_cMatrix.Multiplication( 6 ) << endl;

    //! Creating Vectors by selecting row or column.
    CVector<double> rowVector = file_cMatrix.GetRow(1);
    cout <<"rowVector = " <<  rowVector << endl ;
    CVector<double> colVector = file_cMatrix.GetCol(3);
    cout <<"colVector = " <<  colVector << endl << endl ;

    //! Creating Identity Matrix as a static
    CMatrix<double> identityMatrix = CMatrix<double>::CreateIdentityMatrix(3);
    cout <<"Identity Matrix = "<< endl <<  identityMatrix << endl ;

    //! Augment Matrices
    CMatrix<double> augmentedMatrix = CMatrix<double>::Augment(file_cMatrix,identityMatrix);
    cout << "Augment Matrix = " << endl <<  augmentedMatrix << endl;

    //! Transpose Matrix
    cout << "Transposed Matrix = " << endl << file_cMatrix << endl;

    //! SubMatrix
    cout << "Sub Matrix = " << endl << file_cMatrix.SubMatrix(1,1) << endl;

    CMatrix<double> squareMatrix("C:\\Users\\tyyp-\\Desktop\\Repository\\Effective Programming\\Mini_project\\SquareMatrixDouble.txt");
    //! CalculateDeterminant
    cout << "Determinant =  " << squareMatrix.CalculateDeterminant() << endl;

    //! CalculateMinor
    cout << "Minor [1][0] = " << squareMatrix.Minor(1,0) << endl;

    //! Cofactor
    cout << "Cofactor [1][0] = " << squareMatrix.Cofactor(1,0) << endl;

    //! Cofactor Matrix
    cout << "Cofactor Matrix = "<< endl << squareMatrix.CofactorMatrix() << endl;

    //! Adjuate Matrix
    cout << "Adjugate Matrix = "<< endl << squareMatrix.Adjugate() << endl;

    //! Matrix Inversion
    CMatrix<double> InverseMatrix = squareMatrix.Inverse();
    cout << "Inverted Matrix = " << endl << InverseMatrix << endl;

}


void TestFloatMatrixClass()
{
    //! Constructors

    CMatrix<float> def_cMatrix;
    cout << "def_cMatrix " << endl << def_cMatrix << endl;

    CMatrix<float> par_cMatrix(3,6);
    par_cMatrix.FillAllMatrix(10.5);
    cout << "par_cMatrix " << endl << par_cMatrix << endl;


    float **arr;
    arr = new float* [6];
    for (int i=0; i < 6; i++)
        arr[i] = new float[3];
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j)
            arr[i][j] = i + j + 1.8;
    }

    float **arr3;
    arr3 = new float* [6];
    for (int i=0; i < 6; i++)
        arr3[i] = new float[1];
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 1; ++j)
            arr3[i][j] = i + j + 1.1;
    }

    CMatrix<float> arr_cMatrix(arr, 6, 3);
    cout << "arr_cMatrix " << endl << arr_cMatrix << endl;

    CMatrix<float> arr3_cMatrix(arr3, 6, 1);
    cout << "arr3_cMatrix " << endl << arr3_cMatrix << endl;


    CMatrix<float> copy_cMatrix(arr_cMatrix);

    //CMatrix<float> move_cMatrix(ReturnRValueMatrix(arr_cMatrix));

    CMatrix<float> file_cMatrix("C:\\Users\\tyyp-\\Desktop\\Repository\\Effective Programming\\Mini_project\\MatrixExample-2.txt.txt");
    cout << "file_cMatrix " << endl << file_cMatrix << endl;


    //! Setter and Getters
    file_cMatrix.SetMatrixElement(0,1,25.7);
    cout << "new file_cMatrix [0][1] changed to 25.7" << endl << file_cMatrix << endl;

    cout << "Row Size = " << file_cMatrix.GetRowSize() << endl;
    cout << "Col Size = " << file_cMatrix.GetColSize() << endl;

    arr = file_cMatrix.m_GetMatrix();

    cout << "Matrix [2][1] element is = "<<  file_cMatrix.GetMatrixElement(2,1) << endl;

    float arr2[] = {1.2,2.1,3.9,4.234,5.43,6.74};
    CVector<float> arr_cVector(arr2, 6);
    cout <<"arr_cVector" <<  arr_cVector << endl << endl;

    //! Mathematical Methods
    //cout << "Addition Result = " << endl << file_cMatrix.Addition(par_cMatrix) << endl;
    //cout << "Subtraction Result = " << endl << file_cMatrix.Subtraction(par_cMatrix) << endl;
    cout << "Matrix-Matrix Multiplication Result = " << endl << file_cMatrix.Multiplication(arr_cMatrix) << endl;
    //cout << "Matrix-Vector Multiplication Result = " << endl << file_cMatrix.Multiplication(arr3_cMatrix) << endl;
    //cout << "Matrix-Number Multiplication Result = " << endl << file_cMatrix.Multiplication( 6 ) << endl;

    //! Creating Vectors by selecting row or column.
    CVector<float> rowVector = file_cMatrix.GetRow(1);
    cout <<"rowVector = " <<  rowVector << endl ;
    CVector<float> colVector = file_cMatrix.GetCol(3);
    cout <<"colVector = " <<  colVector << endl << endl ;

    //! Creating Identity Matrix as a static
    CMatrix<float> identityMatrix = CMatrix<float>::CreateIdentityMatrix(3);
    cout <<"Identity Matrix = "<< endl <<  identityMatrix << endl ;

    //! Augment Matrices
    CMatrix<float> augmentedMatrix = CMatrix<float>::Augment(file_cMatrix,identityMatrix);
    cout << "Augment Matrix = " << endl <<  augmentedMatrix << endl;

    //! Transpose Matrix
    cout << "Transposed Matrix = " << endl << file_cMatrix << endl;

    //! SubMatrix
    cout << "Sub Matrix = " << endl << file_cMatrix.SubMatrix(1,1) << endl;

    CMatrix<float> squareMatrix("C:\\Users\\tyyp-\\Desktop\\Repository\\Effective Programming\\Mini_project\\SquareMatrixDouble.txt");
    //! CalculateDeterminant
    cout << "Determinant =  " << squareMatrix.CalculateDeterminant() << endl;

    //! CalculateMinor
    cout << "Minor [1][0] = " << squareMatrix.Minor(1,0) << endl;

    //! Cofactor
    cout << "Cofactor [1][0] = " << squareMatrix.Cofactor(1,0) << endl;

    //! Cofactor Matrix
    cout << "Cofactor Matrix = "<< endl << squareMatrix.CofactorMatrix() << endl;

    //! Adjuate Matrix
    cout << "Adjugate Matrix = "<< endl << squareMatrix.Adjugate() << endl;

    //! Matrix Inversion
    CMatrix<float> InverseMatrix = squareMatrix.Inverse();
    cout << "Inverted Matrix = " << endl << InverseMatrix << endl;

}


int main() {

    //TestIntVectorClass();
    //TestDoubleVectorClass();
    //TestFloatVectorClass();

    TestIntBasicMatrixClass();
    //TestDoubleMatrixClass();
    //TestFloatMatrixClass();

    return 0;
}
