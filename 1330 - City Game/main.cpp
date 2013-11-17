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
                ans=max(ans,h[j]*(r[j]-l[j]+1));
            }
        }
    }
    return ans;
}

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if (c=='F') mat[i][j]=0;
                if (c=='R') mat[i][j]=1;
            }
        }
        cout<<cat(1)*3<<endl;
    }
    return 0;
}
