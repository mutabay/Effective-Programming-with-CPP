//
// Created by tyyp- on 1/21/2021.
//

#ifndef MINI_PROJECT_CVECTOR_H
#define MINI_PROJECT_CVECTOR_H


#include <iostream>
#include <fstream>

using namespace std;

#define DEF_SIZE 4

template <typename T>
class CVector {
public:
    unsigned s_size;
    T * vector;


    // Def Ctor.
    CVector();
    //Parametric Ctor.
    explicit CVector(unsigned vector_size);
    // Parametric Ctor.
    explicit CVector(unsigned vector_size, T _value);
    //Takes Pointer - 1D arg.
    CVector(T * m_OtherVector, unsigned vector_size);
    //Copy Ctor.
    CVector(const CVector<T> & c_Other);
    //Move Ctor.
    CVector(CVector<T> && c_Other) noexcept ;
    //Destructor
    ~CVector();

    //Mutator Method
    void SetVectorElement(unsigned index, T value) const ;

    //Accessor Method
    T * GetVectorElement(unsigned index) const ;
    unsigned GetVectorSize();


    //Computes dot product(scalar product) of vectors.
    T ScalarProduct(const CVector<T> & c_Other) const ;
    //Computes cross product of vectors.
    CVector<T> CrossProduct(const CVector<T> & c_Other) const;


    //Copy operator
    CVector<T> operator=(const CVector<T> &c_Other);
    //Move operator
    CVector<T> operator=(CVector<T> &&c_Other) noexcept ;
    bool operator==(const CVector<T> & c_Other);
    bool operator!=(const CVector<T> & c_Other);
    T & operator[](unsigned index) { return vector[index];}
    const T & operator[](unsigned index) const { return vector[index];}
    // Scalar Product
    T operator*=(const CVector<T> & c_Other) ;

    friend ostream& operator<<(ostream & out, const CVector<T> & c_Vector1)
    {
        for (int index = 0; index < c_Vector1.s_size  ; ++index)
            out << c_Vector1.vector[index] << " ";

        return out;
    }
    void FillVector( T value);
};


template<typename T>
CVector<T>::CVector():s_size(DEF_SIZE) {
    vector = new T[s_size];
    FillVector(0);
}


template<typename T>
CVector<T>::CVector(unsigned vector_size):s_size(vector_size) {
    if(0 >= vector_size)
    {
        cout << "Size must be bigger than 0 " << endl;
        exit(1);
    }
    vector = new T[s_size];
    FillVector(0);
}


template<typename T>
CVector<T>::CVector(unsigned vector_size, T _value):s_size(vector_size) {
    if(0 >= vector_size)
    {
        cout << "Size must be bigger than 0 " << endl;
        exit(1);
    }
    vector = new T[s_size];
    FillVector(_value);
}


template<typename T>
CVector<T>::CVector(T * m_OtherVector, unsigned vector_size):s_size(vector_size) {
    if(0 >= vector_size)
    {
        cout << "Size must be bigger than 0 " << endl;
        exit(1);
    }
    vector = new T[s_size];
    for (int index = 0; index < s_size; ++index)
        vector[index] = m_OtherVector[index];
}


template<typename T>
CVector<T>::CVector(const CVector<T> &c_Other):s_size(c_Other.s_size) {
    vector = new T[s_size];
    for (int index = 0; index < s_size; ++index)
        vector[index] = c_Other.vector[index];

    cout << "Copy Constructor worked "<< endl;
}

template<typename T>
CVector<T>::CVector(CVector<T> &&c_Other) noexcept :s_size(c_Other.s_size) {
    vector = new T[s_size];
    for (int index = 0; index < s_size; ++index)
        vector[index] = c_Other[index];

    delete [] c_Other.vector;
    c_Other.s_size = 0;
    cout << "Move Constructor worked  " << endl;
}

template<typename T>
CVector<T>::~CVector() {
    vector = nullptr;
    delete [] vector;
    s_size = 0;
}

template<typename T>
void CVector<T>::FillVector(T value) {
    for (int index = 0; index < s_size; ++index)
        vector[index] = value;
}


template<typename T>
void CVector<T>::SetVectorElement(unsigned int index, T value) const {
    vector[index] = value;
}

template<typename T>
T *CVector<T>::GetVectorElement(unsigned int index) const {
    return vector[index];
}


template<typename T>
unsigned CVector<T>::GetVectorSize() {
    return s_size;
}

template<typename T>
T CVector<T>::ScalarProduct(const CVector<T> &c_Other) const {
    if (s_size != c_Other.s_size)
        cerr << "Runtime Error - Vector size's are NOT same" << endl;

    T result = 0;
    for (int index = 0; index < s_size; ++index)
        result += (vector[index] * c_Other.vector[index]);

    return result;
}

template<typename T>
CVector<T> CVector<T>::CrossProduct(const CVector<T> &c_Other) const {
    if (s_size != c_Other.s_size)
        cerr << "Runtime Error - Vector size's are NOT same" << endl;

    if (s_size != 3 )
        cerr << "Runtime Error - Vector size's must be 3 for Cross Product" << endl;

    CVector<T> result(s_size);
    result.vector[0] = vector[1] * c_Other.vector[2] - vector[2] * c_Other.vector[1];
    result.vector[1] = vector[2] * c_Other.vector[0] - vector[0] * c_Other.vector[2];
    result.vector[2] = vector[0] * c_Other.vector[1] - vector[1] * c_Other.vector[0];

    return result;
}

#pragma region

template<typename T>
CVector<T> CVector<T>::operator=(const CVector<T> &c_Other) {
    s_size = c_Other.s_size;
    vector = new T[s_size];
    for (int index = 0; index < s_size; ++index)
        vector[index] = c_Other.vector[index];

    cout << "Copy Operator worked "<< endl;
    return (*this);
}

template<typename T>
CVector<T> CVector<T>::operator=(CVector<T> &&c_Other) noexcept {
    s_size = c_Other.s_size;
    vector = new T[s_size];
    for (int index = 0; index < s_size; ++index)
        vector[index] = c_Other.vector[index];

    delete c_Other.vector;
    c_Other.s_size = 0;
    cout << "Move Operator worked  " << endl;

    return (*this);
}

template<typename T>
bool CVector<T>::operator==(const CVector<T> &c_Other) {
    if(s_size && c_Other.s_size)
    {
        for (int index = 0; index < s_size; ++index) {
            if(vector[index] != c_Other.vector[index])
                return false;
        }
        return true;
    }
    return false;
}

template<typename T>
bool CVector<T>::operator!=(const CVector<T> &c_Other) {
    return !( operator==(c_Other) );
}

template<typename T>
T CVector<T>::operator*=(const CVector<T> &c_Other) {
    *this = ScalarProduct(c_Other);
    return *this;
}




#pragma endregion
#endif //MINI_PROJECT_CVECTOR_H
