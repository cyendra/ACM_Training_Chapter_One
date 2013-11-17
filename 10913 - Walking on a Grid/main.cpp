#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const long long OO=1e17;
long long a[111][111];
long long f[111][111][6][3];
bool v[111][111][6][3];
int n;

long long dfs(int x,int y,int k,int tp)
{
    long long &ret=f[x][y][k][tp];
    long long tmp;
    if (v[x][y][k][tp]) return ret;
    v[x][y][k][tp]=true;
    ret=-OO;
    if (a[x][y]<0) k--;
    if (k<0) return -OO;
    if (x==1&&y==1) return ret=a[1][1];
    if (tp!=1&&y>1)
    {
        tmp=dfs(x,y-1,k,2);
        if (tmp!=-OO) ret=max(ret,tmp+a[x][y]);
    }
    if (tp!=2&&y<n)
    {
        tmp=dfs(x,y+1,k,1);
        if (tmp!=-OO) ret=max(ret,tmp+a[x][y]);
    }
    if (x>1)
    {
        tmp=dfs(x-1,y,k,0);
        if (tmp!=-OO) ret=max(ret,tmp+a[x][y]);
    }
    return ret;
}

int main()
{
    int cnt=1;
    int k;
    while (cin>>n>>k)
    {
        if (n==0&&k==0) break;
        memset(v,0,sizeof(v));
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                cin>>a[i][j];
            }
        }
        long long ans=dfs(n,n,k,0);
        cout<<"Case "<<cnt++;
        if (ans==-OO) cout<<": impossible"<<endl;
        else cout<<": "<<ans<<endl;
    }
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int OO=1e9;

int a[111][111];
int f[111][111][3];
bool v[111][111][3];
int n,k;
bool end;

int dfs(int x,int y,int tp)
{
    int ret=-OO,tmp;
    if (a[x][y]<-k) return -OO;
    if (x==1&&y==1)
    {
        end=true;
        return a[1][1];
    }
    if (v[x][y][tp]) return f[x][y][tp];
    if (tp==0)
    {
        if (x>1)
        {
            if (a[x-1][y]>=-k) tmp=dfs(x-1,y,0);
            ret=max(ret,tmp);
        }
        if (y<n)
        {
            if (a[x][y+1]>=-k) tmp=dfs(x,y+1,1);
            if (tmp>ret)
            {
                ret=tmp;
            }
        }
        if (y>1)
        {
            if (a[x][y-1]>=-k) tmp=dfs(x,y-1,2);
            if (tmp>ret)
            {
                ret=tmp;
            }
        }
    }
    if (tp==1)
    {
        if (x>1)
        {
            if (a[x-1][y]>=-k) tmp=dfs(x-1,y,0);
            if (tmp>ret)
            {
                ret=tmp;
            }
        }
        if (y<n)
        {
            if (a[x][y+1]>=-k) tmp=dfs(x,y+1,1);
            if (tmp>ret)
            {
                ret=tmp;
            }
        }
    }
    if (tp==2)
    {
        if (x>1)
        {
            if (a[x-1][y]>=-k) tmp=dfs(x-1,y,0);
            if (tmp>ret)
            {
                ret=tmp;
            }
        }
        if (y>1)
        {
            if (a[x][y-1]>=-k) tmp=dfs(x,y-1,2);
            if (tmp>ret)
            {
                ret=tmp;
            }
        }
    }
    v[x][y][tp]=true;
    if (ret==-OO)
    {
        f[x][y][tp]=ret;
        return ret;
    }
    f[x][y][tp]=ret+a[x][y];
    return ret+a[x][y];
}

int main()
{
    int cnt=1;
    while (~scanf("%d%d",&n,&k))
    {
        if (n==0&&k==0) break;
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        end=false;
        int ans=dfs(n,n,0);
        if (!end) printf("Case %d: impossible\n",cnt++);
        else printf("Case %d: %d\n",cnt++,ans);
        //cerr<<ans<<endl;
    }
    return 0;
}

*/
