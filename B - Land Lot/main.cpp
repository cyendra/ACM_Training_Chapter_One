#include <iostream>
#include <cstring>

using namespace std;

int mp[60][60];
int s[60][60];
int n,m;
int a,b;
const int OO=1e9;

int main()
{
    memset(mp,0,sizeof(mp));
    memset(s,0,sizeof(s));
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+mp[i][j];

        }

    }
    cin>>a>>b;
    int ans=OO;
    int t;
    for (int i=a;i<=n;i++)
    {
        for (int j=b;j<=m;j++)
        {
            t=s[i][j]-s[i-a][j]-s[i][j-b]+s[i-a][j-b];
            if (t<ans) ans=t;
        }
    }
    for (int i=b;i<=n;i++)
    {
        for (int j=a;j<=m;j++)
        {
            t=s[i][j]-s[i-b][j]-s[i][j-a]+s[i-b][j-a];
            if (t<ans) ans=t;
        }
    }
    cout<<ans<<endl;
    return 0;
}
