#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int c1[8100],c2[8100];
    int num[3],m,ans;
    int v[3]={1,2,5};
    while ( scanf("%d%d%d",&num[0],&num[1],&num[2])!=EOF )
    {
        if ( num[0]==0 && num[1]==0 && num[2]==0 )
        {
            break;
        }
        m=num[0]+num[1]*2+num[2]*5;
        for (int i=0;i<=m;i++)
        {
            c1[i]=0;
            c2[i]=0;
        }
        c1[0]=1;
        for (int i=0;i<=2;i++)
        {
            for (int j=0;j<=m;j++)
            {
                for (int k=0,loop=0;loop<=num[i];loop++)
                {
                    if (k+j<=m)
                    {
                        c2[k+j]+=c1[j];
                    }
                    k+=v[i];
                }
            }
            for (int j=0;j<=m;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        ans=-1;
        for (int i=0;i<=m;i++)
        {
            if ( c1[i]==0 )
            {
                ans=i;
                break;
            }
        }
        if (ans==-1)
        {
            printf("%d\n",m+1);
        }
        else
        {
            printf("%d\n",ans);
        }

    }
    return 0;
}
