#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int OO=1e9;

struct STR{
    int wt;
    int ms;
}a[11111];

bool cmp(STR a,STR b)
{
    return a.ms<b.ms;
}

int f[11111];
int maxi;


int main()
{
    int n=0;
    while (~scanf("%d%d",&a[n].wt,&a[n].ms))
    {
        if (a[n].wt>a[n].ms) continue;
        n++;
    }
    sort(a,a+n,cmp);
    for (int i=1;i<=n;i++) f[i]=OO;
    f[0]=0;
    maxi=0;
    for (int i=0;i<n;i++)
    {
        for (int j=maxi;j>=0;j--)
        {
            if (f[j]+a[i].wt<a[i].ms&&f[j]+a[i].wt<f[j+1])
            {
                f[j+1]=f[j]+a[i].wt;
                maxi=max(maxi,j+1);
            }
        }
    }
    printf("%d\n",maxi);
    return 0;
}
