#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int l[100011];
int r[100011];
int a[100011];
//l[i]��ʾ��i������һ��С��i�����ı��+1,���ӱ��l[i]�����i֮���ֵ�����ڵ���a[i]
//r[i]��ʾ��i���Ҳ��һ��С��i�����ı��-1,���ӱ��r[i]�����i֮���ֵ�����ڵ���a[i]
//����i��Ϊ������ľ��ε����ֵΪ(r[i]-l[i]+1)*a[i]
//��a[i]<=a[l[i]-1]ʱ,l[i]=l[l[i]-1]
//ͬ��,��a[i]<=a[r[i]+1]ʱ,r[i]=r[r[i]+1]
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
