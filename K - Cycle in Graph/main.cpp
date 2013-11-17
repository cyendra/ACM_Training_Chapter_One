#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int>a[111111];
vector<int>path;
bool v[111111]={0};
bool done[111111]={0};
int dis[111111]={0};
int n,m,k;
bool ok=false;

void dfs(int i,int deep)
{
    if (v[i]) return;
    v[i]=true;
    path.push_back(i);
    dis[i]=deep;
    for (int j=0;j<a[i].size()&&!ok;j++)
    {
        if (v[a[i][j]]&&!done[a[i][j]]&&deep-dis[a[i][j]]>=k)
        {
            int pos=0;
            while (path[pos]!=a[i][j]) pos++;
            cout<<deep-pos+1<<endl;
            for (int k=pos;k<=deep;k++)
            {
                cout<<path[k]<<" ";
            }
            cout<<endl;
            ok=true;
        }
        else
        {
            dfs(a[i][j],deep+1);
        }
    }
    done[i]=true;
    path.pop_back();
}

int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,0);
    return 0;
}
