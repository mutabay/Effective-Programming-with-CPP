//
// Created by tyyp- on 1/13/2021.
//

#ifndef MINI_PROJECT_CMATRIX_H
#define MINI_PROJECT_CMATRIX_H

using namespace std;

#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include "CVector.h"

#define DEF_ROW_SIZE 4
#define DEF_COL_SIZE 4


template<typename T>
class CMatrix{
private:
    unsigned s_rowSize;
    unsigned s_columnSize;
    T ** m_matrix;

    void AllocateMemory();

public:
    // Def Ctor.
    CMatrix();
    // Parametric Ctor.
    CMatrix(unsigned s_rowSize ,unsigned s_colSize );
    // Takes Double Pointer - 2D arg.
    CMatrix(T ** m_OtherMatrix, unsigned s_rowSize, unsigned s_colSize);
    // Copy Ctor.
    CMatrix(const CMatrix<T> & c_Other);
    // Move Ctor.
    CMatrix(CMatrix<T> &&c_Other) noexcept ;
    // Read Matrix From File
    explicit CMatrix(const char * fileName);
    // Destructor
    ~CMatrix();

    // Print
    void PrintMatrix();

    // Mutator Methods
    void SetMatrixElement(unsigned rowIndex, unsigned colIndex, T value) const;

    // Accessor Methods
    unsigned GetRowSize() { return s_rowSize;}
    unsigned GetColSize() { return s_columnSize;}
    T ** m_GetMatrix() const { return m_matrix;}
    T GetMatrixElement(unsigned rowIndex, unsigned colIndex) const;

    // Helper Methods
    void FillAllMatrix(T value);


    // --- Mathematical Functions ---

    //Addition of two matrices
    CMatrix<T> Addition(const CMatrix & c_Other ) const  ;
    //Subtraction of two matrices
    CMatrix<T> Subtraction(const CMatrix & c_Other ) const;
    //Method Overloading
    //Multiplication of two matrices.
    CMatrix<T> Multiplication(const CMatrix & c_Other) const;
    //Multiplication matrix and vector.
    CVector<T> Multiplication(const CVector<T> & c_Vector ) const ;
    //Multiplication matrix and number
    CMatrix<T> Multiplication(T number) const;


    // Returns vector which selected row on matrix
    CVector<T> GetRow(unsigned rowLocation);
    // Returns vector which selected column on matrix
    CVector<T> GetCol(unsigned colLocation);

    //Static Class Methods
    //Creates Identity Matrix
    static CMatrix<T> CreateIdentityMatrix(unsigned size);

    //Solves matrix equations using Gauss Elimination Method.

    //Assemble two given matrix
    static CMatrix<T> Augment(CMatrix<T> c_Matrix1, CMatrix<T> c_Matrix2);


    // Returns true if matrix is square.
    bool IsSquareMatrix();
    // Returns the transposition of the current matrix.
    CMatrix<T> Transpose() const ;
    //Returns a submatrix of the current matrix, removing one row and column of the original matrix
    CMatrix<T> SubMatrix(unsigned rowLocation, unsigned colLocation) const ;

    //Determinant calculator
    T CalculateDeterminant();
    //Returns the minor of a matrix, which is the determinant of a submatrix
    T Minor(unsigned rowLocation, unsigned colLocation) const ;
    // Calculates the cofactor of a matrix at a given point
    T Cofactor(unsigned rowLocation, unsigned colLocation) const ;
    // Calculates the cofactor matrix
    CMatrix<T> CofactorMatrix() const ;
    // Returns the adjugate of the current matrix, which is the transpose of its cofactor matrix
    CMatrix<T> Adjugate() const;
    // Calculates the inverse of the current matrix.
    CMatrix<T> Inverse() ;


    //Operator Overloadings
    //Copy operator
    CMatrix<T> operator=(const CMatrix<T> &c_Other);
    //Move operator
    CMatrix<T> operator=(CMatrix<T> &&c_Other) noexcept ;
    bool operator==(const CMatrix<T> & c_Other);
    bool operator!=(const CMatrix<T> & c_Other);
    T operator() (unsigned rowIndex, unsigned colIndex );
    CMatrix<T> operator+=(const CMatrix<T> & c_Other);
    CMatrix<T> operator-=(const CMatrix<T> & c_Other);
    CMatrix<T> operator*=(const CMatrix<T> & c_Other);
    CMatrix<T> operator*=(const T & number);

