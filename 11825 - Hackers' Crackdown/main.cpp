#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=18;
const int maxs=1<<18;

int f[maxs];
int p[maxn];
int cover[maxs];
int n;

int main()
{
    int cas=0;
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        for (int i=0;i<n;i++)
        {
            int m,x;
            scanf("%d",&m);
            p[i]=1<<i;
            while (m--)
            {
                scanf("%d",&x);
                p[i]|=(1<<x);
            }
        }
        for (int s=0;s<(1<<n);s++)
        {
            cover[s]=0;
            for (int i=0;i<n;i++)
            {
                if (s&(1<<i))
                {
                    cover[s]|=p[i];
                }
            }
        }
        f[0]=0;
        int ALL=(1<<n)-1;
        for (int s=1;s<(1<<n);s++)
        {
            f[s]=0;
            for (int s0=s;s0;s0=(s0-1)&s)
            {
                if (cover[s0]==ALL)
                {
                    f[s]=max(f[s],f[s^s0]+1);
                }
            }
        }
        printf("Case %d: %d\n",++cas,f[ALL]);
    }
    return 0;
}
