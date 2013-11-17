#include <iostream>
#include <cstring>

using namespace std;

bool a[4111][4111];
int n;
bool v[4111]={0};
int p[4111]={0};
int cnt=0;
int ans[4111]={0};

bool dfs_find(int i,int lt)
{
    v[i]=true;
    for (int j=1;j<=n;j++)
    {
        if (a[i][j]>0&&lt!=j&&i!=j)
        {
            if (v[j])
            {
                p[cnt++]=j;
                return true;
            }
            else
            {
                p[cnt++]=j;
                if (dfs_find(j,i))
                {
                    return true;
                }
                cnt--;
            }
        }
    }
    return false;
}

void dfs(int i)
{
    for (int j=1;j<=n;j++)
    {
        if (i!=j&&a[i][j]>0&&ans[j]==-1)
        {
            ans[j]=ans[i]+1;
            dfs(j);
        }
    }
}

int main()
{
    memset(a,0,sizeof(a));
    memset(ans,-1,sizeof(ans));
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    p[cnt++]=1;
    dfs_find(1,0);

    ans[p[cnt-1]]=0;
    for (int i=cnt-2;i>=0;i--)
    {
        if (p[i]==p[cnt-1]) break;
        ans[p[i]]=0;
    }

    for (int i=1;i<=n;i++)
    {
        if (ans[i]==0)
        {
            dfs(i);
        }
    }

    for (int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
