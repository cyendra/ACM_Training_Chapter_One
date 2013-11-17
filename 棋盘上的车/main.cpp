#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    int k;
    int f[65535]={0};
    scanf("%d%d",&n,&k);
    f[0] = 1;
    for(int i=1;i<(1<<n);i++)
        for(int t=i;t>0;t-=t&-t)
            f[i]+=f[i&~(t&-t)];
    printf("%d\n",f[(1<<n)-1]/f[(1<<(n-k))-1]);
    return 0;
}
