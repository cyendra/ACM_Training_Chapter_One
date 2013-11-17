#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int OO=1e9;

int f[111][1111][33];
int a[33][33];
char s[1111];
bool v[111][1111][33];
int k;

int dfs(int dk,int di,int dj)
{
    int ret=-OO;
    if (di>1&&dk<0) return -OO;
    if (di==1)
    {
        if (s[di]-'a'==dj)
        {
            if (dk==0) return 0;
            else return -OO;
        }
        else
        {
            if (dk==1) return 0;
            else return -OO;
        }
    }
    if (v[dk][di][dj]) return f[dk][di][dj];
    if (dj==s[di]-'a')
    {
        for (int t=0; t<26; t++)
        {
            ret=max( ret, dfs(dk,di-1,t)+a[t][dj] );
        }
    }
    else
    {
        for (int t=0; t<26; t++)
        {
            ret=max( ret, dfs(dk-1,di-1,t)+a[t][dj] );
        }
    }
    f[dk][di][dj]=ret;
    v[dk][di][dj]=true;
    return ret;
}

int main()
{
    int n;
    char x,y;
    int c;
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    memset(v,0,sizeof(v));
    cin>>(s+1)>>k;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>x>>y>>c;
        a[x-'a'][y-'a']=c;
    }
    int len=strlen(s+1);
    int ans=-OO;
    for (int l=0; l<=k; l++)
        for (int j=0; j<26; j++)
        {
            ans=max( ans, dfs(l,len,j) );
        }
    cout<<ans<<endl;

    return 0;
}

/*

    for (int i=0;i<=len;i++)
    {
        for (int j=0;j<26;j++)
        {
            for (int l=0;l<=k;l++)
            {
                f[l][i][j]=-OO;
            }
        }
    }

    for (int i=0;i<26;i++)
    {
        if (s[1]-'a'==i)
        {
            f[0][1][i]=0;
        }
        else
        {
            f[1][1][i]=0;
        }
    }

    for (int i=2; i<=len; i++)
    {
        for (int j=0; j<26; j++)
        {
            if (j==s[i]-'a')
            {
                for (int l=0; l<=k; l++)
                    for (int t=0; t<26; t++)
                    {
                        f[l][i][j]=max( f[l][i][j], f[l][i-1][t]+a[t][j] );
                    }

            }
            else
            {
                for (int l=1; l<=k; l++)
                    for (int t=0; t<26; t++)
                    {
                        f[l][i][j]=max( f[l][i][j], f[l-1][i-1][t]+a[t][j] );
                    }
            }
        }
    }

    for (int l=0; l<=k; l++)
    {
        for (int j=0; j<26; j++)
        {
            if (f[l][len][j]>ans) ans=f[l][len][j];
        }
    }
    cout<<ans<<endl;


*/
