#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
int ans;
const int maxn=1111111;
char P[maxn];
char T[maxn];
int f[maxn];

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
            j=f[j];
        }
    }
}

int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas--){
        scanf("%s%s",P,T);
        ans=0;
        KMP(T,P,f);
        printf("%d\n",ans);
    }
    return 0;
}
