#include <iostream>
#include <cstring>

using namespace std;

int a[40][40];
__int64 f[40][40];
char str[40][40];
int n;

int main()
{
    while ( cin >> n  )
    {
        if (n==-1) break;
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            cin >> str[i];
        }

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                a[i][j]=str[i][j-1]-'0';
            }
        }
        f[1][1]=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if ( a[i][j]==0 ) continue;
                if ( i+a[i][j]<=n ) f[i+a[i][j]][j]+=f[i][j];
                if ( j+a[i][j]<=n ) f[i][j+a[i][j]]+=f[i][j];
            }
        }
        /*
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                cout << f[i][j];
            }
            cout << endl;
        }
        */
        cout << f[n][n] << endl;
    }
    return 0;
}
