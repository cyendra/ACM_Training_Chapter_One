#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b,t;
    int ans;
    scanf("%d",&t);
    for (int loop=0;loop<t;loop++)
    {
        scanf("%d%d",&a,&b);
        ans=a%100+b%100;
        ans=ans%100;
        printf("%d\n",ans);
    }
    return 0;
}
