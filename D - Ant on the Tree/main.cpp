#include <iostream>
#include <cstring>
#define OO 9999999
using namespace std;

int a[500][500];
int f[500][500];//floyd
int path[500][500];//表示前驱节点
int ans[2000]={0}; //表示总路径数
int du[500]={0}; //度
int n;
int zi[500]={0};
int zinum;
int cut=0;

int main()
{
    int x,y;
    memset(a,0,sizeof(a));
    //memset(f,0,sizeof(f));
    cin>>n;
    for (int i=0; i<n-1; i++)
    {
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
        du[x]++;
        du[y]++;
    }
    zinum=0;
    for (int i=2; i<=n; i++)
    {
        if (du[i]==1) zinum+=1;
    }
    for (int i=1; i<=zinum; i++)
    {
        cin>>zi[i];
    }
    //floyd
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            f[i][j]=OO;
            if (i==j) f[i][j]=0;
            if ( i!=j&&a[i][j]>0 )
            {
                f[i][j]=1;
                path[i][j]=i;
                //cout<<path[i][j]<<endl;

            }
            else
            {
                path[i][j]=-1;
            }
            //cout<<f[i][j]<<" ";
        }
        //cout<<endl;
    }
    /*

    */
    for (int k=1; k<=n; k++)
    {
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                if (f[i][k]+f[k][j]<f[i][j])
                {
                    f[i][j]=f[i][k]+f[k][j];
                    path[i][j]=path[k][j];
                    //cout<<path[i][j]<<endl;
                }
            }
        }
    }
/*
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    int bg,ed;
    zi[0]=1;
    zi[++zinum]=1;
    ans[cut++]=1;
    for (int i=0;i<zinum;i++)
    {
        bg=zi[i+1];
        ed=zi[i];
        //cout<<bg<<" "<<ed<<endl;
        //cout<<path[bg][ed]<<endl;
        while (path[bg][ed]!=-1)
        {
            //cout<<path[bg][ed]<<" ";
            ans[cut++]=path[bg][ed];
            if (cut>2*n) break;
            ed=path[bg][ed];
        }
    }
    if ( cut>2*n ) cout<<"-1"<<endl;
    else
    {
        cout<<ans[0];
        for (int i=1;i<cut;i++)
        {
            cout<<" "<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
