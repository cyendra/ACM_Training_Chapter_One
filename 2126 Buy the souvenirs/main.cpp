#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int t,n,m,sum,maxbag;
    int f[32][502][32];
    int a[32];
    scanf("%d",&t);
    for (int loop=0;loop<t;loop++)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }

        sum=0;
        maxbag=0;
        /*
        for (int i=1;i<=n;i++)
        {
            if (sum+a[i]>m)
            {
                break;
            }
            else
            {
                sum+=a[i];
                maxbag++;
            }
        }
        if (maxbag==0)
        {
            printf("Sorry, you can't buy anything.\n");
            continue;
        }
        */
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                for (int k=1;k<=i;k++)
                {
                    if (j-a[i]>=0)
                    {
                        if (k==1)
                        {
                            f[i][j][k]=f[i-1][j][k]+1;
                        }
                        else
                        {
                            f[i][j][k]+=f[i-1][j-a[i]][k-1]+f[i-1][j][k];
                        }
                    }
                    else
                    {
                        f[i][j][k]+=f[i-1][j][k];
                    }
                }
            }
        }
        for (int i=1;i<=n;++i)
            if (f[n][m][i]!=0)
                maxbag=i;
        if (maxbag!=0)
        {
            printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n",f[n][m][maxbag],maxbag);
        }
        else
        {
            printf("Sorry, you can't buy anything.\n");
        }
        //if (loop!=t-1)
        //{
        //    printf("\n");
        //}
    }
    return 0;
}
