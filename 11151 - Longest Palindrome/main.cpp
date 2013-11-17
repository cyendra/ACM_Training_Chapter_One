#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[1111];
int f[1111][1111];
int n;

int dfs(int l,int r)
{
    if (f[l][r]!=-1) return f[l][r];
    if (r-l<1) return 0;
    int ret=0;
    if (s[l]==s[r])
    {
        ret=dfs(l+1,r-1);
    }
    else
    {
        ret=min( dfs(l+1,r), dfs(l,r-1) )+1;
    }
    f[l][r]=ret;
    return ret;
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while (T--)
    {
        memset(f,-1,sizeof(f));
        //scanf("%s",s+1);
        gets(s+1);
        n=strlen(s+1);
        int ans=dfs(1,n);
        printf("%d\n",n-ans);
    }
    return 0;
}
