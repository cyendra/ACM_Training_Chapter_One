#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int n,m;
int c[111111];
set<int>st[111111];


int main()
{
    cin>>n>>m;
    int ans=100000;
    for (int i=1;i<=n;i++)
    {
        cin>>c[i];
        ans=min(ans,c[i]);
    }
    for (int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        if (c[a]!=c[b])
        {
            st[c[a]].insert(c[b]);
            st[c[b]].insert(c[a]);
        }
    }
    for (int i=1;i<=100000;i++)
    {
        if ( ans==-1||st[i].size()>st[ans].size())
        {
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
