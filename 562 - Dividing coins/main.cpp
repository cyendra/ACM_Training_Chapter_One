#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int f[111111];
int a[111];
int n;

int main()
{
    int T;
    int sum;
    scanf("%d",&T);
    while (T--)
    {
        memset(f,0,sizeof(f));
        sum=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        f[0]=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=sum/2-a[i];j>=0;j--)
            {
                if (f[j]) f[j+a[i]]=1;
            }
        }
        int a,b;
        for (int i=sum/2;i>=0;i--)
        {
            if (f[i])
            {
                a=i;
                break;
            }
        }
        b=sum-a;
        int ans;
        if (a>b) ans=a-b;
        else ans=b-a;
        printf("%d\n",ans);
    }
    return 0;
}
