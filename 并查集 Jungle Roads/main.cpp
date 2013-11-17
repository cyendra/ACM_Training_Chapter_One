#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int OO=1e9;

struct STREDGE
{
    int x;
    int y;
    int v;
}edge[55000];

int p[1111];

void make_set(int n);
int find_set(int x);
void union_set(int x,int y);

bool cmp(STREDGE a,STREDGE b);

int n,m,k;
char c;
int x,y;

int main()
{
    while (cin>>n)
    {
        if (n==0) break;
        m=0;
        memset(p,0,sizeof(p));
        memset(edge,0,sizeof(edge));
        for (int i=1;i<n;i++)
        {
            cin>>c>>k;
            x=c-'A'+1;
            for (int j=1;j<=k;j++)
            {
                cin>>c;
                y=c-'A'+1;
                cin>>edge[m].v;
                edge[m].x=x;
                edge[m].y=y;
                m++;
            }
        }
        sort(edge,edge+m,cmp);
        make_set(n);
        int ans=0;
        for (int i=0;i<m;i++)
        {
            x=edge[i].x;
            y=edge[i].y;
            int a=find_set(x);
            int b=find_set(y);
            if (a!=b)
            {
                union_set(x,y);
                ans+=edge[i].v;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

bool cmp(STREDGE a,STREDGE b)
{
    return a.v<b.v;
}

void make_set(int t)
{
    for (int i=1; i<=t; i++) p[i]=i;
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
