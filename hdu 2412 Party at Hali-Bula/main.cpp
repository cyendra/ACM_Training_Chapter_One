/*
#include <iostream>
#include <map>
#include <cstring>
#include <string>

using namespace std;

map<string,int>mp;//记录节点名字与编号的对应关系
int n;//节点数
int r[222]= {0};
int l[222]= {0}; //节点i，j的左右子树（用二叉树表示树，左子树是子节点，右子树为兄弟节点）
int f[222]= {0}; //节点i的父节点
int dp[222][2];
bool b[222][2];
string stra,strb;

int DP(int i,int t)
{
    int ret,p;
    if (dp[i][t]!=-1) return dp[i][t];
    if ( l[i]==0 )
    {
        if ( t==0 )
        {
            dp[i][t]=0;
        }
        else if (t==1)
        {
            dp[i][t]=1;
        }
        b[i][t]=true;
        return dp[i][t];
    }
    if (t==1)
    {
        ret=0;
        p=l[i];
        while ( p!=0 )
        {
            ret+=DP(p,0);
            if ( dp[p][0]==false ) b[i][1]=false;
            p=r[p];
        }
        dp[i][t]=ret+1;
        return dp[i][t];
    }
    else
    {
        ret=0;
        p=l[i];
        while ( p!=0 )
        {
            ret+=max(DP(p,0),DP(p,1));
            if ( dp[p][0]==dp[p][1] ) b[i][0]=false;
            if ( dp[p][0]>dp[p][1] && b[p][0]==false ) b[i][0]=false;
            if ( dp[p][1]>dp[p][0] && b[p][1]==false ) b[i][0]=false;
            p=r[p];
        }
        dp[i][t]=ret;
        return dp[i][t];
    }
}

int main()
{
    while (cin>>n)
    {
        if (n==0) break;
        memset(dp,-1,sizeof(dp));
        memset(r,0,sizeof(r));
        memset(l,0,sizeof(l));
        memset(f,0,sizeof(f));
        memset(b,0,sizeof(b));
        mp.clear();
        int edge=1;
        cin>>stra;
        mp[stra]=edge;
        f[edge]=0;
        for (int i=1; i<n; i++)
        {
            cin>>stra>>strb;
            if ( mp[stra]==0 )
            {
                edge++;
                mp[stra]=edge;
            }
            if ( mp[strb]==0 )
            {
                edge++;
                mp[strb]=edge;
            }
            f[mp[stra]]=mp[strb];
        }
        //建树
        for (int i=2; i<=n; i++)
        {
            if ( l[f[i]]==0 )//若父节点无左子树
            {
                l[f[i]]=i;
            }
            else
            {
                int p=l[f[i]];
                while ( r[p]!=0 )
                {
                    p=r[p];
                }
                r[p]=i;
            }
        }
        //建树完毕
        for (int i=0;i<=n;i++) b[i][0]=b[i][1]=true;
        int ans=max(DP(1,1),DP(1,0));
        cout<<ans<<" ";
        if (dp[1][1]==dp[1][0]) cout<<"No"<<endl;
        else if (dp[1][1]>dp[1][0]&&b[1][1]==false) cout<<"No"<<endl;
        else if (dp[1][0]>dp[1][1]&&b[1][0]==false) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
*/


#include <iostream>
#include <map>
#include <cstring>
#include <string>

using namespace std;

map<string,int>mp;//记录节点名字与编号的对应关系
int n;//节点数
int r[222]= {0};
int l[222]= {0}; //节点i，j的左右子树（用二叉树表示树，左子树是子节点，右子树为兄弟节点）
int f[222]= {0}; //节点i的父节点
int dp[222][2];
int b[222][2];
string stra,strb;

int one(int i,int t)
{
    if (b[i][t]!=-1) return b[i][t];
    if (l[i]==0)
    {
        b[i][0]=1;
        b[i][1]=1;
        return b[i][t];
    }
    int p=l[i];
    int ret=1;
    if (t==1)
    {
        while (p!=0)
        {
            if (one(p,0)==0)
            {
                ret=0;
            }
            p=r[p];
        }
        b[i][t]=ret;
        return b[i][t];
    }
    else
    {
        while (p!=0)
        {
            if (dp[p][0]>dp[p][1]&&one(p,0)==0)
            {
                ret=0;
            }
            if (dp[p][1]>dp[p][0]&&one(p,1)==0)
            {
                ret=0;
            }
            if (dp[p][1]==dp[p][0])
            {
                ret=0;
            }
            p=r[p];
        }
        b[i][t]=ret;
        return b[i][t];
    }
}

int DP(int i,int t)
{
    int ret,p;
    if (dp[i][t]!=-1) return dp[i][t];
    if ( l[i]==0 )
    {
        if ( t==0 )
        {
            dp[i][t]=0;
        }
        else if (t==1)
        {
            dp[i][t]=1;
        }
        return dp[i][t];
    }
    if (t==1)
    {
        ret=0;
        p=l[i];
        while ( p!=0 )
        {
            ret+=DP(p,0);
            p=r[p];
        }
        dp[i][t]=ret+1;
        return dp[i][t];
    }
    else
    {
        ret=0;
        p=l[i];
        while ( p!=0 )
        {
            ret+=max(DP(p,0),DP(p,1));
            p=r[p];
        }
        dp[i][t]=ret;
        return dp[i][t];
    }
}

int main()
{
    while (cin>>n)
    {
        if (n==0) break;
        memset(dp,-1,sizeof(dp));
        memset(r,0,sizeof(r));
        memset(l,0,sizeof(l));
        memset(f,0,sizeof(f));
        memset(b,-1,sizeof(b));
        mp.clear();
        int edge=1;
        cin>>stra;
        mp[stra]=edge;
        f[edge]=0;
        for (int i=1; i<n; i++)
        {
            cin>>stra>>strb;
            if ( mp[stra]==0 )
            {
                edge++;
                mp[stra]=edge;
            }
            if ( mp[strb]==0 )
            {
                edge++;
                mp[strb]=edge;
            }
            f[mp[stra]]=mp[strb];
        }
        //建树
        for (int i=2; i<=n; i++)
        {
            if ( l[f[i]]==0 )//若父节点无左子树
            {
                l[f[i]]=i;
            }
            else
            {
                int p=l[f[i]];
                while ( r[p]!=0 )
                {
                    p=r[p];
                }
                r[p]=i;
            }
        }
        //建树完毕
        int ans=max(DP(1,1),DP(1,0));
        cout<<ans<<" ";
        if ( dp[1][1]==dp[1][0] ) cout<<"No"<<endl;
        else if ( dp[1][0]>dp[1][1]&&one(1,0)==0 ) cout<<"No"<<endl;
        else if ( dp[1][1]>dp[1][0]&&one(1,1)==0 ) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}


