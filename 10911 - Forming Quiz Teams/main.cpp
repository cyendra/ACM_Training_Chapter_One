#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const double OO=1e17;

struct STU{
    int x;
    int y;
}stu[32];

double a[32][32];
int n;
char s[111];
double f[1<<17];
bool v[1<<17];

int lowbit(int x)
{
    return x&(-x);
}

double dfs(int x)
{
    int i,j;
    double ret=OO;
    if (v[x]) return f[x];
    for (i=0;i<n;i++)
    {
        if (x&(1<<i)) break;
    }
    for (j=i+1;j<n;j++)
    {
        if (x&(1<<j))
        {
            ret=min( ret, dfs(x^(1<<i)^(1<<j))+a[i][j] );
        }
    }
    f[x]=ret;
    v[x]=true;
    return ret;
}

void DP()
{
    int i,j,x;
    for (i=0;i<(1<<n);i++) f[i]=OO;
    f[0]=0;
    for (x=1;x<(1<<n);x++)
    {
        for (i=0;i<n;i++)
        {
            if (x&(1<<i)) break;
        }
        for (j=i+1;j<n;j++)
        {
            if (x&(1<<j))
            {
                f[x]=min( f[x], f[x^(1<<i)^(1<<j)]+a[i][j] );
            }
        }
    }
    printf("%0.2lf\n",f[(1<<n)-1]);
}

int main()
{
    int cnt=1;
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        memset(f,0,sizeof(f));
        memset(v,0,sizeof(v));
        n*=2;
        for (int i=0;i<n;i++)
        {
            scanf("%s%d%d",s,&stu[i].x,&stu[i].y);
        }
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                a[i][j]=sqrt((stu[i].x-stu[j].x)*(stu[i].x-stu[j].x)+(stu[i].y-stu[j].y)*(stu[i].y-stu[j].y));
            }
        }
        printf("Case %d: ",cnt++);
        //DP();
        v[0]=true;
        double ans=dfs((1<<n)-1);
        printf("%0.2lf\n",ans);
    }
    return 0;
}

