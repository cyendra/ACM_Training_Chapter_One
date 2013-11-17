#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    int left,ps,os,ans;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        ans=0;
        scanf("%d%d%d",&left,&ps,&os);
        if (left>6)
        {
            ans=(left-6)+(left-6)*7+7+6+5+4+3+2;
        }
        if (left<=6)
        {
            for (int i=1;i<=left;i++)
            {
                ans=ans+8-i;
            }
        }
        if (ans+ps>=os)
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
