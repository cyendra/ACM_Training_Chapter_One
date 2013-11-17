#include <iostream>
#include <cstdio>

using namespace std;
int f[30]={0};
int fff(int n)
{
    if (f[n]!=0)
    {
        return (f[n]);
    }
    else if (n==1)
    {
        f[n]=1;
        return (1);
    }
    else
    {
        f[n]=n*(fff(n-1)+1);
        return ( f[n] );
    }

}

int main()
{
    bool a[30];

    int n,m,t,j,fn,p;
    int ans[30]={0};
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<=n;i++)
        {
            ans[i]=0;
        }
        for (int i=1;i<=n;i++)
        {
            a[i]=true;
        }

        for (int i=n;i>=1;i--)
        if (m!=0)
        {
            t=(m-1)/(fff(i-1)+1)+1;
            j=0;
            p=0;
            for (j=1;j<=n;j++)
            {
                if (a[j]==true)
                {
                    p++;
                    if (p==t){break;}
                }

            }
            ans[i]=j;
            a[j]=false;
            m=m-(t-1)*(fff(i-1)+1)-1;

        }
        for (int i=n;ans[i]!=0;i--)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }

    return 0;
}
