#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int m,n,tmp,dt;
    double ans;
    while (scanf("%d%d",&n,&m))
    {
        if ((n==0)&&(m==0))
        {
            break;
        }
        dt=n*n-4*m;
        ans=sqrt(dt);
        tmp=(int)ans;
        if ((tmp*tmp==dt)&&(dt>=0))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
