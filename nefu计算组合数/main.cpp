#include <iostream>
#include <cstring>
using namespace std;

long long int a[50][50];
long long int S[50],T[50];

int main()
{
    int n;
    memset(a,0,sizeof(a));
    memset(S,0,sizeof(S));
    memset(T,0,sizeof(T));
    for (int i=0;i<=30;i++)
    {
        a[i][0]=a[i][i]=1;
        for (int j=0;j<=i;j++)
        {
            a[i+1][j+1]=a[i][j+1]+a[i][j];
        }
    }
    for (int i=1;i<=30;i++)
    {
        for (int j=1;j<=i;j++)
        {
            S[i]+=(j*a[i][j]);
        }
    }
    T[1]=S[1];
    for (int i=2;i<=30;i++)
    {
        T[i]=T[i-1]+S[i];
    }
    while (cin>>n)
    {
        cout<<T[n]<<endl;
    }
    return 0;
}
