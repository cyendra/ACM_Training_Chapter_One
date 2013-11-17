#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long LL;
const int maxn=111;
LL f[maxn][11];
int bit[maxn];
int n;
LL dp(int p,int m,bool flag){
    if (p==0) return (m==0);
    if (flag&&f[p][m]!=-1) return f[p][m];
    int k=flag?9:bit[p];
    LL res=0;
    for (int i=0;i<=k;i++){
        res+=dp(p-1,(m+i)%10,flag||k!=i);
    }
    if (flag) f[p][m]=res;
    return res;
}

LL get(LL x){
    memset(f,-1,sizeof(f));
    if (x<0) return 0;
    n=0;
    while (x!=0){
        bit[++n]=x%10;
        x/=10;
    }
    return dp(n,0,0);
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
        LL x,y;
        scanf("%I64d%I64d",&x,&y);
        printf("Case #%d: %I64d\n",cas,get(y)-get(x-1));
    }
    return 0;
}

