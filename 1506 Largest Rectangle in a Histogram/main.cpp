#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int l[100011];
int r[100011];
int a[100011];
//l[i]表示第i柱左侧第一个小于i的柱的编号+1,即从编号l[i]到编号i之间的值都大于等于a[i]
//r[i]表示第i柱右侧第一个小于i的柱的编号-1,即从编号r[i]到编号i之间的值都大于等于a[i]
//则以i柱为最低柱的矩形的最大值为(r[i]-l[i]+1)*a[i]
//当a[i]<=a[l[i]-1]时,l[i]=l[l[i]-1]
//同理,当a[i]<=a[r[i]+1]时,r[i]=r[r[i]+1]
int main()
{
    int n;
    long long int ans,tmp;
    while (scanf("%d",&n)!=EOF && n!=0 )
    {
        //memset(l,0,sizeof(l));
        //memset(r,0,sizeof(r));
        memset(a,0,sizeof(a));
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (int i=0;i<n;i++)
        {
            l[i]=i;
            while ( l[i]>0 && a[i]<=a[l[i]-1] )
            {
                l[i]=l[ l[i]-1 ];
            }
        }
        for (int i=n-1;i>=0;i--)
        {
            r[i]=i;
            while ( r[i]<n-1 && a[i]<=a[r[i]+1] )
            {
                r[i]=r[ r[i]+1 ];
            }
        }
        ans=0;
        tmp=0;
        for (int i=0;i<n;i++)
        {
            tmp=(long long int)( (long long int)(r[i]-l[i]+1) * (long long int)a[i] );
            if (tmp>ans)
            {
                ans=tmp;
            }
        }
        cout << ans <<endl;
    }
    return 0;
}
