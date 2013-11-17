#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1111;

int mat[maxn][maxn];
int n,m;

//返回矩形的最大面积，障碍物代号为c
int cat(int c)
{
    int h[maxn],l[maxn],r[maxn];
    int lo,ro;
    int ans=0;
    for (int j=1;j<=m;j++)
    {
        h[j]=0;
        l[j]=1;
        r[j]=m;
    }
    for (int i=1;i<=n;i++)
    {
        lo=0;ro=m+1;
        for (int j=1;j<=m;j++)
        {
            if (mat[i][j]==c){ h[j]=0;l[j]=1;lo=j; }
            else
            {
                h[j]++;
                l[j]=max(l[j],lo+1);
            }
        }
        for (int j=m;j>=1;j--)
        {
            if (mat[i][j]==c){ r[j]=m;ro=j; }
            else
            {
                r[j]=min(r[j],ro-1);
                ans=max(ans,(h[j]+(r[j]-l[j]+1))*2);
            }
        }
    }
    return ans;
}

char s[maxn][maxn];

int main()
{
    int T;
    int ans;
    int cnt=0;
    scanf("%d",&T);
    while (T--)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s[i]+1);
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (s[i][j]=='B') mat[i][j]=0;
                if (s[i][j]=='R') mat[i][j]=1;
            }
        }
        ans=max(ans,cat(1));
        ans=max(ans,cat(0));
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if ((i+j)%2==0)
                {
                    mat[i][j]^=1;
                }
            }
        }
        ans=max(ans,cat(1));
        ans=max(ans,cat(0));
        printf("Case #%d: %d\n",++cnt,ans);
    }
    return 0;
}
