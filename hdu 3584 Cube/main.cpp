#include <iostream>
#include <cstring>

using namespace std;

int n,m;
int tree[111][111][111];

int lowbit(int i)
{
    return i&(-i);
}

void updata(int x,int y,int z,int d)
{
    for (int i=x;i<=n;i+=lowbit(i))
    {
        for (int j=y;j<=n;j+=lowbit(j))
        {
            for (int k=z;k<=n;k+=lowbit(k))
            {
                tree[i][j][k]+=d;
            }
        }
    }
}

int query(int x,int y,int z)
{
    int sum=0;
    for (int i=x;i>0;i-=lowbit(i))
    {
        for (int j=y;j>0;j-=lowbit(j))
        {
            for (int k=z;k>0;k-=lowbit(k))
            {
                sum+=tree[i][j][k];
            }
        }
    }
    return sum;
}

int main()
{
    while (cin>>n>>m)
    {
        memset(tree,0,sizeof(tree));
        int q;
        while (m--)
        {
            cin>>q;
            if (q==0)
            {
                int x,y,z;
                cin>>x>>y>>z;
                int ans=query(x,y,z)%2;
                cout<<ans<<endl;
            }
            else if (q==1)
            {
                int x1,y1,z1,x2,y2,z2;
                cin>>x1>>y1>>z1>>x2>>y2>>z2;
                updata(x1,y1,z1,1);

                updata(x2+1,y1,z1,1);
                updata(x1,y2+1,z1,1);
                updata(x1,y1,z2+1,1);

                updata(x1,y2+1,z2+1,1);
                updata(x2+1,y1,z2+1,1);
                updata(x2+1,y2+1,z1,1);

                updata(x2+1,y2+1,z2+1,1);
            }
        }
    }
    return 0;
}
