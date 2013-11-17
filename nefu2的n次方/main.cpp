#include <iostream>
#include <cstring>
using namespace std;


void mix(int *a,int b,int *c)
{
    int len;
    len=a[0];
    for (int i=1;i<=len;i++)
    {
        c[i]=a[i]*b;
    }
    for (int i=1;i<=len+len;i++)
    {
        c[i+1]+=c[i]/10;
        c[i]=c[i]%10;
        if (c[i+1]!=0)
        {
            len=i+1;
        }
    }
    c[0]=len;
}

int main()
{
    int a[111][111];
    int n;
    memset(a,0,sizeof(a));
    a[0][0]=1;
    a[0][1]=1;
    for (int i=1;i<=100;i++)
    {
        mix(a[i-1],2,a[i]);
    }
    while (cin>>n)
    {
        for (int i=a[n][0];i>=1;i--)
        {
            cout<<a[n][i];
        }
        cout<<endl;
    }
    return 0;
}
