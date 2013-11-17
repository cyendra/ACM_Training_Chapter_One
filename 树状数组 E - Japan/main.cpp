#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,k;
long long tree[1111111];

struct dat{
    int x;
    int y;
}road[1111111];

//long long ans[11111111];
long long sum;
bool cmp(dat a,dat b)
{
    if (a.x!=b.x) return a.x>b.x;
    return a.y>b.y;
}

int lowbit(int i)
{
    return i&(-i);
}

void updata(int i,int d)
{
    while (i<=m)
    {
        tree[i]+=d;
        i+=lowbit(i);
    }
}

long long query(int i)
{
    long long ret=0;
    while (i>0)
    {
        ret+=tree[i];
        i-=lowbit(i);
    }
    return ret;
}

int main()
{
    int T,a,b;
    scanf("%d",&T);
    for (int lp=1;lp<=T;lp++)
    {
        sum=0;
        memset(tree,0,sizeof(tree));
        scanf("%d%d%d",&n,&m,&k);
        for (int i=1;i<=k;i++)
        {
            scanf("%d%d",&a,&b);
            road[i].x=a;
            road[i].y=b+1;
        }
        m++;
        sort(road+1,road+k+1,cmp);
        for (int i=1;i<=k;i++)
        {
            sum+=query(road[i].y-1);
            updata(road[i].y,1);
        }
        printf("Test case %d: %I64d\n",lp,sum);
    }
    return 0;
}
