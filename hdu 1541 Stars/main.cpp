#include <iostream>
#include <cstring>

using namespace std;

int tree[40000];
int m;
const int maxn=32001;
int ans[40000];

int lowbit(int i)
{
    return i&(-i);
}

void updata(int i,int x)
{
    while (i<=maxn)
    {
        tree[i]+=x;
        i+=lowbit(i);
    }
}

int query(int i)
{
    int sum=0;
    while (i>0)
    {
        sum+=tree[i];
        i-=lowbit(i);
    }
    return sum;
}
int main()
{
    int x,y;
    while (cin>>m)
    {
        memset(tree,0,sizeof(tree));
        memset(ans,0,sizeof(ans));
        for (int i=1;i<=m;i++)
        {
            cin>>x>>y;
            x++;y++;
            ans[query(x)]++;
            updata(x,1);
        }
        for (int i=0;i<m;i++)
        {
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}
