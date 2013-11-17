#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int tree[1111][1111];
int n;

int lowbit(int i)
{
    return i&(-i);
}

void updata(int x,int y,int d)
{
    for (int i=x;i<=n;i+=lowbit(i))
    {
        for (int j=y;j<=n;j+=lowbit(j))
        {
            tree[i][j]+=d;
        }
    }
}

int query(int x,int y)
{
    int sum=0;
    for (int i=x;i>0;i-=lowbit(i))
    {
        for (int j=y;j>0;j-=lowbit(j))
        {
            sum+=tree[i][j];
        }
    }
    return sum;
}

int main()
{
    int X,T;
    char c;
    int x,y,x1,y1,x2,y2;
    cin>>X;
    while (X--)
    {
        memset(tree,0,sizeof(tree));
        cin>>n>>T;
        while (T--)
        {
            cin>>c;
            if (c=='C')
            {
                cin>>x1>>y1>>x2>>y2;
                updata(x1,y1,1);
                updata(x1,y2+1,-1);
                updata(x2+1,y1,-1);
                updata(x2+1,y2+1,1);
            }
            if (c=='Q')
            {
                cin>>x>>y;
                int ans=query(x,y)%2;
                cout<<ans<<endl;
            }
        }
        if (X) cout<<endl;
    }
    return 0;
}
