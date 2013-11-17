#include <iostream>
#include <cstring>

using namespace std;

int n,m;
int a[111][111];
int p[111]= {0};
int dis[111]= {0};
bool v[111]= {0};
int cnt=0;

bool find_cycle(int i,int papa)
{
    //cerr<<i<<" ------- "<<papa<<endl;
    v[i]=true;
    for (int j=1; j<=n; j++)
    {
        if (j!=papa&&i!=j&&a[i][j]>0)
        {
            if (!v[j])
            {
                p[cnt++]=j;
                if (find_cycle(j,i)) return true;
                cnt--;
            }
            else
            {
                p[cnt++]=j;
                return true;
            }
        }
    }
    return false;
}

bool dfs(int i,int papa)
{
    v[i]=true;
    for (int j=1;j<=n;j++)
    {
        if (i!=j&&j!=papa&&a[i][j])
        {
            if (papa==0&&dis[j]==0) continue;
            if (v[j]||dis[j]==0)
            {
                return true;
            }
            else
            {
                if (dfs(j,i)) return true;
            }
        }
    }
    return false;
}

void len_dfs(int i)
{
    v[i]=true;
    for (int j=1;j<=n;j++)
    {
        if (!v[j]&&a[i][j]>0) len_dfs(j);
    }
}

int main()
{
    memset(dis,-1,sizeof(dis));
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    p[cnt++]=1;
    memset(v,0,sizeof(v));
    bool ret=find_cycle(1,0);
    if (ret)
    {
        dis[p[cnt-1]]=0;
        for (int i=cnt-2; i>=0; i--)
        {
            if (p[i]==p[cnt-1]) break;
            dis[p[i]]=0;
        }
        //ready_dfs
        for (int i=1;i<=n;i++)
        {
            if (dis[i]==0)
            {
                memset(v,0,sizeof(v));
                if (dfs(i,0))
                {
                    ret=false;
                    break;
                }
            }
        }
        //dfs_over
    }

    memset(v,0,sizeof(v));
    len_dfs(1);
    for (int i=1;i<=n;i++)
    {
        if (!v[i]) ret=false;
    }
    if (ret) cout<<"FHTAGN!"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
