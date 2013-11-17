#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int OO=1e9;

int f[11111];
int n;
int a[5]={1,5,10,25,50};

int main()
{
    while (~scanf("%d",&n))
    {
        memset(f,0,sizeof(f));
        f[0]=1;
        for (int i=0;i<5;i++)
        {
            for (int j=0;j<=n-a[i];j++)
            {
                if (f[j]) f[j+a[i]]+=f[j];
            }
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
