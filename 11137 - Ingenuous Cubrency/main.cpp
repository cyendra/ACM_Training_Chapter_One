#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long a[33];
long long f[11111];
int n;

int main()
{
    for (int i=1;i<=21;i++)
    {
        a[i]=i*i*i;
    }
    while (~scanf("%d",&n))
    {
        memset(f,0,sizeof(f));
        f[0]=1;
        for (int i=1;i<=21;i++)
        {
            for (int j=0;j<=n-a[i];j++)
            {
                if (f[j]) f[j+a[i]]+=f[j];
            }
        }
        printf("%lld\n",f[n]);
    }
    return 0;
}

