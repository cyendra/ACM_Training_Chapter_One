#include <iostream>
//#include <fstream>
#include <cstring>
#include <string>
#include <map>
#include <sstream>

using namespace std;

//ifstream cin("input.txt");
//ofstream cout("output.txt");

const int OO=1e9;

int f[300][300];
int cost[300];
int dad[300];
int son[300];
int r[300];
int l[300];
int n,m;
string str;
char blank;
int cnt;

map<string,int>mp;

void init()
{
    memset(f,-1,sizeof(f));
    memset(cost,0,sizeof(cost));
    memset(dad,0,sizeof(dad));
    memset(son,0,sizeof(son));
    memset(r,-1,sizeof(r));
    memset(l,-1,sizeof(l));
    mp.clear();
    cnt=0;
}

int input(string name)
{
    map<string,int>::iterator it;
    it=mp.find(name);
    if (it!=mp.end())
    {
        return it->second;
    }
    cnt++;
    mp[name]=cnt;
    return mp[name];
}

int sumson(int i)
{
    int ret=0;
    if (l[i]==-1)
    {
        son[i]=1;
        return son[i];
    }
    else
    {
        int p=l[i];
        while (p!=-1)
        {
            ret+=sumson(p);
            p=r[p];
        }
        son[i]=ret+1;
        return son[i];
    }
}

int dp(int i,int j)
{
    if (j<=0) return 0;//不用取的情况
    if ( f[i][j]!=-1) return f[i][j];
    int ret=OO;

    //取节点i的情况
    if ( r[i]>0 )
    {
        ret=cost[i]+dp(r[i],j-son[i]);//i有兄弟
    }
    else
    {
        ret=cost[i];//i无兄弟
        if (j-son[i]>0) ret=OO;//即使取i也不够数量
    }
    if ( i==0 ) ret=OO;//必须不取根节点
    //不取节点i的情况
    if (l[i]<=0&&r[i]<=0)//无子节点，无兄弟节点
    {
        f[i][j]=ret;//必取i
        return ret;
    }
    if (l[i]<=0&&r[i]>0) ret=min(ret,dp(r[i],j));//只有兄弟节点
    if (r[i]<=0&&l[i]>0) ret=min(ret,dp(l[i],j));//只有子节点
    for (int t=0;t<=j;t++)
    {
        ret=min(ret,dp(l[i],t)+dp(r[i],j-t));//子节点取t，兄弟节点取j-t
    }
    f[i][j]=ret;
    return f[i][j];
}

int main()
{
    while (cin>>n>>m)
    {
        init();//初始化
        for (int i=1;i<=n;i++)
        {
            int u;
            cin>>str;
            u=input(str);
            cin>>cost[u];
            while (cin.get()!='\n')
            {
                int s;
                cin>>str;
                s=input(str);
                dad[s]=u;
            }
        }
        //数据读入完毕
        for (int i=1;i<=n;i++)
        {
            int p=dad[i];
            if (l[p]==-1)
            {
                l[p]=i;
            }
            else
            {
                p=l[p];
                while (r[p]!=-1)
                {
                    p=r[p];
                }
                r[p]=i;
            }
        }
        //建树完毕
        sumson(0);
        //计算子树个数完毕
        int ans=dp(0,m);
        cout<<ans<<endl;
    }
    return 0;
}
