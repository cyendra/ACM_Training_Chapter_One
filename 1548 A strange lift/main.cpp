#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 9999999
using namespace std;

int a[210][210];
int f[210];
bool v[210];

int main()
{
    int N,A,B,lift,minf,minj;
    while (scanf("%d",&N)!=EOF && N!=0 )
    {
        scanf("%d%d",&A,&B);
        //--------------------------
        for (int i=0;i<=N;i++)
        {
            for (int j=0;j<=N;j++)
            {
                a[i][j]=MAX;
            }
        }
        for (int i=0;i<=N;i++)
        {
            f[i]=MAX;
            v[i]=false;
        }
        //--------------------------
        for (int i=1;i<=N;i++)
        {
            scanf("%d",&lift);
            if (i-lift>=1)
            {
                a[i][i-lift]=1;
            }
            if (i+lift<=N)
            {
                a[i][i+lift]=1;
            }
        }
        //--------------------------
        //
        /*
        for (int i=1;i<=N;i++)
        {
            for (int j=1;j<=N;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        */
        f[A]=0;
        v[A]=true;
        for (int loop=1;loop<N && v[B]!=true ;loop++)
        {
            for (int i=1;i<=N;i++)
            {
                if (v[i]==true)
                {
                    for (int j=1;j<=N;j++)
                    {
                        if ( v[j]==false && f[i]+a[i][j]<f[j] )
                        {
                            f[j]=f[i]+a[i][j];
                        }
                    }
                }
            }
            minf=MAX;
            minj=0;
            for (int i=1;i<=N;i++)
            {
                if (v[i]==false && f[i]<minf )
                {
                    minf=f[i];
                    minj=i;
                }
            }
            v[minj]=true;
        }
        if (v[B]==true)
        {
            printf("%d\n",f[B]);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