    friend ostream& operator<<(ostream & out, const CMatrix<T> & c_Matrix1)
    {
        for (int i = 0; i < c_Matrix1.s_rowSize ; ++i) {
            for (int j = 0; j < c_Matrix1.s_columnSize; ++j)
                out << " " << c_Matrix1.m_matrix[i][j] << " ";

            out << endl;
        }
        return out;
    }
};

template <class T> CMatrix<T> operator+(const CMatrix<T> & c_Matrix1, const CMatrix<T> & c_Matrix2);
template <class T> CMatrix<T> operator-(const CMatrix<T> & c_Matrix1, const CMatrix<T> & c_Matrix2);
template <class T> CMatrix<T> operator*(const CMatrix<T> & c_Matrix1, const CMatrix<T> & c_Matrix2);
template <class T> CMatrix<T> operator*(const CMatrix<T> & c_Matrix1, const T & value);


template<typename T>
CMatrix<T>::CMatrix():s_rowSize(DEF_ROW_SIZE), s_columnSize(DEF_COL_SIZE){
    AllocateMemory();
    //m_matrix = CVector< CVector<T> >(s_rowSize, CVector<T>(s_columnSize) );
    FillAllMatrix(0);
}

template<typename T>
CMatrix<T>::CMatrix(unsigned s_rowSize, unsigned s_colSize):s_rowSize(s_rowSize), s_columnSize(s_colSize){
    if(0 >= s_rowSize || 0 >= s_colSize)
    {
        cout << "Size of other matrix must be greater than 0.";
        exit(1);
    }
    AllocateMemory();
    //m_matrix = CVector< CVector<T> >(s_rowSize, CVector<T>(s_columnSize));
    FillAllMatrix(0);
}

template<typename T>
CMatrix<T>::CMatrix(T ** m_OtherMatrix, unsigned s_rowSize, unsigned s_colSize):s_rowSize(s_rowSize),s_columnSize(s_colSize){
    if(0 >= s_rowSize || 0 >= s_colSize)
    {
        cout << "Size of other matrix must be greater than 0.";
        exit(1);
    }
    AllocateMemory();
    for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex) {
        for (int colIndex = 0; colIndex < s_columnSize; ++colIndex)
            m_matrix[rowIndex][colIndex] = m_OtherMatrix[rowIndex][colIndex];
    }
}

template<typename T>
CMatrix<T>::CMatrix(const CMatrix &c_Other) {
    s_rowSize = c_Other.s_rowSize;
    s_columnSize = c_Other.s_columnSize;
    AllocateMemory();
    for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex) {
        for (int colIndex = 0; colIndex < s_columnSize; ++colIndex)
            m_matrix[rowIndex][colIndex] = c_Other.m_matrix[rowIndex][colIndex];
    }
    cout << "Copy Constructor worked "<< endl;
}

template<typename T>
CMatrix<T>::CMatrix(CMatrix &&c_Other) noexcept {

    s_rowSize = c_Other.s_rowSize;
    s_columnSize = c_Other.s_columnSize;
    AllocateMemory();
    for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex) {
        for (int colIndex = 0; colIndex < s_columnSize; ++colIndex)
            m_matrix[rowIndex][colIndex] = c_Other.m_matrix[rowIndex][colIndex];
    }

    for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex)
        delete c_Other.m_matrix[rowIndex];
    delete c_Other.m_matrix;

    c_Other.s_rowSize = 0;
    c_Other.s_columnSize = 0;
    cout << "Move Constructor worked  " << endl;
}

