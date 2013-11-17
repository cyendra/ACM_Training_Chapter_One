#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int M=10007;
typedef vector<int>vec;
typedef vector<vec>mat;
mat mul(mat &A,mat &B){
    mat C(A.size(),vec(B[0].size()));
    for (int i=0;i<(int)A.size();i++){
        for (int k=0;k<(int)B.size();k++){
            for (int j=0;j<(int)B[0].size();j++){
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%M;
            }
        }
    }
    return C;
}
mat pow(mat A,LL n){
    mat B(A.size(),vec(A.size()));
    for (int i=0;i<(int)A.size();i++){
        B[i][i]=1;
    }
    while (n>0){
        if (n&1) B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
const int f[3][3]={ {2,1,0},{2,2,2},{0,1,2} };
const int a[1][3]={ {1,0,0} };
int main()
{
    int T;
    scanf("%d",&T);
    while (T--){
        int n;
        scanf("%d",&n);
        mat A(3,vec(3));
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                A[i][j]=f[i][j];
        A=pow(A,n);
        mat B(1,vec(3));
        for (int i=0;i<3;i++) B[0][i]=a[0][i];
        A=mul(A,B);
        printf("%d\n",A[0][0]);
    }
    return 0;
}
