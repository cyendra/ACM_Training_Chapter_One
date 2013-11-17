#include <iostream>
#include <cstring>
using namespace std;

void sum(int *a,int *b,int *c);

void sum(int *a,int *b,int *c)
{
    int len;
    if (a[0]>b[0])
    {
        len=a[0];
    }
    else
    {
        len=b[0];
    }
    for (int i=1;i<=len;i++)
    {
        c[i]=a[i]+b[i];
    }
    c[0]=len;
    for (int i=1;i<=len;i++)
    {
        if (c[i]>9)
        {
            c[i+1]+=c[i]/10;
            c[i]=c[i]%10;
        }
    }
    if (c[len+1]>0)
    {
        c[0]=c[0]+1;
    }
}

int main()
{
    int f[600][600];
    int n;
    memset(f,0,sizeof(f));
    f[0][0]=1;
    f[0][1]=1;
    f[1][0]=1;
    f[1][1]=1;
    for (int i=2;i<=500;i++)
    {
        sum(f[i-1],f[i-2],f[i]);
    }
    while (cin>>n)
    {
        for (int i=f[n][0];i>=1;i--)
        {
            cout<<f[n][i];
        }
        cout<<endl;
    }
    return 0;
}
