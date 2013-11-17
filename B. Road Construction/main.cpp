#include <iostream>
#include <cstring>

using namespace std;

const int maxn=1111;

bool dis[maxn][maxn];
int n,m;

int main()
{
    memset(dis,0,sizeof(dis));
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        dis[x][y]=true;
        dis[y][x]=true;
    }
    for (int rt=1;rt<=n;rt++)
    {
        bool flag=true;
        for (int i=1;i<=n;i++)
        {
            if (dis[rt][i])
            {
                flag=false;
                break;
            }
        }
        if (flag)
        {
            cout<<n-1<<endl;
            for (int i=1;i<=n;i++)
            {
                if (i!=rt)
                {
                    cout<<i<<" "<<rt<<endl;
                }
            }
            break;
        }
    }
    return 0;
}
