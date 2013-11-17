#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,m,t,ans;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==1)
        {
            printf("0\n");
            continue;
        }
        t=1;
        for (int i=0;i<m-1;i++)
        {
            t=t*10;
            t=t%n;
        }
        t=t*10;
        ans=t/n;
        printf("%d\n",ans);
    }
    return 0;
}
