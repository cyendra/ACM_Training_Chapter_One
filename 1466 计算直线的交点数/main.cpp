#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int f[21][500];
    int n;
    memset(f,0,sizeof(f));
    f[2][0]=1;
    f[2][1]=1;
    f[3][0]=1;
    f[3][2]=1;
    f[3][3]=1;
    for (int i=4;i<=20;i++)
    {
        f[i][0]=1;
        for (int j=2;j<i;j++)
        {
            for (int k=0;k<500;k++)
            {
                if ( f[j][k]==1 )
                {
                    f[i][j*(i-j)+k]=1;
                }
            }
        }
    }
    while (cin>>n)
    {
        cout << 0;
        for (int i=1;i<500;i++)
        {
            if (f[n][i]==1)
            {
                cout << ' ' << i;
            }
        }
        cout << endl;
    }
    return 0;
}
