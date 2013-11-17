#include <iostream>
#include <cstring>

using namespace std;

int n,m;
int tree[1111][1111];
bool map[1111][1111];

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
    char c;
    int x,y;
    int x1,x2,y1,y2;
    n=1000;
    while (cin>>m)
    {
        memset(tree,0,sizeof(tree));
        memset(map,0,sizeof(map));
        for (int k=1;k<=m;k++)
        {
            cin>>c;
            if (c=='B')
            {
                cin>>x>>y;
                x++;y++;
                if (!map[x][y])
                {
                    updata(x,y,1);
                    map[x][y]=true;
                }
            }
            else if (c=='D')
            {
                cin>>x>>y;
                x++;y++;
                if (map[x][y])
                {
                    updata(x,y,-1);
                    map[x][y]=false;
                }
            }
            else if (c=='Q')
            {
                cin>>x1>>x2>>y1>>y2;
                x1++;x2++;y1++;y2++;
                if (x1>x2) swap(x1,x2);
                if (y1>y2) swap(y1,y2);
                int ans=query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
