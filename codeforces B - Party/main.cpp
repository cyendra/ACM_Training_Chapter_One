#include <iostream>
#include <vector>

using namespace std;

vector<int>a[2222];
int p[2222]={0};
int n;
int deep[2222]={0};


void dfs(int i,int d)
{
    int len=a[i].size();
    deep[i]=d;
    for (int v=0;v<len;v++)
    {
        dfs(a[i][v],d+1);
    }
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>p[i];
        if (p[i]!=-1)
        {
            a[p[i]].push_back(i);
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (p[i]==-1)
        {
            dfs(i,1);
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (deep[i]>ans)
        {
            ans=deep[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
