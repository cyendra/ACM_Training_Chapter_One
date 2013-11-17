#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int OO=1e9;

int f[1111][1111];
char s[1111];

int dfs(int l,int r)
{
    int ret;
    if (r-l<1) return 0;
    if (f[l][r]!=-1) return f[l][r];
    if (s[l]==s[r])
    {
        ret=dfs(l+1,r-1);
    }
    else
    {
        ret=min( dfs(l+1,r), min( dfs(l,r-1), dfs(l+1,r-1) ) )+1;
    }
    f[l][r]=ret;
    return ret;
}

int main()
{
    int T;

    scanf("%d",&T);
    for (int cnt=1;cnt<=T;cnt++)
    {
        memset(f,-1,sizeof(f));
        scanf("%s",s+1);
        printf("Case %d: %d\n",cnt,dfs(1,strlen(s+1)));
    }
    return 0;
}
