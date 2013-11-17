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
            j=f[j];
        }
    }
}

int main()
{
    int cas=0;
    int n;
    while (~scanf("%d",&n)){
        if (n==0) break;
        scanf("%s",P);
        getFail(P,f);
        //for (int i=0;i<=n;i++) cerr<<f[i]<<" ";cerr<<endl;
        //if (cas) puts("");
        printf("Test case #%d\n",++cas);
        for (int i=2;i<=n;i++){
            if (f[i]>0&&i%(i-f[i])==0){
                printf("%d %d\n",i,i/(i-f[i]));
            }
        }
        puts("");
    }
    return 0;
}
