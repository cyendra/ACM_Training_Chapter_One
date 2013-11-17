#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

const int maxn=1111111;
char P[maxn];
char T[maxn];
int f[maxn];
int ans=0;
void getFail(char P[],int f[]){
    int i=0,j=-1;
    int len=strlen(P);
    f[0]=-1;
    while (i<len){
        if (j==-1||P[i]==P[j]){
            i++,j++;
            f[i]=j;
        }
        else{
            j=f[j];
        }
    }
}

void KMP(char T[],char P[],int f[]){
    int i=0,j=0;
    int n=strlen(T);
    int m=strlen(P);
    getFail(P,f);
    while(i<n){
        if(j==-1||T[i]==P[j]){
            i++,j++;
        }
        else{
            j=f[j];
        }
        if(j==m){
            // TO DO:
            ans++;
            //j=f[j];
            j=0;
        }
    }
}
int dp[maxn];

int main()
{
    int cas;
    int n;
    scanf("%d",&cas);
    while (cas--){
        scanf("%d",&n);
        scanf("%s",P);
        getFail(P,f);
        memset(dp,0,sizeof(dp));
        int ans=0;
        for (int i=1;i<=n;i++){
            dp[i]=dp[f[i]]+1;
            ans=(ans+dp[i])%10007;
        }
        printf("%d\n",ans);
    }
    return 0;
}