template<typename T>
CMatrix<T>::CMatrix(const char * fileName) {

    ifstream s_file(fileName);
    string is_line;
    unsigned rowSize = 0;
    unsigned colSize = 0;
    unsigned controller = 0;
    unsigned index = 0;
    T element;
    T * p_vector = nullptr;

    if( s_file.is_open() && s_file.good() )
    {
        cout << "File is successfully opened. --- " << fileName << endl;
        while ( getline(s_file,is_line) )
        {
            //TODO delete if
            rowSize++;
            if (!s_file )
                break;

            stringstream s_stream(is_line);
            colSize = 0;
            while(true)
            {
                s_stream >> element;
                if(!s_stream)
                    break;
                colSize++;
                T * p_temp = new T[index + 1];
                //Copy p_vector to p_temp
                for (int i = 0; i < index; ++i)
                    p_temp[i] = p_vector[i];

                p_temp[index] = element;
                p_vector = p_temp;
                index++;
            }

            if (controller == 0)
                controller = colSize;
            else if (controller != colSize)
            {
                cerr << "Error line " << rowSize << " - " << colSize <<
                     "values instead of " << controller << endl;
                exit(1);
            }

        }
    } else
    {
        cerr << "File COULD NOT open. --- " << fileName << endl;
        exit(1);
    }

    s_rowSize = rowSize;
    s_columnSize = colSize;
    //m_matrix = CVector< CVector<T> >(s_rowSize, CVector<T>(s_columnSize));
    AllocateMemory();
    index = 0;
    for (int rowIndex = 0; rowIndex < rowSize; ++rowIndex) {
        for (int colIndex = 0; colIndex < colSize; ++colIndex) {
            m_matrix[rowIndex][colIndex] = p_vector[index];
            index++;
        }
    }
    if(p_vector)
        delete [] p_vector;
}



template<typename T>
CMatrix<T>::~CMatrix() {


    for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex)
        delete m_matrix[rowIndex];
    if(m_matrix)
        delete m_matrix;
    s_rowSize = 0;
    s_columnSize = 0;
}

template<typename T>
void CMatrix<T>::AllocateMemory() {
    m_matrix = new T*[s_rowSize];
    for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex)
        m_matrix[rowIndex] = new T[s_columnSize];

}

template<typename T>
void CMatrix<T>::SetMatrixElement(unsigned int rowIndex, unsigned int colIndex, T value) const {
    if(rowIndex >= s_rowSize || colIndex >= s_columnSize)
    {
        cout << "RowIndex or-and ColIndex args are out of bound" << endl;
        exit(1);
    }
    m_matrix[rowIndex][colIndex] = value;
}

template<typename T>
T CMatrix<T>::GetMatrixElement(unsigned int rowIndex, unsigned int colIndex) const{
    if(rowIndex < s_rowSize && colIndex < s_columnSize)
        return m_matrix[rowIndex][colIndex];
    cout << "RowIndex or ColIndex args are not withing boundaries." << endl;
    exit(1);
}

template<typename T>
void CMatrix<T>::FillAllMatrix(T value) {
    for (int i = 0; i < s_rowSize; ++i) {
        for (int j = 0; j < s_columnSize; ++j)
            m_matrix[i][j] = value;
    }
}


template<typename T>
bool CMatrix<T>::IsSquareMatrix() {
    return (s_rowSize == s_columnSize);
}


template<typename T>
void CMatrix<T>::PrintMatrix() {
    for (int i = 0; i < s_rowSize; ++i) {
        for (int j = 0; j < s_columnSize; ++j)
            cout << " " << m_matrix[i][j] << " ";

        cout << endl;
    }
}

template<typename T>
CMatrix<T> CMatrix<T>::Addition(const CMatrix &c_Other) const {
    // For addition operation, matrices have to same sizes.
    if ( ! (s_rowSize == c_Other.s_rowSize && s_columnSize == c_Other.s_columnSize ))
    {
        cerr<< "Runtime Error - Not compatible for addition. Matrices must have same sizes  - Addition"  << endl ;
        exit(2);
    }


    CMatrix<T> c_addition(s_rowSize, s_columnSize);
    for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex) {
        for (int columnIndex = 0; columnIndex < s_columnSize; ++columnIndex)
            c_addition.m_matrix[rowIndex][columnIndex] = m_matrix[rowIndex][columnIndex] + c_Other.m_matrix[rowIndex][columnIndex];
    }

    return c_addition;
}

template<typename T>
CMatrix<T> CMatrix<T>::Subtraction(const CMatrix &c_Other) const{
    if ( ! (s_rowSize == c_Other.s_rowSize && s_columnSize == c_Other.s_columnSize ))
    {
        cerr<< "Runtime Error - Not compatible for subtraction. Matrices must have same sizes  - Subtraction"  << endl ;
        exit(2);
    }

    CMatrix<T> c_subtraction(s_rowSize, s_columnSize);
    for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex) {
        for (int columnIndex = 0; columnIndex < s_columnSize; ++columnIndex)
            c_subtraction.m_matrix[rowIndex][columnIndex] = m_matrix[rowIndex][columnIndex] - c_Other.m_matrix[rowIndex][columnIndex];

    }
    return c_subtraction;
}

