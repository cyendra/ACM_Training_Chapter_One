#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n,m,a,b,ans;
    int h[1001];
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        ans=0;
        for (int i=0; i<n; i++)
        {
            h[i]=i;
        }
        for (int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            while (h[a]!=a)
            {
                a=h[a];
            }
            while (h[b]!=b)
            {
                b=h[b];
            }
            if (a==b)
            {
                ans++;
            }
            else
            {
                h[a]=b;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
