#include "Vector.h"
#include "Matrix.h"
template <class T>
VECTOR<T> operator *(Matrix<T>& matrix, VECTOR<T>& vector)
{
    if (matrix.GetM() == vector.GetSize())
    {
        T* arr = new T[matrix.GetM()];
        T** arr_matrix = matrix.GetMatrix();
        T* arr_vector = vector.GetVector();
       
        for (int i = 0; i < matrix.GetM(); i++)
        {
            arr[i] = 0;
            for (int j = 0; j < matrix.GetN(); j++)
            {
                arr[i] = arr[i] + (arr_matrix[i][j] * arr_vector[j]);

            }
        }
        VECTOR<T> result(matrix.GetN(), arr);
        delete[] arr;
        return result;
    }
    else
        throw - 1;
};

template <class T>
Matrix<T> operator *(VECTOR<T>& vector, Matrix<T>& matrix)
{
    if (matrix.GetN() == vector.Size() && matrix.GetM() == 1)
    {
        T** arr = new T * [matrix.GetN()];
        for (int i = 0; i < vector.GetSize(); i++)
            arr[i] = new T[vector.GetSize()];

        for (int i = 0; i < vector.GetSize(); i++)
            for (int j = 0; j < matrix.GetN(); j++)
            {
                arr[i][j] = (matrix[0][j] * vector[i]);
            }
        Matrix<T> result(matrix.GetN(), vector.GetSize(), arr);


        for (int i = 0; i < vector.GetSize(); i++)
            delete[] arr[i];
        delete[] arr;
        return result;
    }
    else
        throw - 1;
};

