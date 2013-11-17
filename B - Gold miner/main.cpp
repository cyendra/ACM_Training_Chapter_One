#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn=522;
const int maxf=55555;
int n,T;
struct GOLD{
    int x;
    int y;
    int w;
    int v;
}gold[maxn];

struct DPDATA{
    int w;
    int v;
};

bool cmpgold(GOLD a,GOLD b)
{
    if(a.y*b.x==a.x*b.y)return a.x*a.x+a.y*a.y<b.x*b.x+b.y*b.y;
    return a.y*b.x<a.x*b.y;
}

int f[maxf];
vector<DPDATA>a[maxn];

int main()
{
    int cas;
    int kas=0;
    DPDATA tmp;
    while (~scanf("%d%d",&n,&T))
    {
        memset(f,0,sizeof(f));
        for (int i=0;i<maxn;i++) a[i].clear();
        for (int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&gold[i].x,&gold[i].y,&gold[i].w,&gold[i].v);
        }
        sort(gold,gold+n,cmpgold);
        cas=0;
        tmp.w=0;
        tmp.v=0;
        for (int i=0;i<n;i++)
        {
            if (i>0&&gold[i].y*gold[i-1].x==gold[i].x*gold[i-1].y)
            {
                tmp.w+=gold[i].w;
                tmp.v+=gold[i].v;
                a[cas].push_back(tmp);
            }
            else
            {
                tmp.w=gold[i].w;
                tmp.v=gold[i].v;
                cas++;
                a[cas].push_back(tmp);
            }
        }
        for (int i=1;i<=cas;i++)
        {
            for (int j=T;j>=0;j--)
            {
                for (int k=0;k<a[i].size();k++)
                {
                    if (j-a[i][k].w>=0&&f[j-a[i][k].w]+a[i][k].v>f[j])
                    {
                        f[j]=f[j-a[i][k].w]+a[i][k].v;
                    }
                }
            }
        }
        printf("Case %d: %d\n",++kas,f[T]);
    }
    return 0;
}
