/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    int a[51],b[51],f[51],s[27];
    scanf("%d",&n);
    for (int loop=1;loop<=n;loop++)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(f,0,sizeof(f));
        f[0]=1;
        for (int i=1;i<=26;i++)
        {
            scanf("%d",&s[i]);
            if (s[i]==0) continue;
            memset(a,0,sizeof(a));
            for (int j=0;j<=50;j++)
            {
                if (s[i]+j<=50) a[s[i]+j]=f[j];
            }
            for (int j=0;j<=50;j++)
            {
                f[j]+=a[j];
            }

        }
        int ans=0;
        for (int i=1;i<=50;i++)
        {
            ans+=f[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i, j, k, t, x;
    int n[2][51];

    scanf("%d", &t);
    while (t--)
    {
        memset(n[0], 0, sizeof(n[0]));
        n[0][0] = 1;
        for (i = 1; i < 27; i++)
        {
            scanf("%d", &x);
            if (!x)
            {
                for (j = 0; j < 51; j++)
                    n[i % 2][j] = n[!(i%2)][j];
                continue;
            }
            memset(n[i % 2], 0, sizeof(n[0]));
            for (j = 0; j < 51 && j <= x * i; j += i)
            {
                for (k = 0; k + j < 51 ; k++)
                {
                    if (n[!(i%2)][k])
                        n[i % 2][k + j] += n[!(i%2)][k];
                }
            }
        }
        for (x = 0, i = 1; i < 51; i++)
            x += n[0][i];
        printf("%d\n", x);
    }

    return 0;
}

