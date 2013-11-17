#include <iostream>
#include <cstring>
#include <stack>

using namespace std;
typedef long long LL;
const int MOD=1000000007;
const int maxn=800;
stack<int>stk;
char s[maxn];
int match[maxn];
LL f[maxn][maxn][3][3];
LL ans;
bool check(int i,int j){
    if (i==0||j==0||i!=j) return true;
    return false;
}
LL dp(int l,int r,int cl,int cr){
    LL &res=f[l][r][cl][cr];
    if (res!=-1) return res;
    res=0;
    if (match[l]==r){
        if ((cl==0)^(cr==0)){
            if (l+1==r) return res=1;
            for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
            if (check(cl,i)&&check(j,cr)){
                res=(res+dp(l+1,r-1,i,j))%MOD;
            }
        }
    }
    else{
        for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
        if (check(i,j)){
            res=(res+dp(l,match[l],cl,i)*dp(match[l]+1,r,j,cr))%MOD;
        }
    }
    return res;
}
int main()
{
    while (cin>>(s+1)){
        ans=0;
        while (!stk.empty()) stk.pop();
        memset(match,0,sizeof(match));
        memset(f,-1,sizeof(f));
        int n=strlen(s+1);
        for (int i=1;i<=n;i++){
            if (s[i]=='(') stk.push(i);
            else{
                match[stk.top()]=i;
                stk.pop();
            }
        }
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                ans=(ans+dp(1,n,i,j))%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
