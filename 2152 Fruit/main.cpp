#include <iostream>
#include <cstdio>

using namespace std;

int c1[100000],c2[100000];
int a[110],b[110];
int n,m,mxn,ans;

int main()
{
    while ( scanf("%d%d",&n,&m)!=EOF )
    {
        mxn=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            mxn+=b[i];
        }
        for (int i=0;i<=m;i++)
        {
            c1[i]=0;
            c2[i]=0;
        }
        for (int i=a[0];i<=b[0];i++)
        {
            c1[i]=1;
        }
        for (int i=1;i<n;i++)
        {
            //for (int j=0;j<=mxn;j++)
            for (int j=a[i];j<=b[i];j++)
            {
                //c2[j]+=c1[j];
                //for (int k=a[i];k<=b[i];k++)
                for (int k=0;k+j<=m;k++)
                {
                    c2[j+k]+=c1[k];
                }
            }
            for (int j=0;j<=m;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        printf("%d\n",c1[m]);
    }
    return 0;
}
