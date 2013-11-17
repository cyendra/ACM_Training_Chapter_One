
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

int f[20][10][10][10][10];
int sum[10][10];
int s[10][10][10][10];
int a[10][10];
int N;
int tmp;
double ans;

int main()
{
    while (cin>>N)
    {
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        memset(f,-1,sizeof(f));
        for (int i=1; i<=8; i++)
        {
            tmp=0;
            for (int j=1; j<=8; j++)
            {
                cin>>a[i][j];
                tmp+=a[i][j];
                sum[i][j]=sum[i-1][j]+tmp;
            }
        }
        for (int x1=1; x1<=8; x1++)
        {
            for (int y1=1; y1<=8; y1++)
            {
                for (int x2=x1; x2<=8; x2++)
                {
                    for (int y2=y1; y2<=8; y2++)
                    {
                        s[x1][y1][x2][y2]=sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
                        s[x1][y1][x2][y2]*=s[x1][y1][x2][y2];
                        f[0][x1][y1][x2][y2]=s[x1][y1][x2][y2];
                    }
                }
            }
        }
        for (int k = 1; k < N; ++k)   // 枚举切割了多少次
        {
            for (int x2 = 1; x2 <= 8; ++x2)
                for (int y2 = 1; y2 <= 8; ++y2)
                    for (int x1 = 1; x1 <= x2; ++x1)
                        for (int y1 = 1; y1 <= y2; ++y1)   // 枚举合法的四个坐标
                        {
                            // 以下为横向切割
                            int Min = 0x7fffffff, t;
                            for (int a = y1+1; a <= y2; ++a)
                            {
                                t = min(f[k-1][x1][a][x2][y2]+s[x1][y1][x2][a-1], f[k-1][x1][y1][x2][a-1]+s[x1][a][x2][y2]);
                                Min = min(Min, t);
                            }
                            // 以下为纵向切割
                            for (int a = x1+1; a <= x2; ++a)
                            {
                                t = min(f[k-1][a][y1][x2][y2]+s[x1][y1][a-1][y2], f[k-1][x1][y1][a-1][y2]+s[a][y1][x2][y2]);
                                Min = min(Min, t);
                            }
                            if (Min != 0x7fffffff)
                                f[k][x1][y1][x2][y2] = Min;
                        }
        }
        ans=f[N-1][1][1][8][8];
        ans=sqrt(double(N*ans-s[1][1][8][8])/(N*N));
        cout<<fixed;
        cout<<setprecision(3);
        cout<<ans<<endl;
    }
    return 0;
}
