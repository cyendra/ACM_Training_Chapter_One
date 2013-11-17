#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=111;
typedef long long LL;
/*==============================================*\
 | 最大公约数-辗转相除
\*==============================================*/
int gcd(int a,int b){
    if (b==0) return a;
    return gcd(b,a%b);
}
/*==============================================*\
 | 扩展欧几里得
 | ax+by=gcd(a,b)
\*==============================================*/
int extgcd(int a,int b,int& x,int& y){
    int d=a;
    if (b!=0){
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }else{
        x=1;y=0;
    }
    return d;
}
/*==============================================*\
 | 素数-埃氏筛法
\*==============================================*/
int prime[maxn];
bool is_prime[maxn+1];
int sieve(int n){
    int p=0;
    for (int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for (int i=2;i<=n;i++){
        if (is_prime[i]){
            prime[p++]=i;
            for (int j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
/*==============================================*\
 | 快速幂
\*==============================================*/
LL modPow(LL x,LL n,LL mod){
    if (n==0) return 1;
    LL res=modPow(x*x%mod,n/2,mod);
    if (n&1) res=res*x%mod;
    return res;
}
/*==============================================*\
 | 高斯消元-列主元
 | 求解Ax=b,A为矩阵 无解/多解时返回空数组
\*==============================================*/
//const double eps=1e-8;
//typedef vector<double>vec;
//typedef vector<vec>mat;
/*
vec gaussJordan(const mat& A,const vec& b){
    int n=A.size();
    mat B(n,vec(n+1));
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) B[i][j]=A[i][j];
    for (int i=0;i<n;i++) B[i][n]=b[i];
    for (int i=0;i<n;i++){
        int pivot=i;
        for (int j=i;j<n;j++){
            if (abs(B[j][i])>abs(B[pivot][i])) pivot=j;
        }
        swap(B[i],B[pivot]);
        if (abs(B[i][i]<eps)) return vec();//无解或多解
        for (int j=i+1;j<=n;j++) B[i][j]/=B[i][i];
        for (int j=0;j<n;j++){
            if (i!=j){
                for (int k=i+1;k<=n;k++) B[j][k]-=B[j][i]*B[i][k];
            }
        }
    }
    vec x(n);
    for (int i=0;i<n;i++) x[i]=B[i][n];
    return x;
}
*/
/*==============================================*\
 | 逆元
 | ax≡b(mod m) x=a逆×b
 | gcd(a,m)!=1逆元不存在
\*==============================================*/
int modInverse(int a,int m){
    int x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
/*==============================================*\
 | 矩阵快速幂
\*==============================================*/
const int M=10000;
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

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
