#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string a,b;
    int f[500][500];
    while (cin >> a >> b)
    {
        memset(f,0,sizeof(f));
        for (int i=1;i<=a.length();i++)
        {
            for (int j=1;j<=b.length();j++)
            {
                if (a[i-1]==b[j-1])
                {
                    f[i][j]=f[i-1][j-1]+1;
                }
                else
                {
                    f[i][j]=f[i-1][j];
                    if (f[i][j-1]>f[i][j])
                    {
                        f[i][j]=f[i][j-1];
                    }
                }
            }
        }
        cout << f[a.length()][b.length()] << endl;
    }
    return 0;
}
