#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAXN=16384;
const int MOD=1000000007;
char s[4][MAXN];
int f[MAXN][8];
int n,sx,sy;

void input(){
    cin>>n;
    for (int i=1;i<=3;i++){
        cin>>(s[i]+1);
    }
}
void findDot(){
    for (int i=1;i<=3;i++){
        for (int j=1;j<=n;j++){
            if (s[i][j]=='O'){
                sx=i;
                sy=j;
                return;
            }
        }
    }
}
int getBit(int j){
    int res=0;
    for (int i=1;i<=3;i++){
        if (s[i][j]!='.') res|=(1<<(3-i));
    }
    return res;
}
int getDP(int i,int k){
    if (k==0) return f[i-1][7];// 000 <- 111
    if (k==1) return f[i-1][6];// 001 <- 110
    if (k==2) return f[i-1][5];// 010 <- 101
    if (k==3) return (f[i-1][4]+f[i-1][7])%MOD;// 011 <- 100,111
    if (k==4) return f[i-1][3];// 100 <- 011
    if (k==5) return f[i-1][2];// 101 <- 010
    if (k==6) return (f[i-1][1]+f[i-1][7])%MOD;// 110 <- 001,111
    if (k==7) return ((f[i-1][0]+f[i-1][3])%MOD+f[i-1][6])%MOD;// 111 <- 000,011,110
    return -1;
}
int solve(){
    memset(f,0,sizeof(f));
    f[0][7]=1;
    for (int i=1;i<=n;i++){
        int k=getBit(i);
        for (int j=k;j<=7;j++){
            if ((j&k)==k){
                f[i][j]=getDP(i,j&(~k));
            }
        }
    }
    return f[n][7];
}

int special(){
    int ans=0;
    bool lb=false,rb=false;
    if (sy-2>=1){
        if (s[2][sy-1]=='.'&&s[2][sy-2]=='.'){
            s[2][sy-1]=s[2][sy-2]='X';
            ans+=solve();
            s[2][sy-1]=s[2][sy-2]='.';
            lb=true;
        }
    }
    if (sy+2<=n){
        if (s[2][sy+1]=='.'&&s[2][sy+2]=='.'){
            s[2][sy+1]=s[2][sy+2]='X';
            ans+=solve();
            s[2][sy+1]=s[2][sy+2]='.';
            rb=true;
        }
    }
    if (lb&&rb){
        s[2][sy-1]=s[2][sy-2]='X';
        s[2][sy+1]=s[2][sy+2]='X';
        ans-=solve();
        s[2][sy-1]=s[2][sy-2]='.';
        s[2][sy+1]=s[2][sy+2]='.';
    }
    while (ans<0) ans+=MOD;
    ans%=MOD;
    return ans;
}

int main()
{
    input();
    findDot();
    //cerr<<solve()<<endl;
    if (sx==2) cout<<special()<<endl;
    else cout<<solve()<<endl;
    return 0;
}
