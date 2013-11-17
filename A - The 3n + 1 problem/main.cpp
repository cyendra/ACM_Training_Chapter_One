#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=1111111;

int f[maxn];

int main()
{
    int x,y;
    int ans,ret;
    memset(f,0,sizeof(f));
    while (~scanf("%d%d",&x,&y))
    {
        ans=0;
        for (int i=min(x,y);i<=max(x,y);i++)
        {
            if (f[i]) ret=f[i];
            else
            {
                ret=1;
                int n=i;
                while (n!=1)
                {
                    if (n&1) n=3*n+1;
                    else n/=2;
                    ret++;
                }
                f[i]=ret;
            }
            if (ret>ans) ans=ret;
        }
        printf("%d %d %d\n",x,y,ans);
    }
    return 0;
}
