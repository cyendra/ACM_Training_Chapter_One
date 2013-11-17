#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge{
    int x;
    int y;
    int spd;
};

const int OO=1e9;

void make_set(int x);
int find_set(int x);
void union_set(int x,int y);
bool cmp(edge a,edge b);
void init();

edge a[1111];

int p[1111];

int n,m,Q;
int bg,ed;
int start_spd,end_spd;
int ans_start,ans_end;
int ans;

int main()
{
    while (cin>>n>>m)
    {
        init();
        for (int i=1;i<=m;i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].spd;
        }
        sort(a+1,a+m+1,cmp);
        cin>>Q;
        for (int k=1;k<=Q;k++)
        {
            cin>>bg>>ed;
            ans=OO;
            for (int i=1;i<=m;i++)
            {
                for (int j=1;j<=n;j++) make_set(j);
                for (int j=i;j>=1;j--)
                {
                    union_set(a[j].x,a[j].y);
                    if ( find_set(bg)==find_set(ed) )
                    {
                        ans=min( ans, a[i].spd-a[j].spd );
                        break;
                    }
                }
            }
            if (ans==OO) cout<<"-1"<<endl;
            else cout<<ans<<endl;
        }
    }
    return 0;
}


void make_set(int x)
{
    p[x]=x;
}

int find_set(int x)
{
    if ( p[x]==x ) return x;
    else
    {
        int u=find_set(p[x]);
        p[x]=u;
        return u;
    }
}

void union_set(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    p[y]=x;
}

bool cmp(edge a,edge b)
{
    return ( a.spd<b.spd );
}

void init()
{
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    start_spd=0;
    end_spd=0;
    ans_start=0;
    ans_end=0;
    ans=OO;
}
