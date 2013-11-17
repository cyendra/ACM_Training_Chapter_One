#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define Display_1(A, n, m) {                    \
    REP_1(i, n){                                \
        REP_1(j, m) cout << A[i][j] << " ";     \
        cout << endl;                           \
    }                                           \
}

const int INF=0x3f3f3f3f;//无穷大
const int maxm=41111;//边的最大数量，为原图的两倍
const int maxn=111;//点的最大数量
const int maxk=20;
int A,B,M,L,K;
int n;
int a[maxn][maxn];
int f[maxn][maxn];
bool v[maxn][maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d%d%d%d",&A,&B,&M,&L,&K);
        //init()
        n=A+B;
        memset(a,0x3f,sizeof(a));
        memset(f,0,sizeof(f));
        memset(v,0,sizeof(v));
        //for (int i=1;i<=n;i++) a[i][i]=0;
        //input()
        for (int i=1;i<=M;i++){
            int x,y,t;
            scanf("%d%d%d",&x,&y,&t);
            a[x][y]=a[y][x]=t;
            if (t<=L) v[x][y]=true;
        }
        //floyd
        for (int k=1;k<=n;k++){
            for (int i=1;i<=n;i++){
                for (int j=1;j<=n;j++){
                    if (a[i][k]+a[k][j]<a[i][j]){
                        a[i][j]=a[i][k]+a[k][j];
                        if (k<=A&&a[i][j]<=L) v[i][j]=v[j][i]=true;

                    }
                }
            }
        }
        //Display_1(a,n,n);
        //DP()
        for (int i=1;i<=n;i++) f[i][0]=a[1][i];
        for (int i=0;i<=K;i++) f[1][i]=0;
        for (int i=2;i<=n;i++){
            for (int k=1;k<=K;k++){
                int Min=INF;
                for (int j=1;j<i;j++){
                    if (v[j][i]){
                        Min=min(Min,f[j][k-1]);
                    }
                    Min=min(Min,f[j][k]+a[j][i]);
                }
                f[i][k]=Min;
            }
        }
        printf("%d\n",f[n][K]);
    }
    return 0;
}

