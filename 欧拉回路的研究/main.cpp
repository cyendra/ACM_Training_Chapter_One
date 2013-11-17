#include <iostream>
#include <cstring>
using namespace std;

bool a[222][222];
int ans[2222];
int n,m;
int cnt;
int bg;
bool dfs(int u,int deep)
{
    ans[deep]=u;//将点u加入到路径中
    if (deep==m)//若遍历了所有的边
    {
        if (u==bg)//终点等于起点，即找到欧拉回路
        {
            for (int i=0; i<=m; i++)
            {
                cout<<ans[i]<<" ";//输出路径
            }
            cout<<endl;
        }
        return true;//找到字典序最小的欧拉回路
    }
    for (int i=1; i<=n; i++)//遍历所有节点
    {
        if (a[u][i])//若当前点u与点i间有边
        {
            a[u][i]=false;a[i][u]=false;//消除此边表示已经遍历过
            if (dfs(i,deep+1))//寻找下一条边
            {
                return true;//找到字典序最小的欧拉回路，直接返回true
            }
            a[u][i]=true;a[i][u]=true;//回溯
        }
    }
    return false;//未找到欧拉回路
}

/*
void dfs(int u)
{
    for (int i=1;i<=n;i++)
    {
        if (a[u][i])
        {
            a[u][i]=false;
            a[i][u]=false;
            dfs(i);
            ans[++cnt]=i;
        }
    }
}
*/
int main()
{

    while(cin>>n>>m>>bg)
    {
        cnt=0;
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        for (int i=1; i<=m; i++)
        {
            int x,y;
            cin>>x>>y;
            a[x][y]=true;
            a[y][x]=true;
        }
        dfs(bg,0);
        /*
        if (ret)
        {
            for (int i=1;i<=m;i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<"Not find"<<endl;
        }
        */
    }
    return 0;
}
