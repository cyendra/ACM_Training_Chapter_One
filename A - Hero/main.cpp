#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn=1<<22;
int n;
int dps[22],hp[22];
int sum[maxn];
int f[maxn];

int main()
{
    //f[S]=min(f[S+k]+sum[S+k]*hp[k]);
    while (~scanf("%d",&n))
    {
        memset(f,-1,sizeof(f));
        memset(sum,0,sizeof(sum));

        //init()
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&dps[i],&hp[i]);
        }
        //prepare()
        for (int i=0;i<(1<<n);i++)
        {
            for (int j=0;j<n;j++)
            {
                if (i&(1<<j))
                {
                    sum[i]+=dps[j];
                }
            }
        }
        //dp
        f[(1<<n)-1]=0;
        for (int s=(1<<n)-1;s>=0;s--)
        {
            for (int k=0;k<n;k++)
            {
                if (!(s&(1<<k)))
                {
                    if (f[s]==-1||f[s+(1<<k)]+sum[s+(1<<k)]*hp[k]<f[s])
                    {
                        f[s]=f[s+(1<<k)]+sum[s+(1<<k)]*hp[k];
                    }
                }
            }
        }
        printf("%d\n",f[0]);
    }
    return 0;
}
