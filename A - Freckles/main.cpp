#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int maxn=222;
const int maxm=11111;
const double INF=1e300;

double a[maxn][maxn];
double x[maxn],y[maxn];
double dist[maxn];

double prim(double a[maxn][maxn],double d[maxn],int n,int s)
{
    bool v[maxn]={0};
    double ans=0,m;
    int t;
    for (int i=0;i<n;i++) d[i]=INF;
    d[s]=0;
    for (int loop=1; loop<=n; loop++){
        m=INF;
        t=n;
        for (int i=0; i<n; i++)
            if (!v[i]&&d[i]<m){
                m=d[i];
                t=i;
            }
        if (t==n) break;
        v[t]=true;
        ans+=m;
        for (int i=0; i<n; i++)
            if (!v[i]&&t!=i&&a[t][i]<d[i]) d[i]=a[t][i];
    }
    return ans;
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--)
    {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for (int i=0; i<n; i++)
        {
            scanf("%lf%lf",&x[i],&y[i]);
        }
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                a[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            }
        }
        printf("%0.2f\n",prim(a,dist,n,0));
        if (T) puts("");
    }
    return 0;
}
