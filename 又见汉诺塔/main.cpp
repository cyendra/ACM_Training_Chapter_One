#include <iostream>
#include <cstdio>
using namespace std;

int c=0;
int abs;
int han(int n,int a,int b)
{
    abs=a-b;
    if (abs<0)
    {
        abs=-abs;
    }
    if (n==1)
    {
        if (abs==1)
        {
            return 1;
        }
        if (abs==2)
        {
            return 2;
        }
    }
    if (abs==1)
    {
        return(han(n-1,a,6-a-b)+1+han(n-1,6-a-b,b));
    }
    if (abs==2)
    {
        return(han(n-1,a,b)*2+2+han(n-1,b,a));
    }
}

int main()
{
    int n,ans;
    scanf("%d",&n);
    ans=han(n-1,1,2)+2+han(n-1,2,3);
    printf("%d",ans);
    return 0;
}
