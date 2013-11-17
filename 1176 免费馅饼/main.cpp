#include<iostream>
#include<algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int a[100001][12];
int f[100001][12];
int main()
{
    int n,x,t,maxt,tmp;
    while ( scanf("%d",&n)!=EOF )
    {
        if (n==0)
        {
            break;
        }
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        maxt=0;
        for (int i=0; i<n; i++)
        {
            scanf("%d%d",&x,&t);
            a[t][x]++;
            maxt=max(maxt,t) ;
        }
        f[1][5]=a[1][5];
        f[1][4]=a[1][4];
        f[1][6]=a[1][6];
        for (int i=2; i<=maxt; i++)
        {
            for (int k=0; k<=10; k++)
            {
                f[i][k]=f[i-1][k];
                if (k-1>=0)
                {
                    f[i][k]=max(f[i][k],f[i-1][k-1]);
                }
                if (k+1<=10)
                {
                    f[i][k]=max(f[i][k],f[i-1][k+1]);
                }
                f[i][k]+=a[i][k];
            }
        }
        tmp=0;
        for (int k=0; k<=10; k++)
        {
            if (f[maxt][k]>tmp)
            {
                tmp=f[maxt][k];
            }
        }
        printf("%d\n",tmp);
    }
    return 0;
}
/*
#include<iostream>
#include<algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int a[100001][12];
int f[100001][12];
int main()
{
    int n;
    while(scanf("%d", &n) != EOF && n)
    {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        int x, T, i, j, maxT = 0, ans = 0;
        while(n--)
        {
            scanf("%d%d", &x, &T);
            ++a[T][x];
            maxT = max(maxT, T);
        }
        f[1][4] = a[1][4];
        f[1][5] = a[1][5];
        f[1][6] = a[1][6];
        for(i = 2; i <= maxT; ++i)
        {
            for(j = 0; j < 11; ++j)
            {
                f[i][j] = f[i - 1][j];
                if(j > 0) f[i][j] = max(f[i][j], f[i - 1][j - 1]);
                if(j < 10) f[i][j] = max(f[i][j], f[i - 1][j + 1]);
                f[i][j] += a[i][j];
            }
        }
        for(i = 0; i < 11; ++i) ans = max(ans, f[maxT][i]);
        printf("%d\n", ans);
    }
    return 0;
}
*/
