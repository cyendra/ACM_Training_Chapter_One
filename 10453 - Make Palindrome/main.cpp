#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[1111];
int f[1111][1111];
int q[1111][1111];
int n;

int dfs(int l,int r)
{
    if (r-l<1)
    {
        return 0;
    }
    if (f[l][r]!=-1)
    {
        return f[l][r];
    }
    int ret=0;
    if (s[l]==s[r])
    {
        ret=dfs(l+1,r-1);
        q[l][r]=0;
    }
    else
    {
        ret=dfs(l+1,r)+1;
        q[l][r]=1;
        if (dfs(l,r-1)+1<ret)
        {
            ret=dfs(l,r-1)+1;
            q[l][r]=-1;
        }
    }
    f[l][r]=ret;
    return ret;
}

int main()
{
    while (cin>>(s+1))
    {
        string str1,str2,str;
        memset(f,-1,sizeof(f));
        memset(q,0,sizeof(q));
        n=strlen(s+1);
        int ans=dfs(1,n);
        int x=1,y=n;
        while (y-x>=0)
        {
            if (q[x][y]==0)
            {
                if (x==y)
                {
                    str1+=s[x];
                    x++;
                    y--;
                }
                else
                {
                    str1+=s[x];
                    str2+=s[y];
                    x++;
                    y--;
                }
            }
            else if (q[x][y]==1)
            {
                str1+=s[x];
                str2+=s[x];
                x++;
            }
            else if (q[x][y]==-1)
            {
                str1+=s[y];
                str2+=s[y];
                y--;
            }
        }
        for (int i=str2.length()-1; i>=0; i--)
        {
            str1+=str2[i];
        }
        cout<<ans<<" "<<str1<<endl;
    }
    return 0;
}
