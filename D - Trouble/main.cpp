#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int maxn=222;
LL a[5][maxn];
LL f[maxn*maxn];
LL g[maxn*maxn];
int n;
int n2;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        n2=n*n;
        for (int i=0;i<5;i++)
        {
            for (int j=0;j<n;j++)
            {
                scanf("%I64d",&a[i][j]);
            }
        }
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                f[i*n+j]=a[1][i]+a[2][j];
                g[i*n+j]=a[3][i]+a[4][j];
            }
        }
        sort(f,f+n2);
        sort(g,g+n2);
        bool ok=false;
        for (int i=0;i<n;i++)
        {
            int k=n2-1;
            for (int j=0;j<n2;j++)
            {
                //LL sum=a[0][i]+f[j];
                //int k=lower_bound(g,g+n*n,-sum)-g;
                //if (sum+g[k]==0) ok=true;
                while (k>0&&a[0][i]+f[j]+g[k]>0 ) k--;
                if (a[0][i]+f[j]+g[k]==0) ok=true;
                if (ok) break;
            }
            if (ok) break;
        }
        if (ok) puts("Yes");
        else puts("No");
    }
    return 0;
}

