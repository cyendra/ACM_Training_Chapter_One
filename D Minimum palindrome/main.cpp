/*
#include <string>
#include<cstring>
#include<iostream>
#include<cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define clr(f,z) memset(f,z,sizeof(f))
#define ll(x) (1<<x)
using namespace std;

const int msize=1e4+9;

string as;
int mx;
char cs[msize];
string bg;

class SUFFIX_ARRAY
{
public:
    int rank[msize],h[msize],c[msize],sa[msize];
    bool cmp(int*r,int i,int k)
    {
        return r[ sa[i] ]==r[ sa[i-1] ]&&r[ sa[i]+k ]==r[ sa[i-1]+k ];
    }
    void build_SA(char*s,int n,int m)
    {
        int*wx=h,*wy=rank;
        FOR(i,0,m-1)c[i]=0;
        FOR(i,0,n-1)++c[ wx[i]=s[i] ];
        FOR(i,1,m-1)c[i]+=c[i-1];
        for(int i=n-1; i>=0; --i)sa[ --c[ wx[i] ] ]=i;
        for(int k=1; k<=n; k<<=1)
        {
            int p=0;
            FOR(i,n-k,n-1)wy[p++]=i;
            FOR(i,0,n-1)if(sa[i]>=k)wy[p++]=sa[i]-k;
            FOR(i,0,m-1)c[i]=0;
            FOR(i,0,n-1)++c[ wx[ wy[i] ] ];
            FOR(i,1,m-1)c[i]+=c[i-1];
            for(int i=n-1; i>=0; --i)sa[ --c[ wx[ wy[i] ] ] ]=wy[i];
            swap(wx,wy);
            p=1;
            wx[ sa[0] ]=0;
            FOR(i,1,n-1)wx[ sa[i] ]=cmp(wy,i,k)?p-1:p++;
            if(p>=n)break;
            m=p;
        }
    }
    void get_H(char*s,int n)
    {
        int k=0;
        FOR(i,0,n)rank[ sa[i] ]=i;
        FOR(i,0,n-1)
        {
            if(k)--k;
            int j=sa[ rank[i]-1 ];
            while(s[i+k]==s[j+k])++k;
            h[ rank[i] ]=k;
        }
    }
    int bit[msize],rmq[msize][32];
    void initRMQ(int n)
    {
        bit[0]=-1;
        FOR(i,1,n)bit[i]=(i&(i-1))==0?bit[i-1]+1:bit[i-1];
        FOR(i,1,n)rmq[i][0]=h[i];
        FOR(i,1,bit[n])
        for(int j=1; j+ll(i)-1<=n; ++j)
            rmq[j][i]=min(rmq[j][i-1],rmq[j+ll(i-1)][i-1]);
    }
    int LCP(int l,int r)
    {
        l=rank[l];
        r=rank[r];
        if(l>r)swap(l,r);
        ++l;
        int t=bit[r-l+1];
        r-=ll(t)-1;
        return min(rmq[l][t],rmq[r][t]);
    }
    void getans(int len,int xlen,char*s)
    {
        int ans=0,z,id;
        FOR(i,0,len)
        {
            z=LCP(i,xlen-i);
            if(ans<z+z)//odd
                ans=z+z,id=i-z;
            z=LCP(i,xlen-i-1);
            if(ans<z+z-1)
                ans=z+z-1,id=i-z+1;
        }
        s[id+ans]=0;
        if (ans<mx){
            bg=cs;
            as=s+id;
            mx=ans;
        }
        //printf("×Ó´®£º%s\n",s+id);
        //printf("len = %d\n",ans);
    }
};
SUFFIX_ARRAY ty;
char s[msize];

void fun(char *s){
    int len=strlen(s);
    int xlen=len;
    s[xlen++]=1;
    for(int i=len-1; i>=0; --i)
        s[xlen++]=s[i];
    s[xlen]=0;
    ty.build_SA(s,xlen+1,128);//puts("A");
    ty.get_H(s,xlen);//puts("B");
    ty.initRMQ(xlen);//puts("+++");
    ty.getans(len,xlen,s);
}

void dfs(int p,int m,int n){
    if (p==n){
        cs[p]=0;
        strcpy(s,cs);
        //printf("Ô­´®£º%s\n",cs);
        fun(s);
        return;
    }
    for (int j=0;j<m;j++){
        cs[p]='a'+j;
        dfs(p+1,m,n);
    }


}



int main()
{
    int n,m=2;
    while(~scanf("%d",&n))
    {
        mx=0x3f3f3f;
        dfs(0,m,n);
        cout<<bg<<endl;
        //cout<<as<<endl;
        cout<<mx<<endl;
    }
}
*/

#include <iostream>
#include <cstring>

using namespace std;

const int maxn=111111;

char s[maxn];
int n,m;

char bit[12][12]={ "","a","ab","aab","aabb","aaaba","aaabab","aaababb","aaababbb","aaaababba","aaaababbaa","aaaababbaaa" };
char cycle[11]="babbaa\0";
int main()
{
    int T;
    cin>>T;
    for (int cas=1;cas<=T;cas++){
        cin>>m>>n;
        if (m==1){
            for (int i=0;i<n;i++){
                s[i]='a';
            }
            s[n]=0;
            cout<<"Case #"<<cas<<": "<<s<<endl;
        }
        else if (m>=3){
            for (int i=0;i<n;i++){
                s[i]='a'+i%3;
            }
            s[n]=0;
            cout<<"Case #"<<cas<<": "<<s<<endl;
        }
        else if (m==2){
            if (n<=10){
                cout<<"Case #"<<cas<<": "<<bit[n]<<endl;
            }
            else{
                cout<<"Case #"<<cas<<": ";
                cout<<"aaaa";
                for (int i=0;i<(n-4)/6;i++){
                    cout<<cycle;
                }
                if ((n-4)%6==1){
                    cout<<'a';
                }
                else if ((n-4)%6==2){
                    cout<<"aa";
                }
                else{
                    for (int i=0;i<(n-4)%6;i++){
                        cout<<cycle[i];
                    }
                }
                cout<<endl;
            }

        }
    }
    return 0;
}

