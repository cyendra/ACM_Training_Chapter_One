#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxsize=32;

struct Matrix
{
    int element[maxsize][maxsize];
    int size;
    int modulo;

    void init_matrix(int _size,int _modulo)
    {
        size=_size;
        modulo=_modulo;
        for (int i=0; i<_size; i++)
            for (int j=0; j<_size; j++)
                element[i][j]=0;
    }

    Matrix operator*(Matrix param)
    {
        Matrix product;
        product.init_matrix(size,modulo);
        for (int i=0; i<size; i++)
            for (int j=0; j<size; j++)
                for (int k=0; k<size; k++)
                {
                    product.element[i][j]+=element[i][k]*param.element[k][j];
                    product.element[i][j]%=modulo;
                }
        return product;
    }

    Matrix power(int exp)
    {
        Matrix tmp = (*this) * (*this);
        if (exp==1) return *this;
        else if (exp & 1) return tmp.power(exp/2) * (*this);
        else return tmp.power(exp/2);
    }

};
/*
class CMatrix{
    public:
        int element[maxsize][maxsize];
        void setSize(int _size);
        void setModulo(int _modulo);
        CMatrix operator*(CMatrix param);
        CMatrix power(int exp);
    private:
        int size;
        int modulo;
};

void CMatrix::setSize(int _size)
{
    for (int i=0;i<_size;i++)
        for (int j=0;j<_size;j++)
            element[i][j]=0;
    size=_size;
}

void CMatrix::setModulo(int _modulo)
{
    modulo = _modulo;
}

CMatrix CMatrix::operator*(CMatrix param)
{
    CMatrix product;
    product.setSize(size);
    product.setModulo(modulo);
    for (int i=0;i<size;i++)
        for (int j=0;j<size;j++)
            for (int k=0;k<size;k++)
            {
                product.element[i][j]+=element[i][k]*param.element[k][j];
                product.element[i][j]%=modulo;
            }
    return product;
}

CMatrix CMatrix::power(int exp)
{
    CMatrix tmp = (*this) * (*this);
    if (exp==1) return *this;
    else if (exp & 1) return tmp.power(exp/2) * (*this);
    else return tmp.power(exp/2);
}
*/

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
