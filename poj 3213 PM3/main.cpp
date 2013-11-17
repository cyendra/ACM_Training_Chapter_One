#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;
const int maxn=1011;

int N,P,M;
int A[maxn][maxn],B[maxn][maxn];
LL C[maxn][maxn];
LL sumB[maxn],sumC[maxn];
int wr,wl;
LL rt;
int main()
{
    while (~scanf("%d%d%d",&N,&P,&M)){
        for (int i=1;i<=N;i++){
            for (int j=1;j<=P;j++){
                scanf("%d",&A[i][j]);
            }
        }
        memset(sumB,0,sizeof(sumB));
        for (int i=1;i<=P;i++){
            for (int j=1;j<=M;j++){
                scanf("%d",&B[i][j]);
                sumB[i]+=B[i][j];
            }
        }
        memset(sumC,0,sizeof(sumC));
        for (int i=1;i<=N;i++){
            for (int j=1;j<=M;j++){
                scanf("%I64d",&C[i][j]);
                sumC[i]+=C[i][j];
            }
        }
        //puts("Done.");
        wr=-1;
        for (int i=1;i<=N;i++){
            LL sum=0;
            for (int j=1;j<=P;j++){
                sum+=A[i][j]*sumB[j];
            }
            if (sum!=sumC[i]){
                wr=i;
                break;
            }
        }
        if (wr==-1) puts("Yes");
        else{
            puts("No");
            for (int i=1;i<=M;i++){
                LL sum=0;
                for (int j=1;j<=P;j++){
                    sum+=A[wr][j]*B[j][i];
                }
                if (sum!=C[wr][i]){
                    wl=i;
                    rt=sum;
                    break;
                }
            }
            printf("%d %d\n",wr,wl);
            printf("%I64d\n",rt);
        }
    }
    return 0;
}
