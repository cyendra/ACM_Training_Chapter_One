#include <iostream>
#include <cstring>
using namespace std;

long long int a[50][50];

int main()
{
    int n,m;
    memset(a,0,sizeof(a));
    for (int i=0;i<=30;i++)
    {
        a[0][i]=1;
        a[i][0]=1;
    }
    for (int i=1;i<=30;i++)
    {
        for (int j=1;j<=30;j++)
        {
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    while (cin>>n>>m)
    {
        cout<<a[n][m]<<endl;
    }
    return 0;
}
