#include <iostream>
#include <queue>

using namespace std;



int n,m;
struct PP{
    int l;
    int r;
    int t;
    int c;
    int id;
    bool operator<(const PP & tmp) const
    {
        if (t==tmp.t) return id>tmp.id;
        return t>tmp.t;
    }
}a[111];
priority_queue<PP>que[111];
int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>a[i].l>>a[i].r>>a[i].t>>a[i].c;
        a[i].id=i;
        for (int j=a[i].l;j<=a[i].r;j++)
        {
            que[j].push(a[i]);
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (!que[i].empty())
        {
            //cout<<que[i].top().c<<" ";
            ans+=que[i].top().c;
        }
    }
    //cout<<endl;
    cout<<ans<<endl;
    return 0;
}
