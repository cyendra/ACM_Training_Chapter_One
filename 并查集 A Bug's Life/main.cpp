#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int m,n;
bool a[2222][2222];
int sex[2222];
bool v[2222];
bool flag;

void dfs(int x)
{
    if (!flag) return;
    if (v[x]) return;
    int p=(sex[x]+1)%2;
    v[x]=true;
    for (int i=1;i<=n;i++)
    {
        if ( x!=i && a[x][i] )
        {
            if ( sex[i]==-1 )
            {
                sex[i]=p;
                dfs(i);
            }
            if ( sex[i]==sex[x] )
            {
                flag=false;
                break;
            }
        }
    }
}

int main()
{
    int T;
    int loop=1;
    //cin>>T;
    scanf("%d",&T);
    while (T--)
    {
        memset(a,0,sizeof(a));
        memset(v,0,sizeof(v));
        memset(sex,-1,sizeof(sex));
        flag=true;
        //cin>>n>>m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=m;i++)
        {
            int x,y;
            //cin>>x>>y;
            scanf("%d%d",&x,&y);
            a[x][y]=1;
            a[y][x]=1;
        }
        for (int i=1;i<=n;i++)
        {
            if (flag&&!v[i])
            {
                sex[i]=0;
                dfs(i);
            }
        }
        printf("Scenario #%d:\n",loop);
        //cout<<"Scenario #"<<loop<<":"<<endl;
        loop++;
        if (flag) printf("No suspicious bugs found!\n");
        //cout<<"No suspicious bugs found!"<<endl;
        else printf("Suspicious bugs found!\n");
        //cout<<"Suspicious bugs found!"<<endl;
        //cout<<endl;
        printf("\n");
    }
    return 0;
}
