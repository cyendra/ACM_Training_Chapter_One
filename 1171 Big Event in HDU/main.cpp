#include <iostream>
#include <cstdio>

using namespace std;

int v[51];
int m[51];
int c1[510000];
int c2[510000];
int n,k;
int mxn;
int value,num,ansa,ansb;

int main()
{
    while (scanf("%d",&n)!=EOF && n>=0)
    {
        mxn=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&v[i],&m[i]);
            mxn+=v[i]*m[i];
        }
        for (int i=0;i<=mxn;i++)
        {
            c1[i]=0;
            c2[i]=0;
        }
        c1[0]=1;
        for (int i=0;i<n;i++)
        {
            k=v[i];
            for (int loop=0;loop<m[i];loop++)
            {
                for (int j=0;j<=mxn;j++)
                {
                    if (j+k<=mxn) c2[j+k]+=c1[j];
                }
                for (int j=0;j<=mxn;j++)
                {
                    c1[j]+=c2[j];
                    c2[j]=0;
                }
            }
        }

        for (int i=0;i<=mxn;i++)
        {

            if ( c1[i]!=0 && i>=mxn-i )
            {
                ansa=i;
                ansb=mxn-i;
                break;
            }

            //if (c1[i]!=0)
            //{
            //    printf("i=%d c1[i]=%d \n",i,c1[i]);
            //}
        }
        if (n==0)
        {
            printf("0 0\n");
        }
        else
        {
            printf("%d %d\n",ansa,ansb);
        }
    }
    return 0;
}
