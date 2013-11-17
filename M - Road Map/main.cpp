#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n,r1,r2;
vector<int>a[111111];
int p[111111]={0};
bool v[111111]={0};

void dfs(int i)
{
    v[i]=true;
    for (int j=0;j<a[i].size();j++)
    {
        if (!v[a[i][j]])
        {
            p[a[i][j]]=i;
            dfs(a[i][j]);
        }
    }
}

int main()
{
    cin>>n>>r1>>r2;
    for (int i=1;i<=n;i++)
    {
        if (i!=r1)
        {
            int j;
            cin>>j;
            a[i].push_back(j);
            a[j].push_back(i);
        }
    }
    dfs(r2);
    for (int i=1;i<=n;i++)
    {
        if (i!=r2)
        {
            cout<<p[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}
