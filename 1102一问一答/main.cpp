#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int n,k,t;
int a[5001];
char str[4];

int cmp(const void *x,const void *y)
{
    if (*(int*)x>*(int*)y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    getchar();
    gets(str);
    qsort(a,n,sizeof(int),cmp);
    scanf("%d",&k);
    for (int i=0;i<k;i++)
    {
        scanf("%d",&t);
        printf("%d\n",a[t-1]);
    }
    return 0;
}
