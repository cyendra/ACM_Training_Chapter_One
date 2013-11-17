#include<cstdio>
#include<cstring>
#include<iostream>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define clr(f,z) memset(f,z,sizeof(f))
#define ll(x) (1<<x)
using namespace std;
const int mm=10;
const int mn=9*ll(8);
int bit[mm],low[mm];
int dp[mm][mn][mn];
int A,B,VA;
int F(int x)
{
    int ret=0;
    int z=0;
    while(x)
    {
        ret+=(x%10)*low[z];
        x/=10;
        z++;
    }
    return ret;
}
int DP(int pp,int st,int va,bool big)
{
    if(pp==0)return st<=VA;
    if(big&&dp[pp][st][va]!=-1)return dp[pp][st][va];
    int kn=big?9:bit[pp];
    int ret=0;
    FOR(i,0,kn)
    {
        ret+=DP(pp-1,st*2+i,va,big||kn!=i);
    }
    if(big)dp[pp][st][va]=ret;
    return ret;
}
int get(int a,int b)
{
    VA=F(a);//clr(dp,-1);
    //printf("va=%d\n",VA);
    int pos=0;
    while(b)
    {
        bit[++pos]=b%10;
        b/=10;
    }
    return DP(pos,0,VA,0);
}
int main()
{
    int cas;
    low[0]=1;
    FOR(i,1,16)low[i]=2*low[i-1];
    //cout<<mn*mn*mm<<endl;
    clr(dp,-1);
    while(~scanf("%d",&cas))
    {
        FOR(ca,1,cas)
        {
            scanf("%d%d",&A,&B);
            printf("Case #%d: ",ca);
            printf("%d\n",get(A,B));
        }
    }
}
