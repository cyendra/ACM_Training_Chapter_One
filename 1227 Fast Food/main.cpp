#include <iostream>
#include <cstring>
#define MAX 9999999

using namespace std;

//---------------------------------------
int n,k,tmp,loop,ans;
double mid;
int d[210]={0};
int f[40][210];
int w[210][210];
int min(int a,int b);

int min(int a,int b)
{
    if (a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

//---------------------------------------
int main()
{
    loop=0;
    while ( cin >> n >> k )
    {
        loop++;
        if (n==0 && k==0)
        {
            break;
        }

        for (int i=0;i<n;i++)
        {
            cin >> d[i];
        }
        //输入完毕

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                w[i][j]=MAX;
            }
        }

        for (int i=0;i<n;i++)
        {
            for (int j=i;j<n;j++)
            {
                w[i][j]=0;
                for (int t=i;t<=j;t++)
                {
                    w[i][j]+=min( d[j]-d[t] , d[t]-d[i] );
                }
            }
        }
        //预处理完毕
        for (int i=0;i<k;i++)
        {
            for (int j=0;j<n;j++)
            {
                f[i][j]=MAX;
                if (i==j)
                {
                    f[i][j]=0;
                }
            }
        }

        for (int j=0;j<n;j++)
        {
            f[0][j]=0;
            for (int t=0;t<j;t++)
            {
                f[0][j]+=d[j]-d[t];
            }
        }

        for (int i=1;i<k;i++)
        {
            for (int j=i;j<n;j++)
            {
                for (int t=i-1;t<j;t++)
                {
                    f[i][j]=min( f[i][j] , f[i-1][t]+w[t][j] );
                }
                //printf("f[%d][%d]=%d ",i,j,f[i][j]);
            }
            //printf("\n");
        }

        tmp=0;
        ans=MAX;
        for (int i=k-1;i<n;i++)
        {
            tmp=0;
            for (int j=i;j<n;j++)
            {
                tmp+=d[j]-d[i];
            }
            ans=min( ans , f[k-1][i]+tmp );
        }

        cout << "Chain " << loop << endl;
        cout << "Total distance sum = " << ans << endl;
        cout << endl;
    }
    return 0;
}