template<typename T>
CMatrix<T> CMatrix<T>::Multiplication(const CMatrix &c_Other)const {
    if ( s_columnSize != c_Other.s_rowSize )
    {
        cerr<< "Runtime Error - Not compatible for multiplication. 1st matrices column number must equal to 2nd matrices row number "  << endl ;
        exit(2);

    }

    CMatrix<T> c_multiplication(s_rowSize, c_Other.s_columnSize);
    for (int i = 0; i < c_multiplication.s_rowSize; ++i) {
        for (int j = 0; j < c_multiplication.s_columnSize; ++j) {
            for (int k = 0; k < s_columnSize; ++k)
                c_multiplication.m_matrix[i][j] += (m_matrix[i][k] * c_Other.m_matrix[k][j]);
        }
    }
    return c_multiplication;
}

template<typename T>
CVector<T> CMatrix<T>::Multiplication(const CVector<T> &c_Vector) const {
    if ( s_columnSize != c_Vector.s_size )
    {
        cerr << "Not compatible for multiplication. 1st matrices column number must equal to vector's size" << endl;
        exit(2);
    }

    CVector<T> c_multiplication( s_rowSize);
    for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex) {
        for (int colIndex = 0; colIndex < s_columnSize; ++colIndex)
            c_multiplication.vector[rowIndex] +=  m_matrix[rowIndex][colIndex] * c_Vector[rowIndex];
    }
    return c_multiplication;
}

template<typename T>
CMatrix<T> CMatrix<T>::Multiplication(T number) const{
    CMatrix<T> c_multiplication(s_rowSize, s_columnSize);
    for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex) {
        for (int colIndex = 0; colIndex < s_columnSize; ++colIndex)
            c_multiplication.m_matrix[rowIndex][colIndex] = m_matrix[rowIndex][colIndex] * number;
    }
    return c_multiplication;
}


template<typename T>
CVector<T> CMatrix<T>::GetRow(unsigned int rowLocation) {
    if(rowLocation > s_rowSize)
    {
        cout << "RowIndex or-and ColIndex args are out of bound" << endl;
        exit(2);
    }
    CVector<T> rowVector(s_columnSize);

    for (int colIndex = 0; colIndex < s_columnSize; ++colIndex)
        rowVector[colIndex] = m_matrix[rowLocation - 1][colIndex];
    
    return rowVector;
}

template<typename T>
CVector<T> CMatrix<T>::GetCol(unsigned int colLocation) {
    if(colLocation > s_columnSize)
    {
        cout << "RowIndex or-and ColIndex args are out of bound" << endl;
        exit(2);
    }
    CVector<T> colVector(s_rowSize);

    for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex)
        colVector[rowIndex] = m_matrix[rowIndex][colLocation - 1];

    return colVector;
}


template<typename T>
CMatrix<T> CMatrix<T>::CreateIdentityMatrix(unsigned size) {
    CMatrix<T> identityMatrix(size,size);
    for (int rowIndex = 0; rowIndex < size; ++rowIndex) {
        for (int colIndex = 0; colIndex < size; ++colIndex) {
            if(rowIndex == colIndex)
                identityMatrix.m_matrix[rowIndex][colIndex] = 1;
            else
                identityMatrix.m_matrix[rowIndex][colIndex] = 0;
        }
    }
    return identityMatrix;
}

template<typename T>
CMatrix<T> CMatrix<T>::Augment(CMatrix<T> c_Matrix1, CMatrix<T> c_Matrix2) {
    if ( c_Matrix1.s_rowSize != c_Matrix2.s_rowSize )
    {
        cerr<< "Runtime Error - Not compatible for augmentation. Row size's must same"  << endl ;
        exit(2);
    }
    CMatrix<T> augmentedMatrix(c_Matrix1.s_rowSize, c_Matrix1.s_columnSize + c_Matrix2.s_columnSize);
    for (int rowIndex = 0; rowIndex < augmentedMatrix.s_rowSize; ++rowIndex) {
        for (int colIndex = 0; colIndex < augmentedMatrix.s_columnSize; ++colIndex) {
            if(colIndex < c_Matrix1.s_columnSize)
                augmentedMatrix.m_matrix[rowIndex][colIndex] = c_Matrix1.m_matrix[rowIndex][colIndex];
            else
                augmentedMatrix.m_matrix[rowIndex][colIndex] = c_Matrix2.m_matrix[rowIndex][colIndex - c_Matrix1.s_columnSize];
        }
    }
    return augmentedMatrix;
}

