#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

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

int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%s",P);
        int n=strlen(P);
        getFail(P,f);
        int x=n;
        bool flag=false;
        while (f[x]>(n/3)) x=f[x];
        while (f[x]>0){
            flag=false;
            for (int i=f[x]*2;i<=n-f[x];i++){
                if (f[i]==f[x]){
                    flag=true;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) printf("0\n");
        else printf("%d\n",f[x]);
    }
    return 0;
}
