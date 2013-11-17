#include <iostream>
#include <cstdio>
using namespace std;

int n,k;
int c1[35000],c2[35000];
int w[35000];
int mxn,ans;
int v[35000];
int mix;
int mid=15000;

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        mxn=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&w[i]);
            mxn+=w[i];
        }
        mix=-mxn;
        for (int i=mix;i<=mxn;i++)
        {
            c1[mid+i]=0;
            c2[mid+i]=0;
        }
        c1[mid+0]=1;
        for (int i=0;i<n;i++)
        {
            for (int j=mix;j<=mxn;j++)
            {
                k=w[i];
                if (j+k<=mxn)
                {
                    c2[mid+j+k]+=c1[mid+j];
                }
                if (j-k>=mix)
                {
                    c2[mid+j-k]+=c1[mid+j];
                }
            }
            for (int j=mix;j<=mxn;j++)
            {
                c1[mid+j]+=c2[mid+j];
                c2[mid+j]=0;
            }
        }
        ans=0;
        for (int i=0;i<=mxn;i++)
        {
            if (c1[mid+i]==0)
            {
                v[ans]=i;
                ans++;
            }
        }
        if (ans==0)
        {
            printf("%d\n",ans);
        }
        else
        {
            printf("%d\n",ans);
            printf("%d",v[0]);
            for (int i=1;i<ans;i++)
            {
                printf(" %d",v[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
