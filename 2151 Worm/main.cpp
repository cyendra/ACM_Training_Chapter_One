#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n,p,m,t;
    int f[200][200];
    while ( cin >> n >> p >> m >> t )
    {
        memset(f,0,sizeof(f));
        f[0][p]=1;
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (j>1)
                {
                    f[i][j]+=f[i-1][j-1];
                }
                if (j<n)
                {
                    f[i][j]+=f[i-1][j+1];
                }
            }
        }
        cout << f[m][t] << endl;
    }
    return 0;
}
