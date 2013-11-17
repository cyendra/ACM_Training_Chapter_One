#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int OO=1e9;

int f[111][111];
int a[111];
int n;
int l;

int dfs(int l,int r)
{
    int ret=OO;
    if (f[l][r]!=-1) return f[l][r];
    if (l==r) return f[l][r]=0;
    if (l+1==r) return f[l][r]=0;
    for (int k=l+1;k<=r-1;k++) ret=min( ret, dfs(l,k)+dfs(k,r)+a[r]-a[l] );
    return f[l][r]=ret;
}

int main()
{
    while (~scanf("%d",&l))
    {
        if (l==0) break;
        memset(a,0,sizeof(a));
        memset(f,-1,sizeof(f));
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        a[0]=0;
        a[n+1]=l;
        int ans=dfs(0,n+1);
        printf("The minimum cutting is %d.\n",ans);
    }
    return 0;
}
