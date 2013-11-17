#include <iostream>
#include <cstdio>
using namespace std;

int T;
int n;
int a[1111111];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        bool ok=true;
        for (int i=n;i>=2;i--)
        {
            if (a[i]<=a[i-1])
            {
                a[i-1]-=a[i];
                a[i]=0;
            }
            else
            {
                ok=false;
            }
        }
        for (int i=1;i<=n;i++)
            if (a[i]>0) ok=false;
        if (ok) printf("yeah~ I escaped ^_^\n");
        else printf("I will never go out T_T\n");
    }
    return 0;
}
