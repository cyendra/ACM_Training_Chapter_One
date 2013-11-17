#include <iostream>
#include <cstring>

using namespace std;

int n,m;

int map[111];
int stk[111];
int sum[111];
int f[111][111][111];
int cnt;

int getsum(int x)
{
    int ret=0;
    while (x!=0)
    {
        if (x&1) ret++;
        x>>=1;
    }
    return ret;
}

bool ok(int x)
{
    if (x&(x<<1)) return false;
    if (x&(x<<2)) return false;
    return true;
}

void initstk(int m)
{
    for (int i=0;i<(1<<m);i++)
    {
        if (ok(i))
        {
            stk[cnt]=i;
            sum[cnt]=getsum(i);
            cnt++;
        }
    }
}

int main()
{
    while (cin>>n>>m)
    {
        char c;
        memset(map,0,sizeof(map));
        memset(stk,0,sizeof(stk));
        memset(f,-1,sizeof(f));
        cnt=0;
        initstk(m);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                cin>>c;
                if (c=='H') map[i]|=1<<j;
            }
        }
        for (int i=0;i<cnt;i++)
        {
            if ( !(stk[i]&map[0]) )
            {
                f[0][0][i]=sum[i];
            }
        }
        for (int r=1;r<n;r++)
        {
            for (int i=0;i<cnt;i++)
            {
                if (stk[i]&map[r]) continue;
                for (int j=0;j<cnt;j++)
                {
                    if (stk[i]&stk[j]) continue;
                    for (int k=0;k<cnt;k++)
                    {
                        if (stk[i]&stk[k]) continue;
                        if (f[r-1][k][j]==-1) continue;
                        f[r][j][i]=max(f[r][j][i],f[r-1][k][j]+sum[i]);
                    }
                }
            }
        }
        int ans=0;
        for (int i=0;i<cnt;i++)
        {
            for (int j=0;j<cnt;j++)
            {
                ans=max(ans,f[n-1][i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