template<typename T>
CMatrix<T> CMatrix<T>::Transpose() const {
    CMatrix<T> transposedMatrix(s_columnSize, s_rowSize);
    for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex) {
        for (int colIndex = 0; colIndex < s_columnSize; ++colIndex)
            transposedMatrix.m_matrix[colIndex][rowIndex] = m_matrix[rowIndex][colIndex];
    }
    return transposedMatrix;
}


template<typename T>
CMatrix<T> CMatrix<T>::SubMatrix(unsigned int rowLocation, unsigned int colLocation) const {
    CMatrix<T> subMatrix(s_rowSize - 1, s_columnSize - 1);
    unsigned subRowIndex = 0;
    for (int rowIndex = 0; rowIndex < s_rowSize ; ++rowIndex) {
        unsigned subColIndex = 0;
        if (rowIndex == rowLocation)
            continue;
        for (int colIndex = 0; colIndex < s_columnSize ; ++colIndex) {
            if(colIndex == colLocation)
                continue;
            subMatrix.m_matrix[subRowIndex][subColIndex] = m_matrix[rowIndex][colIndex];
            subColIndex++;
        }
        subRowIndex++;
    }

    return subMatrix;
}

template<typename T>
T CMatrix<T>::CalculateDeterminant() {
    if( !IsSquareMatrix() )
    {
        cerr<< "Runtime Error - Cannot invert a non-square matrix" << endl ;
        exit(2);
    }


    T determinant = 0;
    if (2 == s_rowSize)
        return ( (m_matrix[0][0] * m_matrix[1][1] ) - (m_matrix[0][1] * m_matrix[1][0]) );
    else
    {
        for (int index = 0; index < s_rowSize; ++index) {
            if(index % 2 == 0)
                determinant += 1 * m_matrix[0][index] * SubMatrix(0,index).CalculateDeterminant();
            else
                determinant += -1 * m_matrix[0][index] * SubMatrix(0,index).CalculateDeterminant();
        }
    }
    return determinant;
}

template<typename T>
T CMatrix<T>::Minor(unsigned int rowLocation, unsigned int colLocation) const {
    //TODO DELETE UNNECESSARY IF BLOCK
    if(s_rowSize == 2 && s_columnSize == 2)
    {
        CMatrix<T> minorMatrix(s_rowSize, s_columnSize);
        minorMatrix.m_matrix[0][0] = m_matrix[1][1];
        minorMatrix.m_matrix[1][1] = m_matrix[0][0];
        minorMatrix.m_matrix[1][0] = m_matrix[0][1];
        minorMatrix.m_matrix[0][1] = m_matrix[1][0];
        return minorMatrix.CalculateDeterminant();
    }
    return SubMatrix(rowLocation,colLocation).CalculateDeterminant();
}

template<typename T>
T CMatrix<T>::Cofactor(unsigned int rowLocation, unsigned int colLocation) const {
    T minor;

    // Special case for when our matrix 2x2
    if(s_rowSize == 2 && s_columnSize == 2)
    {
        //TODO Change All of these if blocks to submatrix of 2x2 matrix
        if(rowLocation == 0 and colLocation == 0)
            minor = m_matrix[1][1];
        else if (rowLocation == 1 and colLocation == 1)
            minor = m_matrix[0][0];
        else if (rowLocation == 0 and colLocation == 1)
            minor = m_matrix[1][0];
        else if (rowLocation == 1 and colLocation == 0)
            minor = m_matrix[0][1];
    } else
        minor = Minor(rowLocation, colLocation);

    return (rowLocation + colLocation) % 2 == 0 ? minor : -minor;
}


template<typename T>
CMatrix<T> CMatrix<T>::CofactorMatrix() const {
    CMatrix<T> cofactorMatrix(s_rowSize, s_columnSize);
    for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex) {
        for (int colIndex = 0; colIndex < s_columnSize; ++colIndex)
            cofactorMatrix.m_matrix[rowIndex][colIndex] = Cofactor(rowIndex, colIndex);
    }

    return cofactorMatrix;
}

