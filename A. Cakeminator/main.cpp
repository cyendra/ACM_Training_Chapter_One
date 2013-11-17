#include <iostream>
#include <cstring>

using namespace std;

const int maxn=21;

char s[maxn][maxn];
bool v[maxn][maxn];
int r,c;

int main()
{
    memset(v,0,sizeof(v));
    cin>>r>>c;
    for (int i=1;i<=r;i++)
        cin>>(s[i]+1);
    for (int i=1;i<=r;i++)
    {
        bool flag=true;
        for (int k=1;k<=c;k++)
        {
            if (s[i][k]=='S')
            {
                flag=false;
                break;
            }
        }
        if (flag)
        {
            for (int k=1;k<=c;k++) v[i][k]=true;
        }
    }
    for (int j=1;j<=c;j++)
    {
        bool flag=true;
        for (int k=1;k<=r;k++)
        {
            if (s[k][j]=='S')
            {
                flag=false;
                break;
            }
        }
        if (flag)
        {
            for (int k=1;k<=r;k++) v[k][j]=true;
        }
    }
    int ans=0;
    for (int i=1;i<=r;i++)
    {
        for (int j=1;j<=c;j++)
        {
            if (v[i][j]) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
