#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn=1111111;

int a[maxn];
int que[maxn];
int idx[maxn];

int main()
{
    int n,k;
    int head,tail,cas;
    while (~scanf("%d%d",&n,&k))
    {
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        head=tail=cas=0;
        for (int i=0;i<n;i++)
        {
            while (head<tail&&que[tail-1]>=a[i]) tail--;
            idx[tail]=i;
            que[tail++]=a[i];
            while (head<tail&&i-idx[head]>=k) head++;
            if (i>=k-1) cout<<que[head]<<" ";
            else if (i>=k-1&&i==n-1) cout<<que[head];
        }
        cout<<endl;
        head=tail=cas=0;
        for (int i=0;i<n;i++)
        {
            while (head<tail&&que[tail-1]<=a[i]) tail--;
            idx[tail]=i;
            que[tail++]=a[i];
            while (head<tail&&i-idx[head]>=k) head++;
            if (i>=k-1&&i<n-1) cout<<que[head]<<" ";
            else if (i>=k-1&&i==n-1) cout<<que[head];
        }
        cout<<endl;
    }
    return 0;
}
