#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MM=200005;
int next[MM],extand[MM];
char T[MM],P[MM];

void GetNext(const char *P){
    int len=strlen(P),a=0;
    next[0]=len;
    while(a<len-1 && P[a]==P[a+1]) a++;
    next[1]=a;
    a=1;
    for(int k=2;k<len;k++){
        int p=a+next[a]-1,L=next[k-a];
        if( (k-1)+L >= p){
            int j = (p-k+1)>0 ? (p-k+1) : 0;
            while(k+j<len && P[k+j]==P[j]) j++;
            next[k]=j;
            a=k;
        }
        else
            next[k]=L;
    }
}
void GetExtand(const char *T,const char *P){
    GetNext(P);
    int slen=strlen(T),tlen=strlen(P),a=0;
    int MinLen = slen < tlen ? slen : tlen;
    while(a<MinLen && T[a]==P[a]) a++;
    extand[0]=a;
    a=0;
    for(int k=1;k<slen;k++){
        int p=a+extand[a]-1, L=next[k-a];
        if( (k-1)+L >= p){
            int j= (p-k+1) > 0 ? (p-k+1) : 0;
            while(k+j<slen && j<tlen && T[k+j]==P[j]) j++;
            extand[k]=j;
            a=k;
        }
        else
            extand[k]=L;
    }
}

int f[MM];
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
    int cas;
    int Cas=0;
    scanf("%d",&cas);
    while(cas--){
        scanf("%s",P);
        strcpy(T,P);
        strcat(T,P);
        GetExtand(T,P);
        int n=strlen(P);
        int cnt1=0,cnt2=0,cnt3=0;
        for (int i=0;i<n;i++){
            if (extand[i]>=n) cnt2++;
            else if (T[i+extand[i]]<P[extand[i]]) cnt1++;
            else cnt3++;
        }
        getFail(P,f);
        int tol=1;
        if (n%(n-f[n])==0) tol=n/(n-f[n]);
        printf("Case %d: %d %d %d\n",++Cas,cnt1/tol,cnt2/tol,cnt3/tol);
        for (int i=0;i<n;i++){
            cerr<<extand[i]<<" ";
        }
        cerr<<endl;
    }
    return 0;
}

