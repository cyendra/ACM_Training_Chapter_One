#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn=110000;

int p[maxn];
void make_set(int n)
{
    for (int i=0;i<=n;i++) p[i]=i;
}
int find_set(int x)
{
    if (x!=p[x]) p[x]=find_set(p[x]);
    return p[x];
}
void unin(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    if (x!=y) p[x]=y;
}
int n,m;

int main()
{
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        scanf("%d",&m);
        make_set(n);
        while (m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            unin(x,y);
        }
        int ans=0;
        for (int i=1;i<=n;i++) if (p[i]==i) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
