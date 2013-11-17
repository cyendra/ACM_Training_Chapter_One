#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int tp[11111];
int n;
int a[11111];
int tn;

int main()
{
    while (~scanf("%d",&tn))
    {
        memset(tp,0,sizeof(tp));
        memset(a,0,sizeof(a));
        for (int i=1;i<=tn;i++)
        {
            scanf("%d",&tp[i]);
        }
        sort(tp+1,tp+tn+1);
        n=0;
        for (int i=1;i<=tn;i++)
        {
            while (tp[i]==tp[i+1]) i++;
            a[n++]=tp[i];
        }
        //for (int i=0;i<n;i++) cerr<<a[i]<<" ";cerr<<endl;
        int ans=1;
        for (int i=1;i<=n-1;i++)
        {
            ans=(ans*2)%100007;
        }
        ans=(ans*(n-2))%100007;
        ans=(ans+1)%100007;
        printf("%d\n",ans);
    }
    return 0;
}
