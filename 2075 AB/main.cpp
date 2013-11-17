#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    __int64 a,b;
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%I64d%I64d",&a,&b);
        if (a%b==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
