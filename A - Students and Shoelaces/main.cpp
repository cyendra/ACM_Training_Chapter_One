#include <iostream>

using namespace std;

int a[111][111];
int n,m;
int ans;
int lf;
int cnt[111]={0};

int main()
{
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
        cnt[x]++;
        cnt[y]++;
    }
    lf=n;
    bool ok=true;
    while (lf>1&&ok)
    {
        ok=false;
        int lie=0;
        for (int i=1;i<=n;i++)
        {
            if (cnt[i]==1)
            {
                lf--;
                ok=true;
                for (int j=1;j<=n;j++)
                {
                    if (a[i][j])
                    {
                        a[j][i]=a[i][j]=0;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++) cnt[i]=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (a[i][j])
                {
                    cnt[i]++;
                }
            }
        }
        if (ok) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
