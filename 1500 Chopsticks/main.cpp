#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[5001];
int f[1010][5010];
bool cmp(int a,int b);

bool cmp(int a,int b)
{
    return ( a>b );
}

int main()
{
    int T,K,N;
    cin >> T;
    for (int loop=0;loop<T;loop++)
    {
        cin >> K >> N;
        for (int i=1;i<=N;i++)
        {
            cin >> a[i];
        }
        K=K+8;
        sort(a+1,a+N+1,cmp);
        memset(f,0,sizeof(f));
        for (int i=1;i<=K;i++)
        {
            f[i][i*3]=f[i-1][i*3-2]+(a[i*3]-a[i*3-1])*(a[i*3]-a[i*3-1]);
            for (int j=i*3+1;j<=N;j++)
            {
                f[i][j]=min( f[i][j-1] , f[i-1][j-2]+(a[j]-a[j-1])*(a[j]-a[j-1]) );
            }
        }
        cout << f[K][N] << endl;
    }
    return 0;
}
