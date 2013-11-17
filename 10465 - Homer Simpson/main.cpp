#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n,m,t;
int f[11111];

int main()
{
    while (~scanf("%d%d%d",&n,&m,&t))
    {
        memset(f,-1,sizeof(f));
        f[0]=0;
        for (int i=0;i<=t-n;i++)
        {
            if (f[i]>=0)
            {
                f[i+n]=max( f[i+n],f[i]+1 );
            }
        }
        for (int i=0;i<=t-m;i++)
        {
            if (f[i]>=0)
            {
                f[i+m]=max( f[i+m],f[i]+1 );
            }
        }
        if (f[t]!=-1)
        {
            printf("%d\n",f[t]);
        }
        else
        {
            int ans=0;
            int tmp=0;
            for (int i=t;i>=0;i--)
            {
                if (f[i]!=-1)
                {
                    ans=f[i];
                    tmp=i;
                    break;
                }
            }
            printf("%d %d\n",ans,t-tmp);
        }
    }
    return 0;
}
