#include <iostream>
#include <cstring>

using namespace std;

const long long maxn=(1<<16);

long long n,m,i;

long long f[14][maxn];

void init(long long x,long long now)
{
    if (x==m+1) f[1][now]++;
    if (x>m) return;
    init(x+1,now<<1);
    init(x+2,(now<<2)|3);
}

void dfs(long long x,long long lst,long long nxt)
{
    if (x==m+1){
        f[i][nxt]+=f[i-1][lst];
        //cerr<<x<<" "<<lst<<" "<<nxt<<endl;
        //cerr<<f[i][nxt]<<" "<<f[i-1][lst]<<endl;
    }
    //cerr<<i<<" "<<nxt<<" "<<f[i][nxt]<<endl;
    if (x>m) return;
    dfs(x+1,(lst<<1)|1,nxt<<1);
    dfs(x+1,lst<<1,(nxt<<1)|1);
    dfs(x+2,(lst<<2)|3,(nxt<<2)|3);
}

int main()
{
    while (cin>>n>>m)
    {
        if (m==0&&n==0) break;
        if (m>n) swap(m,n);
        memset(f,0,sizeof(f));
        init(1,0);
        //for (int j=0;j<=(1<<m)-1;j++){//if (f[1][j]>0) cerr<<j<<endl;//cerr<<f[1][j]<<endl;}
        for (i=2;i<=n;i++)
        {
            dfs(1,0,0);
            //for (int j=0;j<=(1<<m)-1;j++){cerr<<f[i][j]<<" ";/*if (f[i][j]>0) cerr<<j<<" ";*/}cerr<<endl;
        }
        cout<<f[n][(1<<m)-1]<<endl;
    }
    return 0;
}
