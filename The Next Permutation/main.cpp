#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

char s[1111];
int a[1111];
int n;
int p;

int main()
{
    int T,tp;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&tp);
        scanf("%s",s+1);
        n=strlen(s+1);
        for (int i=1;i<=n;i++)
        {
            a[i]=s[i]-'0';
        }
        bool ok=true;
        for (int i=n;i>1;i--)
        {
            if (a[i]>a[i-1])
            {
                ok=false;
                p=i-1;
                break;
            }
        }
        if (ok)
        {
            printf("%d BIGGEST\n",tp);
            continue;
        }
        int m=10;
        int c=0;
        for (int i=p+1;i<=n;i++)
        {
            if (a[i]>a[p]&&a[i]<m)
            {
                m=a[i];
                c=i;
            }
        }
        swap(a[p],a[c]);
        sort(a+p+1,a+n+1);
        printf("%d ",tp);
        for (int i=1;i<=n;i++)
        {
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
