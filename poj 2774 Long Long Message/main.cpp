/** head-file **/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>

/** define-for **/

#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define DWN(i, b, a) for (int i=int(b-1);i>=int(a);--i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define FOR_1(i, a, b) for (int i=int(a);i<=int(b);++i)
#define DWN_1(i, b, a) for (int i=int(b);i>=int(a);--i)
#define REP_N(i, n) for (i=0;i<int(n);++i)
#define FOR_N(i, a, b) for (i=int(a);i<int(b);++i)
#define DWN_N(i, b, a) for (i=int(b-1);i>=int(a);--i)
#define REP_1_N(i, n) for (i=1;i<=int(n);++i)
#define FOR_1_N(i, a, b) for (i=int(a);i<=int(b);++i)
#define DWN_1_N(i, b, a) for (i=int(b);i>=int(a);--i)

/** define-useful **/

#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) int(x.size())
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x
#define pb push_back
#define mp make_pair

/** test **/

#define Display(A, n, m) {                      \
    REP(i, n){                                  \
        REP(j, m) cout << A[i][j] << " ";       \
        cout << endl;                           \
    }                                           \
}

#define Display_1(A, n, m) {                    \
    REP_1(i, n){                                \
        REP_1(j, m) cout << A[i][j] << " ";     \
        cout << endl;                           \
    }                                           \
}

using namespace std;

/** typedef **/

typedef long long LL;

/** Add - On **/

const int direct4[4][2]={ {0,1},{1,0},{0,-1},{-1,0} };
const int direct8[8][2]={ {0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };
const int direct3[6][3]={ {1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1} };

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long INFF = 1LL << 60;
const double EPS = 1e-9;
const double OO = 1e15;
const double PI = acos(-1.0); //M_PI;

const int maxn=6e5+10;
/******************************************************************
**  后缀数组 Suffix Array
**  INIT：solver.call_fun(char* s);
**  CALL: solver.lcp(int i,int j); //后缀i与后缀j的最长公共前缀
**  SP_USE: solver.LCS(char *s1,char* s2); //最长公共字串
******************************************************************/
struct SuffixArray{
    int r[maxn];
    int sa[maxn],rank[maxn],height[maxn];
    int t[maxn],t2[maxn],c[maxn],n;
    int m;//模板长度
    void init(char* s){
        n=strlen(s);
        for (int i=0;i<n;i++) r[i]=int(s[i]);
        m=300;
    }
    int cmp(int *r,int a,int b,int l){
        return r[a]==r[b]&&r[a+l]==r[b+l];
    }
    /**
    字符要先转化为正整数
    待排序的字符串放在r[]数组中，从r[0]到r[n-1]，长度为n，且最大值小于m。
    所有的r[i]都大于0,r[n]无意义算法中置0
    函数结束后，结果放在sa[]数组中(名次从1..n)，从sa[1]到sa[n]。s[0]无意义
    **/
    void build_sa(){
        int i,k,p,*x=t,*y=t2;
        r[n++]=0;
        for (i=0;i<m;i++) c[i]=0;
        for (i=0;i<n;i++) c[x[i]=r[i]]++;
        for (i=1;i<m;i++) c[i]+=c[i-1];
        for (i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
        for (k=1,p=1;k<n;k*=2,m=p){
            for (p=0,i=n-k;i<n;i++) y[p++]=i;
            for (i=0;i<n;i++) if (sa[i]>=k) y[p++]=sa[i]-k;
            for (i=0;i<m;i++) c[i]=0;
            for (i=0;i<n;i++) c[x[y[i]]]++;
            for (i=1;i<m;i++) c[i]+=c[i-1];
            for (i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
            swap(x,y);
            p=1;
            x[sa[0]]=0;
            for (i=1;i<n;i++) x[sa[i]]=cmp(y,sa[i-1],sa[i],k)?p-1:p++;
        }
        n--;
    }
    /**
    height[2..n]:height[i]保存的是lcp(sa[i],sa[i-1])
    rank[0..n-1]:rank[i]保存的是原串中suffix[i]的名次
    **/
    void getHeight(){
        int i,j,k=0;
        for (i=1;i<=n;i++) rank[sa[i]]=i;
        for (i=0;i<n;i++){
            if (k) k--;
            j=sa[rank[i]-1];
            while (r[i+k]==r[j+k]) k++;
            height[rank[i]]=k;
        }
    }
    int d[maxn][20];
    //元素从1编号到n
    void RMQ_init(int A[],int n){
        for (int i=1;i<=n;i++) d[i][0]=A[i];
        for (int j=1;(1<<j)<=n;j++)
            for (int i=1;i+j-1<=n;i++)
                d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
    }
    int RMQ(int L,int R){
        int k=0;
        while ((1<<(k+1))<=R-L+1) k++;
        return min(d[L][k],d[R-(1<<k)+1][k]);
    }
    void LCP_init(){
        RMQ_init(height,n);
    }
    int lcp(int i,int j){
        if (rank[i]>rank[j]) swap(i,j);
        return RMQ(rank[i]+1,rank[j]);
    }
    void call_fun(char* s){
        init(s);//初始化后缀数组
        build_sa();//构造后缀数组sa
        getHeight();//计算height与rank
        LCP_init();//初始化RMQ
    }
    int LCS(char* s1,char* s2){
        int p,ans;
        int l=strlen(s1);
        p=l;
        s1[l]='$';
        s1[l+1]='\0';
        strcat(s1,s2);
        call_fun(s1);
        ans=0;
        for (int i=2;i<=n;i++)
            if ((sa[i-1]<p&&sa[i]>p)||(sa[i-1]>p&&sa[i]<p)) ans=max(ans,height[i]);
        return ans;
    }
}solver;

int main()
{
    char a[maxn],b[maxn];
    while (~scanf("%s%s",a,b)) printf("%d\n",solver.LCS(a,b));
    return 0;
}
