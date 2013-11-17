#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int mn=1000000;
int m,n;
int p[211111];
int dn[211111];

int ax[211111];
int ay[211111];
bool v[211111];
int papa[211111];
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
    int loop=1;

    while ( flag )
    {
        init();
        memset(dn,0,sizeof(dn));
        memset(v,0,sizeof(v));
        while (scanf("%d%d",&x,&y))
        {
            dn[y]++;
            if ( x<=-1 && y<=-1 ){ flag=false; break; }
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
        memset(papa,-1,sizeof(papa));
        for (int i=1;i<=m;i++)
        {
            x=ax[i];
            y=ay[i];
            if ( papa[y]==-1 ) papa[y]=x;
            else if (papa[y]!=x) ok=false;
            int a=find_set(x);
            int b=find_set(y);
            if (a==b) ok=false;
            union_set(x,y);
            //cout<<x<<" "<<y<<endl;
        }
        //for (int i=1;i<=n;i++) cout<<p[i]<<" ";cout<<endl;
        int cnt=0;
        int father=0;

        for (int i=1;i<=n;i++)
        {
            if (v[i]&&p[i]==i) cnt++;
            if (v[i]&&dn[i]==0) father++;
        }
        if (cnt>1) ok=false;
        if (father!=1) ok=false;
        if (m==0) ok=true;
        //cerr<<cnt<<" "<<father<<" "<<m<<" "<<n<<endl;
        if (ok) printf("Case %d is a tree.\n",loop);
        else  printf("Case %d is not a tree.\n",loop);
        loop++;
    }
    return 0;
}
