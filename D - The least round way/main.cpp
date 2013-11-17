#include <iostream>
//#include <algorithm>
#include <cstring>
#define MAX 1111
using namespace std;

int n,t,ans,x,y;
int a[MAX][MAX];
int f[MAX][MAX];
int two[MAX][MAX];
int five[MAX][MAX];
char prv[MAX][MAX];
char out[MAX*2];

int main()
{
    ans=1e9;
    memset(a,0,sizeof(a));
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            two[i][j]=0;
            five[i][j]=0;
            t=a[i][j];
            while (t%2==0)
            {
                t=t/2;
                two[i][j]++;
            }
            t=a[i][j];
            while (t%5==0)
            {
                t=t/5;
                five[i][j]++;
            }
            if (a[i][j]==0)
            {
                ans=two[i][j]=five[i][j]=1;
            }
        }
    }
    if (ans==1)
    {
        for (x=1;x<=n;x++)
        {
            for (y=1;y<=n;y++)
            {
                if (a[x][y]==0)
                {
                    break;
                }
            }
        }
        t=0;
        for (int i=1;i<x;i++)
        {
            out[t]='D';
            t++;
        }
        for (int i=1;i<=n;i++)
        {
            out[t]='R';
            t++;
        }
        for (int i=x;i<=n;i++)
        {
            out[t]='D';
            t++;
        }
        out[t]='\0';
    }
    memset(f,0,sizeof(f));
    memset(prv,0,sizeof(prv));
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i-1==1&&j-1==1)
            {
                f[i][j]=two[i][j];
            }
            else if (i-1==1)
            {
                prv[i][j]='R';
                f[i][j]=f[i][j-1]+two[i][j];
            }
            else if (j-1==1)
            {
                prv[i][j]='D';
                f[i][j]=f[i-1][j]+two[i][j];
            }
            else if (f[i-1][j]>f[i][j-1])
            {
                prv[i][j]='R';
                f[i][j]=f[i][j-1]+two[i][j];
            }
            else
            {
                prv[i][j]='D';
                f[i][j]=f[i-1][j]+two[i][j];
            }
        }
    }
    if (f[n][n]<ans)
    {
        ans=f[n][n];
        x=n;
        y=n;
        t=0;
        while (x!=1||y!=1)
        {
            out[t]=prv[x][y];
            t++;
            if (prv[x][y]=='D')
            {
                x=x-1;
            }
            else
            {
                y=y-1;
            }
        }
        out[t]='\0';
        strrev(out);
    }

    memset(f,0,sizeof(f));
    memset(prv,0,sizeof(prv));
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i-1==1&&j-1==1)
            {
                f[i][j]=five[i][j];
            }
            else if (i-1==1)
            {
                prv[i][j]='R';
                f[i][j]=f[i][j-1]+five[i][j];
            }
            else if (j-1==1)
            {
                prv[i][j]='D';
                f[i][j]=f[i-1][j]+five[i][j];
            }
            else if (f[i-1][j]>f[i][j-1])
            {
                prv[i][j]='R';
                f[i][j]=f[i][j-1]+five[i][j];
            }
            else
            {
                prv[i][j]='D';
                f[i][j]=f[i-1][j]+five[i][j];
            }
        }
    }
    if (f[n][n]<ans)
    {
        ans=f[n][n];
        x=n;
        y=n;
        t=0;
        while (x!=1||y!=1)
        {
            out[t]=prv[x][y];
            t++;
            if (prv[x][y]=='D')
            {
                x=x-1;
            }
            else
            {
                y=y-1;
            }
        }
        out[t]='\0';
        strrev(out);
    }
    cout<<ans<<endl;
    cout<<out<<endl;
    return 0;
}
