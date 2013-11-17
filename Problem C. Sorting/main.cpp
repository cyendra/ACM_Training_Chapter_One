#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
const int maxn=1111;

int a[maxn];
int od[maxn],po;
int ev[maxn],pe;
int f[maxn],cnt;
int n;
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int T;
    int cas=0;
    scanf("%d",&T);
    while (T--)
    {
        po=0;
        pe=0;
        cnt=0;
        scanf("%d",&n);
        for (int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            if (a[i]&1) od[po++]=a[i];
            else ev[pe++]=a[i];
        }
        sort(ev,ev+pe,greater<int>());
        sort(od,od+po,less<int>());
        int o=0,e=0;
        for (int i=0; i<n; i++)
        {
            if (a[i]&1) f[cnt++]=od[o++];
            else f[cnt++]=ev[e++];
        }
        printf("Case #%d:",++cas);
        for (int i=0; i<n; i++) printf(" %d",f[i]);
        puts("");
    }
    return 0;
}
