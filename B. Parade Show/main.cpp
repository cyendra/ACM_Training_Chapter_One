#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn=211111;
int f[maxn];
char P[maxn],T[maxn];
int ans=0;
void getfail(char* P,int *f)
{
    int i=0,j=-1;
    f[0]=-1;
    int m=strlen(P);
    while(i<m)
    {
        if(j==-1||P[i]==P[j])
        {
            i++; j++;
            if(P[i]!=P[j])
                f[i]=j;
            else
                f[i]=f[j];
        }
        else j=f[j];
    }
}
//void getfail(char* P,int *f)
//{
//    int m=strlen(P);
//    f[0]=f[1]=0;
//    for (int i=1;i<m;i++)
//    {
//        int j=f[i];
//        while (j&&P[i]!=P[j]) j=f[j];
//        f[i+1]=(P[i]==P[j])?j+1:0;
//    }
//}

void find(char* T,char* P,int* f)
{
    int n=strlen(T),m=strlen(P);
    getfail(P,f);
    int j=0;
    int i=0;
    while (i<n)
    {
        //while (j&&P[j]!=T[i]) j=f[j];
        //if (P[j]==T[i]) j++;
        if(j==-1||T[i]==P[j]){
            i++;j++;
        }
        else{
            j=f[j];
        }
        if (j>=m){
            //printf("%d\n",i-m+1);
            ans++;
            j=0;
            i++;
           // printf("%d\n",i-m+1);
        }
    }
}

int main()
{
    int n,m,k;
    int a[maxn];
    int b[maxn];
    while (~scanf("%d%d%d",&n,&m,&k)){
        memset(T,0,sizeof(T));
        memset(P,0,sizeof(P));
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        for (int i=0;i<m;i++) scanf("%d",&b[i]);
        if (m==1){
            printf("%d\n",n);
            continue;
        }
        for (int i=0;i<n-1;i++){
            if (a[i]<a[i+1]) T[i]='1';
            if (a[i]>a[i+1]) T[i]='2';
            if (a[i]==a[i+1]) T[i]='0';
        }
        for (int i=0;i<m-1;i++){
            if (b[i]<b[i+1]) P[i]='1';
            if (b[i]>b[i+1]) P[i]='2';
            if (b[i]==b[i+1]) P[i]='0';
        }
        a[n-1]=0;
        b[m-1]=0;
        //cout<<T<<endl;

        ans=0;
        find(T,P,f);
        printf("%d\n",ans);
    }
    return 0;
}
