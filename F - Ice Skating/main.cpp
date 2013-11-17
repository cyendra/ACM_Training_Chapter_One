#include <iostream>

using namespace std;

int n;
int x[1111];
int y[1111];
bool v[1111]={0};

void dfs(int i)
{
    v[i]=true;
    for (int j=1;j<=n;j++)
    {
        if (!v[j]&&(x[i]==x[j]||y[i]==y[j]))
        {
            dfs(j);
        }
    }
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (!v[i])
        {
            dfs(i);
            ans++;
        }
    }
    cout<<ans-1<<endl;
    return 0;
}
