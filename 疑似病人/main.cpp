#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int p[30000],rank[30000],f[30000];
    int x,y,n,m,t,px,py,k,sum,tmp;
    while (scanf("%d%d",&n,&m))
    {
        if ((n==0)and(m==0))
        {
            break;
        }
        for (int i=0;i<30000;i++)
        {
            p[i]=-1;
            rank[i]=1;
            f[i]=-1;
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d",&k);
            for (int j=1;j<=k;j++)
            {
                scanf("%d",&t);
                if (f[i]==-1)
                {
                    f[i]=t;
                }
                else
                {
                    px=f[i];
                    py=t;
                    while (p[px]!=-1)
                    {
                        px=p[px];
                    }
                    while (p[py]!=-1)
                    {
                        py=p[py];
                    }
                    if (rank[px]>rank[py])
                    {
                        p[py]=px;
                    }
                    else if (rank[px]<rank[py])
                    {
                        p[px]=py;
                    }
                    else
                    {
                        p[px]=py;
                        rank[py]+=rank[px];
                    }
                }

            }
        }
        t=0;
        while (p[t]!=-1)
        {
            t=p[t];
        }
        sum=1;
        for (int i=1;i<=n-1;i++)
        {
            tmp=i;
            while (p[tmp]!=-1)
            {
                tmp=p[tmp];
            }
            if (tmp==t)
            {
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
