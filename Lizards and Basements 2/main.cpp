/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define maxn 1000

using namespace std;

int  n, a, b;
int h[maxn];
int cur[maxn];
int now[maxn];
int ans = maxn;

bool dfs(int who, int num)
{
    int i, j;
    if(num >= ans) return false;
    if(who == n)
    {
        if(h[n] >= 0) return false;
        ans = num;
        for(i = 2; i < n; i++)
            now[i] = cur[i];
        return true;
    }
    else
    {
        int begin = ((h[who-1]+b-1)/b);
        if(begin < 0) begin = 0;
        for(j = begin; j <= 16; j++)
            if(h[who -1] - b * j >= 0) continue;
            else
            {
                if(j + num >= ans) break;
                //--------------------------------------------------
                if(who == n - 1 && h[who+1] - b*j >= 0) continue;
                cur[who] = j;
                h[who-1] -= b * j;
                h[who] -= a * j;
                h[who+1] -= b * j;

                bool ok = dfs(who+1,num+j);
                h[who-1] += b * j;
                h[who] += a * j;
                h[who+1] += b * j;
                //----------------------------------------
                if(h[who-1] - b*j < 0 && h[who+1] - b*j < 0 && h[who] - a*j < 0) break;
            }
    }
    return false;
}

int main()
{
    int i, j, sum = 0;
    scanf("%d%d%d",&n,&a,&b);
    for(i = 1; i <= n; i++)
        scanf("%d",&h[i]);
    dfs(2,0);
    printf("%d\n",ans);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= now[i]; j++)
        {
            sum++;
            if(sum  == ans) printf("%d\n",i);
            else printf("%d ",i);
        }
    return 0;
}
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#define OO 999999
using namespace std;

int n,a,b,maxh,tmp,tp,kill;
int h[30];
int f[30][30][30][30];
int p[30][30][30][30];
int d1,d2,d3;
int th1,th2,th3;
int ph1,ph2,ph3;
int main()
{
    //input
    maxh=0;
    scanf("%d%d%d",&n,&a,&b);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
        h[i]+=1;
        if ( h[i]>maxh ) maxh=h[i];
    }
    h[n+1]=0;
    //初始化数组f为OO
    for (int i=0;i<30;i++)
    {
        for (int j=0;j<30;j++)
        {
            for (int k=0;k<30;k++)
            {
                for (int l=0;l<30;l++)
                {
                    f[i][j][k][l]=OO;
                }
            }
        }
    }
    //起始状态
    f[2][h[1]][h[2]][h[3]]=0;
    //DP
    for (int i= 2;i<n;i++)
        for (int hp1=h[i-1];hp1>=0;hp1--)
            for (int hp2=h[i];hp2>=0;hp2--)
                for ( int hp3=h[i+1];hp3>=0;hp3--)
                    if (f[i][hp1][hp2][hp3]!=OO)
                    {
                        d1=max(0,hp1-b);
                        d2=max(0,hp2-a);
                        d3=max(0,hp3-b);
                        if (f[i][hp1][hp2][hp3]+1<f[i][d1][d2][d3])
                        {
                            f[i][d1][d2][d3]=f[i][hp1][hp2][hp3]+1;
                            p[i][d1][d2][d3]=i*30*30*30+hp1*30*30+hp2*30+hp3;
                        }
                        if (d1==0)
                        {
                            if (f[i][hp1][hp2][hp3]+1<f[i+1][d2][d3][h[i+2]])
                            {
                                f[i+1][d2][d3][h[i+2]]=f[i][hp1][hp2][hp3]+1;
                                p[i+1][d2][d3][h[i+2]]=i*30*30*30+hp1*30*30+hp2*30+hp3;
                            }
                        }
                        if (hp1==0)
                        {
                            if (f[i][hp1][hp2][hp3]<f[i+1][hp2][hp3][h[i+2]])
                            {
                                f[i+1][hp2][hp3][h[i+2]]=f[i][hp1][hp2][hp3];
                                p[i+1][hp2][hp3][h[i+2]]=p[i][hp1][hp2][hp3];
                            }
                        }
                    }
    //output
    printf("%d\n",f[n][0][0][0]);
    ph1=0;
    ph2=0;
    ph3=0;
    tmp=n;
    while ( !(ph1==h[1]&&ph2==h[2]&&ph3==h[3]&&tmp==2) )
    {
        tp=p[tmp][ph1][ph2][ph3];
        th1=tp/30/30%30;
        th2=tp/30%30;
        th3=tp%30;
        kill=tp/30/30/30;
        printf("%d \n",kill);
        ph1=th1;
        ph2=th2;
        ph3=th3;
        tmp=kill;
    }
    printf("\n");
    return 0;
}
