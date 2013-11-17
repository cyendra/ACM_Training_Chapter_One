#include <iostream>
#include <cstdio>
using namespace std;

int c=0;
int abss;
int han(int n,int a,int b)
{
    abss=a-b;
    if (abss<0)
    {
        abss=-abss;
    }
    if (n==1)
    {
        if (abss==1)
        {
            return 1;
        }
        if (abss==2)
        {
            return 2;
        }
    }
    if (abss==1)
    {
        return(han(n-1,a,6-a-b)+1+han(n-1,6-a-b,b));
    }
    if (abss==2)
    {
        return(han(n-1,a,b)*2+2+han(n-1,b,a));
    }
}

int main()
{
    int n,ans,x;
    scanf("%d",&x);
    for (int i=1;i<=x;i++)
    {
        scanf("%d",&n);
        if (n==1)
        {
            printf("2\n");
            continue;
        }
        ans=han(n-1,1,2)+2+han(n-1,2,3);
        printf("%d\n",ans);
    }
    return 0;
}
