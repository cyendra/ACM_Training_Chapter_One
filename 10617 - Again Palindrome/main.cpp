#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
char s[111];
long long f[111][111];
int n;

long long dfs(int l,int r)
{
    if (f[l][r]!=-1) return f[l][r];
    if (r-l<0) return 0;
    if (s[l]==s[r])
    {
        f[l][r]=dfs(l+1,r)+dfs(l,r-1)+1;
    }
    else
    {
        f[l][r]=dfs(l+1,r)+dfs(l,r-1)-dfs(l+1,r-1);
    }
    return f[l][r];
}

int main()
{
    cin>>T;
    while (T--)
    {
        memset(f,-1,sizeof(f));
        cin>>(s+1);
        n=strlen(s+1);
        long long ans=dfs(1,n);
        cout<<ans<<endl;
    }
    return 0;
}
