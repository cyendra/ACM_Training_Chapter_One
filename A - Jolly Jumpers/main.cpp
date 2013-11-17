#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=3333;
bool v[maxn];
int a[maxn];
int n;
int sum;

int main()
{
    while (cin>>n)
    {
        sum=0;
        memset(v,0,sizeof(v));
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=2;i<=n;i++)
        {
            int t=abs(a[i]-a[i-1]);
            if (!v[t]&&t>=1&&t<=n-1)
            {
                v[t]=true;
                sum++;
            }
        }
        if (sum==n-1) puts("Jolly");
        else puts("Not jolly");
    }
    return 0;
}
