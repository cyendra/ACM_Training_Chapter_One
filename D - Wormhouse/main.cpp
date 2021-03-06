#include <iostream>

using namespace std;

bool a[222][222];
int p[2222];
int ans[2222];
int n,m;

bool dfs(int u,int deep,bool ok)
{
    int v;
    ans[deep]=u;
    if (deep==m) return ok;
    if (ok) v=1;
    else v=p[deep+1];
    for (int i=v;i<=n;i++)
    {
        if (a[u][i])
        {
            a[u][i]=false;
            a[i][u]=false;
            if (i!=p[deep+1])//第deep+1条边大于原路径，字典序必然大于原回路
            {
                if (dfs(i,deep+1,true)) return true;
            }
            else
            {
                if (dfs(i,deep+1,ok)) return true;
            }
            a[u][i]=true;
            a[i][u]=true;
        }
    }
    return false;
}

int main()
{
    cin>>n>>m;
    for (int i=0;i<=m;i++)
    {
        cin>>p[i];
        if (i>0) a[p[i-1]][p[i]]=a[p[i]][p[i-1]]=true;
    }
    if (dfs(p[0],0,false))
    {
        for (int i=0;i<=m;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"No solution"<<endl;
    }
    return 0;
}
