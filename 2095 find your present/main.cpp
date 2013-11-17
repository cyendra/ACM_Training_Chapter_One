#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    __int64 ans,t;
    while (scanf("%d",&n))
    {
        if (n==0)
        {
            break;
        }
        ans=0;
        for (int loop=0;loop<n;loop++)
        {
            scanf("%I64d",&t);
            ans=ans^t;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
