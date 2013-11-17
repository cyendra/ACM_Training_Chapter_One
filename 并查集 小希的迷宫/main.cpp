#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int mn=100000;
int m,n;
int p[111111];

int ax[111111];
int ay[111111];
bool v[111111];
bool flag=true;
bool ok=true;

void make_set(int x);
int find_set(int x);
void union_set(int x,int y);
void init();

void init()
{
    memset(ax,0,sizeof(ax));
    memset(ay,0,sizeof(ay));
    memset(v,0,sizeof(v));
    m=0;
    n=0;
    ok=true;
    for (int i=1;i<=mn;i++) make_set(i);
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

int main()
{
    int x,y;

    while ( flag )
    {
        init();
        while (cin>>x>>y)
        {
            if ( x==-1 && y==-1 ){ flag=false; break; }
            if ( x==0 && y==0 ) break;
            v[x]=true;
            v[y]=true;
            if (x>n) n=x;
            if (y>n) n=y;
            m++;
            ax[m]=x;
            ay[m]=y;
        }
        if (!flag) break;
        for (int i=1;i<=m;i++)
        {
            x=ax[i];
            y=ay[i];
            int a=find_set(x);
            int b=find_set(y);
            if (a==b) ok=false;
            union_set(x,y);
            //cout<<x<<" "<<y<<endl;
        }
        //for (int i=1;i<=n;i++) cout<<p[i]<<" ";cout<<endl;
        int cnt=0;
        for (int i=1;i<=n;i++)
        {
            if (v[i]&&p[i]==i) cnt++;
        }
        if (cnt>1) ok=false;
        if (ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
