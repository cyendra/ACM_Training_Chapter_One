#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef struct
{
    int x;
    int y;
    int v;
} TUR;
TUR a[101];
int f[101][101];


int main()
{

    int m,n,k,tmp;
    while (cin>>m>>n)
    {
        memset(f,0,sizeof(0));
        for (int i=1; i<=n; i++)
        {
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
        }
        scanf("%d",&k);
        //---------------------------------------------------
        for (int i=1; i<=m; i++)
        {
            for (int j=1; j<=k; j++)
            {
                /*
                tmp=0;
                for (int p=1;p<=n;p++)
                {
                    if (a[p].y==i)
                    {
                        tmp+=a[p].v;
                    }
                }
                f[i][j]=f[i-1][j]+tmp;
                */

                for (int t=1; t<=i-j+1; t++)
                {
                    tmp=0;
                    for (int p=1; p<=n; p++)
                    {
                        if ((a[p].x>=i-t+1)and(a[p].y<=i))
                        {
                            tmp+=a[p].v;
                        }
                    }
                    if (f[i-t][j-1] + tmp >f[i][j])
                    {
                        f[i][j]=f[i-t][j-1]+tmp;
                    }
                }
            }
        }
        printf("%d\n",f[m][k]);
    }

    //---------------------------------------------------
    return 0;
}
