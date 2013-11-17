#include <iostream>
#include <cstdio>

using namespace std;

int f[40]={0};
int han(int n)
{
    if (f[n]!=0)
    {
        return f[n];
    }
    else if(n==1)
    {
        f[n]=2;
        return f[n];
    }
    else
    {
        f[n]=han(n-1)+1+han(n-1)+han(n-1)+1;
        return f[n];
    }
}

int main()
{
    int n,ans;
    scanf("%d",&n);
    ans=han(n);
    printf("%d",ans);
    return 0;
}
