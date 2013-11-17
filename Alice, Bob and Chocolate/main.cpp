#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int t[100100];
int a[100100];
int b[100100];
int ansa,ansb;
int main()
{
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for (int i=0;i<n;i++)
    {
        scanf("%d",&t[i]);
        if (i==0)
        {
            a[i]=t[i];
        }
        else
        {
            a[i]=a[i-1]+t[i];
        }
    }
    for (int i=n-1;i>=0;i--)
    {
        if (i==n-1)
        {
            b[i]=t[i];
        }
        else
        {
            b[i]=b[i+1]+t[i];
        }
    }
    for (int i=0;i<n;i++)
    {
        if (a[i]>b[i])
        {
            ansa=i;
            break;
        }
    }
    ansb=n-ansa;
    if (n==1)
    {
        printf("1 0\n");
    }
    else
    {
        printf("%d %d\n",ansa,ansb);
    }
    return 0;
}
