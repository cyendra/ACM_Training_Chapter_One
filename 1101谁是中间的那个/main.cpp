#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

int n,ans;
int a[10000];
int cmp(const void *a,const void *b)
{
    if (*(int *)a>*(int *)b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    ans=a[n/2];
    printf("%d\n",ans);
    return 0;
}
