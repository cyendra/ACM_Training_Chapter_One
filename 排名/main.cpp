#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct STU{
    char name[110];
    int v;
}a[1111];

int ct[222];

int n,m,g;
int t;

bool cmp(STU a,STU b)
{
    if (a.v==b.v)
    {
        return (strcmp(a.name,b.name)<0);
    }
    return a.v>b.v;
}


int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) break;
        scanf("%d%d",&m,&g);
        memset(a,0,sizeof(a));
        memset(ct,0,sizeof(ct));
        for (int i=1;i<=m;i++)
        {
            scanf("%d",&ct[i]);
        }
        int ans=0;
        for (int i=0;i<n;i++)
        {
            scanf("%s%d",a[i].name,&t);
            for (int j=1;j<=t;j++)
            {
                int tmp;
                scanf("%d",&tmp);
                a[i].v+=ct[tmp];
            }
            if (a[i].v>=g) ans++;
        }
        sort(a,a+n,cmp);
        printf("%d\n",ans);
        for (int i=0;i<n;i++)
        {
            if (a[i].v>=g)
            {
                printf("%s %d\n",a[i].name,a[i].v);
            }
        }
    }
    return 0;
}
