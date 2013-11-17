#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[411111];
int f[411111];
int que[1111111];
int pt[1111111];
int n,k;
int T;
int head,tail;
int sum[411111];
int max_sum,start,end;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        memset(f,0,sizeof(f));
        memset(que,0,sizeof(que));
        memset(pt,0,sizeof(pt));
        memset(sum,0,sizeof(sum));
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i+n]=a[i];
        }
        for (int i=1;i<=n+k;i++)
        {
            sum[i]+=sum[i-1]+a[i];
        }
        //f[i]=max(sum[i]-sum[k]);
        head=tail=0;
        max_sum=start=end=-1e9;
        for (int i=1;i<=n+k;i++)
        {
            while ((head<tail)&&(i-pt[head]>k)) head++;
            while ((head<tail)&&(sum[i-1]<=que[tail-1])) tail--;
            que[tail]=sum[i-1],pt[tail++]=i-1;
            f[i]=sum[i]-que[head];
            if (f[i]>max_sum)
            {
                max_sum=f[i];
                start=pt[head]+1;
                end=i;
            }
        }
        if (start>n) start=start-n;
        if (end>n) end=end-n;
        printf("%d %d %d\n",max_sum,start,end);
    }
    return 0;
}
