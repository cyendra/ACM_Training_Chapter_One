#include <iostream>
#include <cstring>
using namespace std;

int f[210][2000];
void fib(int *a,int *b,int *c)
{
    a[0]=b[0];
    if ( c[0]>a[0] )
    {
        a[0]=c[0];
    }
    for (int i=1;i<=a[0];i++)
    {
        a[i]+=b[i]+c[i];
        a[i+1]+=a[i]/10;
        a[i]=a[i]%10;
    }
    if ( a[a[0]+1]>0)
    {
        a[0]+=1;
    }
}
int main()
{
    int n;
    memset(f,0,sizeof(f));
    f[0][0]=1;
    f[0][1]=1;
    f[1][0]=1;
    f[1][1]=1;
    for (int i=2;i<=200;i++)
    {
        fib(f[i],f[i-1],f[i-2]);
    }
    while (cin >> n)
    {
        for (int i=f[n][0];i>=1;i--)
        {
            cout << f[n][i];
        }
        cout << endl;
    }

    return 0;
}
