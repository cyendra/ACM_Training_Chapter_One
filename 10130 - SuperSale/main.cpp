#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int f[33333];
int w[1111];
int v[1111];
int n;
int m;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(f,0,sizeof(f));
        memset(w,0,sizeof(w));
        memset(v,0,sizeof(v));
        m=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&v[i],&w[i]);
            m+=w[i];
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=m;j>=w[i];j--)
            {
                f[j]=max(f[j],f[j-w[i]]+v[i]);
            }
        }
        int G,MV;
        int ans=0;
        scanf("%d",&G);
        while (G--)
        {
            scanf("%d",&MV);
            ans+=f[MV];
        }
        printf("%d\n",ans);
    }
    return 0;
}
