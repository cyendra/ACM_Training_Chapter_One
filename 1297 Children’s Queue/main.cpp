#include <iostream>
#include <cstring>
using namespace std;
int f[1001][1001];
void arrsum(int* a,int* b)
{
    if (b[0]>a[0])
    {
        a[0]=b[0];
    }
    for (int i=1;i<=a[0];i++)
    {
        a[i]=a[i]+b[i];
        if (a[i]>=10)
        {
            a[i+1]++;
            a[i]-=10;
            if (i+1>a[0])
            {
                a[0]=i+1;
            }
        }
    }
}

int main()
{
    int n;
    memset(f,0,sizeof(f));
    f[1][0]=f[2][0]=f[3][0]=f[4][0]=1;
    f[1][1]=1;
    f[2][1]=2;
    f[3][1]=4;
    f[4][1]=7;
    for (int i=5;i<=1000;i++)
    {
        arrsum(f[i],f[i-1]);
        arrsum(f[i],f[i-2]);
        arrsum(f[i],f[i-4]);
    }
    while (cin >> n)
    {
        for (int i=f[n][0];i>=1;i--)
        {
            cout << f[n][i];
        }
        cout <<endl;
    }
    return 0;
}
