#include <iostream>
#include <cstring>
#include <cstdio>



using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)
#define Display(A, n, m) {                      \
    REP(i, n){                                  \
        REP(j, m) cout << A[i][j] << " ";       \
        cout << endl;                           \
    }                                           \
}

const int INF=0x3f3f3f3f;
int a[111][111];
int lst[111];

int main()
{
    int n,m;
    while (~scanf("%d%d",&n,&m)){
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (i!=j) a[i][j]=INF;
                else a[i][j]=0;
        int t;
        for (int i=0;i<m;i++){
            scanf("%d",&t);
            for (int j=0;j<t;j++){
                scanf("%d",&lst[j]);
                lst[j]-=1;
            }
            for (int j=0;j<t;j++){
                for (int k=0;k<t;k++){
                    if (j!=k) a[ lst[j] ][ lst[k] ]=1;
                }
            }
        }
        //Display(a,n,n);

        for (int k=0;k<n;k++){
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    a[i][j]=min( a[i][j], a[i][k]+a[k][j] );
                }
            }
        }

        //Display(a,n,n);

        double ans=1e9;
        for (int i=0;i<n;i++){
            int sum=0;
            for (int j=0;j<n;j++){
                if (i!=j) sum+=a[i][j];
            }
            ans=min( ans, (double)sum/(double)(n-1) );
        }
        printf("%d\n",int(ans*100));
    }
    return 0;
}
