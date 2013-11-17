#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    __int64 n,ans;
    while (scanf("%I64d",&n)!=EOF)
    {
        ans=(n*(n+1)/2)%10000;
        ans=(ans*ans)%10000;
        if (ans<1000) printf("0");
        if (ans<100) printf("0");
        if (ans<10) printf("0");
        printf("%I64d\n",ans);
    }
    return 0;
}