template<typename T>
CMatrix<T> CMatrix<T>::Adjugate() const{
    return CofactorMatrix().Transpose();
}

template<typename T>
CMatrix<T> CMatrix<T>::Inverse() {
    if( !IsSquareMatrix() )
    {
        cerr<< "Runtime Error - Cannot invert a non-square matrix" << endl ;
        exit(2);
    }


    T determinant = CalculateDeterminant();
    if(0 == determinant)
    {
        cerr<< "Runtime Error - Cannot invert a non-square matrix" << endl ;
        exit(1);
    }



    CMatrix<T> adjugateMatrix = Adjugate();
    return adjugateMatrix * (1 / determinant);
}

//Operator Overloading Region
#pragma region


template<typename T>
CMatrix<T> CMatrix<T>::operator=(const CMatrix<T> &c_Other) {

    s_rowSize = c_Other.s_rowSize;
    s_columnSize = c_Other.s_columnSize;
    AllocateMemory();
    for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex) {
        for (int colIndex = 0; colIndex < s_columnSize; ++colIndex)
            m_matrix[rowIndex][colIndex] = c_Other[rowIndex][colIndex];
    }
    cout << "Copy Operator worked "<< endl;

    return (*this);
}

template<typename T>
CMatrix<T> CMatrix<T>::operator=(CMatrix<T> &&c_Other) noexcept {
    if(0 == c_Other.size() )
    {
        cout << "Size of other matrix must be greater than 0.";
        exit(1);
    }
    s_rowSize = c_Other.size();
    s_columnSize = c_Other.m_matrix[0].size();
    m_matrix = c_Other.m_matrix;

    for (int i = 0; i < s_rowSize; ++i)
        c_Other.m_matrix[i].erase();
    c_Other.m_matrix.erase();
    c_Other.s_rowSize = 0;
    c_Other.s_columnSize = 0;
    cout << "Move Operator worked  " << endl;

    return (*this);

}




template<typename T>
bool CMatrix<T>::operator==(const CMatrix<T> &c_Other) {
    if (s_rowSize == c_Other.s_rowSize && s_columnSize == c_Other.s_columnSize)
    {
        for (int rowIndex = 0; rowIndex < s_rowSize; ++rowIndex) {
            for (int colIndex = 0; colIndex < s_columnSize; ++colIndex) {
                if(m_matrix[rowIndex][colIndex] != c_Other.m_matrix[rowIndex][colIndex])
                    return false;
            }
        }
        return true;
    }
    return false;
}


template<typename T>
bool CMatrix<T>::operator!=(const CMatrix<T> &c_Other) {
    return !operator==(c_Other);
}

template<typename T>
T CMatrix<T>::operator()(unsigned int rowIndex, unsigned int colIndex) {
    return GetMatrixElement(rowIndex, colIndex);
}

template<typename T>
CMatrix<T> CMatrix<T>::operator+=(const CMatrix<T> &c_Other) {
    m_matrix = Addition(c_Other).m_matrix ;
    return *this;
}

template<typename T>
CMatrix<T> CMatrix<T>::operator-=(const CMatrix<T> &c_Other) {
    m_matrix = Subtraction(c_Other);
    return *this;
}

template<typename T>
CMatrix<T> CMatrix<T>::operator*=(const CMatrix<T> &c_Other) {
    *this = Multiplication(c_Other);
    return *this;
}

template<typename T>
CMatrix<T> CMatrix<T>::operator*=(const T & number) {
    *this = Multiplication(number);
    return *this;
}


template <class T>
CMatrix<T> operator+(const CMatrix<T> & c_Matrix1, const CMatrix<T> & c_Matrix2){
    return c_Matrix1.Addition(c_Matrix2);
}

template <class T>
CMatrix<T> operator-(const CMatrix<T> & c_Matrix1, const CMatrix<T> & c_Matrix2)
{
    return c_Matrix1.Subtraction(c_Matrix2);
}

template <class T>
CMatrix<T> operator*(const CMatrix<T> & c_Matrix1, const CMatrix<T> & c_Matrix2)
{
    return c_Matrix1.Multiplication(c_Matrix2);
}
template <class T>
CMatrix<T> operator*(const CMatrix<T> & c_Matrix1, const T & value)
{
    return c_Matrix1.Multiplication(value);
}

#pragma endregion






#endif //MINI_PROJECT_CMATRIX_H
