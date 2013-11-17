#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int ans,day;

    while (scanf("%d",&day)!=EOF)
    {
        ans=1;
        for (int i=2;i<=day;i++)
        {
            ans=(ans+1)*2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
