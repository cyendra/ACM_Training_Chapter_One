#include <iostream>
#include <algorithm>
#include <cstring>
#define OO 999999
using namespace std;

int c[100][100];//容量
int f[100][100];//流量
int b[100];     //增广路径前驱结点
int sum;
int n,m;

bool findflow(int k);
void addflow();

//找到k节点的后继节点i
bool findflow(int k)
{
    if (k==n) return true;//找到了一条增广路径
    for (int i=1;i<=n;i++)
    {
        if ( b[i]==-1 && (c[k][i]-f[k][i]>0||f[i][k]>0) )
        {
            b[i]=k;
            if ( findflow(i) ) return true;
        }
    }
    return false;
}

//沿增广路径增广
void addflow()
{
    int d=OO;
    int i=n;
    while ( b[i]!=0 )
    {
        if ( c[b[i]][i]>0 )
        {
            d=min(d,c[b[i]][i]-f[b[i]][i]);
        }
        if ( c[i][b[i]]>0 )
        {
            d=min(d,f[i][b[i]]);
        }
        i=b[i];
    }
    i=n;
    while ( b[i]!=0 )
    {
        if ( c[b[i]][i]>0 )
        {
            f[b[i]][i]+=d;
        }
        if ( c[i][b[i]]>0 )
        {
            f[i][b[i]]-=d;
        }
        i=b[i];
    }
    sum+=d;
}

int main()
{
    int x,y,z;
    cin >> n >> m;
    memset(c,-1,sizeof(c));
    memset(f,0,sizeof(f));
    for (int i=1;i<=m;i++)
    {
        cin >> x >> y >> z;
        c[x][y]=z;
    }
    for (int i=0;i<=n;i++) b[i]=-1;
    b[1]=0;
    while ( findflow(1) )
    {
        addflow();
        for (int i=0;i<=n;i++) b[i]=-1;
        b[1]=0;
    }
    cout << sum << endl;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (f[i][j]>0) cout << i << "-->" << j << " " << f[i][j] << endl;
        }
    }
    return 0;
}
