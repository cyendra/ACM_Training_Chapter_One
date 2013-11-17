#include <iostream>
#include <cstring>

using namespace std;

int f[40];
int n,m;

int main()
{
    while ( cin >> n >> m )
    {
        if (n==0&&m==0) break;
        memset(f,0,sizeof(f));
        f[1]=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=i+m&&j<=n;j++)
            {
                f[j]+=f[i];
            }
            //cout << "f[i]= " << f[i] << endl;
        }
        cout << f[n] << endl;
    }
    return 0;
}
