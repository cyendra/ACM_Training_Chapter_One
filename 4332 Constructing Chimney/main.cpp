#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define BIT(x, y) ((x) & (1 << (y)))
using namespace std;

const int MOD=1000000007;
const int maxsize=256;

struct Matrix
{
    int element[maxsize][maxsize];

    Matrix(int s=maxsize)
    {
        for (int i=0;i<s;i++)
        {
            for (int j=0;j<s;j++)
            {
                element[i][j]=0;
            }
        }
    }

    void unit(int s=maxsize)
    {
        for (int i=0;i<s;i++)
        {
            element[i][i]=1;
        }
    }

};


Matrix mul(Matrix A, Matrix B)
{
    Matrix R(maxsize);
    for (int i=0; i<maxsize; i++)
        for (int j=0; j<maxsize; j++)
            for (int k=0; k<maxsize; k++)
            {
                R.element[i][j]+=A.element[i][k]*B.element[k][j];
                R.element[i][j]%=MOD;
            }
    return R;
}

Matrix pow(Matrix A,int exp)
{
    Matrix ret(maxsize);
    ret.unit();
    while (exp)
    {
        if (exp&1) ret=mul(A, ret);
        exp>>=1;
        A=mul(A,A);
    }
    return ret;
}

int T;
int n;

int main()
{
    int cas=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        Matrix f(maxsize);
        for (int i=0; i<maxsize; i++)
        {
            for (int j=0; j<maxsize; j++)
            {
                f.element[i][j]=1;
            }
        }
        f=pow(f,n);
        printf("Case %d: %d\n",++cas,f.element[maxsize-1][maxsize-1]);
    }
    return 0;
}
