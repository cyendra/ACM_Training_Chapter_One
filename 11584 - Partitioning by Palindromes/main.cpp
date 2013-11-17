#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int OO=1e9;
int n;
char s[1111];
int f[1111];
bool rev[1111][1111];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(rev,0,sizeof(rev));
        scanf("%s",s+1);
        n=strlen(s+1);
        for (int i=1;i<=n;i++)
        {
            rev[i][i]=true;
            if (s[i]==s[i+1]&&i+1<=n)
            {
                rev[i][i+1]=true;
            }
        }
        for (int k=2;k<=n;k++)
        {
            for (int i=1;i+k<=n;i++)
            {
                if (s[i]==s[i+k]&&rev[i+1][i+k-1])
                {
                    rev[i][i+k]=true;
                }
            }
        }
        for (int i=1;i<=n;i++) f[i]=OO;
        f[0]=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=i;j++)
            {
                if (rev[j][i])
                {
                    f[i]=min(f[i],f[j-1]+1);
                }
            }
        }
        int ans=f[n];
        printf("%d\n",ans);
    }
    return 0;
}

/*
int dfs(int l,int r)
{
    int ret=OO;
    if (v[l][r]) return f[l][r];
    if (rev[l][r]) ret=1;
    for (int i=l;i<r;i++)
    {
        ret=min( ret, dfs(l,i)+dfs(i+1,r) );
    }
    v[l][r]=true;
    f[l][r]=ret;
    return ret;
}

*/
