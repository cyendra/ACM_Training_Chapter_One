
#include <iostream>
#include <cstring>

using namespace std;

int n,T;
int m,s;
int c[111],g[111];
int f[222][222];
int num;

const int OO=99999999;

void intput();
void pack();

void input()
{
    cin>>m>>s;
    for (int i=1;i<=m;i++)
    {
        cin>>c[i]>>g[i];
    }
}

void pack()
{
    num++;
    if (s==0)
    {
        for (int i=0;i<=T;i++)
        {
            f[num][i]=-OO;
        }
        for (int i=1;i<=m;i++)
        {
            for (int j=T;j>=c[i];j--)
            {
                f[num][j]=max( f[num][j] , f[num][j-c[i]]+g[i] );
                f[num][j]=max( f[num][j] , f[num-1][j-c[i]]+g[i] );
            }
        }
    }
    else if (s==1)
    {
        for (int i=0;i<=T;i++)
        {
            f[num][i]=f[num-1][i];
        }
        for (int i=1;i<=m;i++)
        {
            for (int j=T;j>=c[i];j--)
            {
                f[num][j]=max( f[num][j] , f[num-1][j-c[i]]+g[i] );
            }
        }
    }
    else
    {
        for (int i=0;i<=T;i++)
        {
            f[num][i]=f[num-1][i];
        }
        for (int i=1;i<=m;i++)
        {
            for (int j=T;j>=c[i];j--)
            {
                f[num][j]=max( f[num][j] , f[num][j-c[i]]+g[i] );
            }
        }
    }
}

int main()
{
    while (cin>>n>>T)
    {
        num=0;
        memset(f,0,sizeof(f));
        memset(c,0,sizeof(c));
        memset(g,0,sizeof(g));
        for (int lp=1;lp<=n;lp++)
        {
            input();
            pack();
        }
        if ( f[num][T]>=0 ) cout<<f[num][T]<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}
