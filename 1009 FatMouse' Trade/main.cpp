#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct{
    int bean;
    int food;
    double v;
}STR;
STR a[1001];
bool cmp(STR x,STR y);

bool cmp(STR x,STR y)
{
    if (x.v>y.v)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int m,n,i;
    double ans;

    while ( scanf("%d%d",&m,&n)!=EOF )
    {
        if ((n==-1)&&(m==-1))
        {
            break;
        }
        if (n==0)
        {
            ans=0;
            printf("%0.3f\n",ans);
            continue;
        }
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].bean,&a[i].food);
            a[i].v=(double)a[i].bean/(double)a[i].food;
        }
        sort(a,a+n,cmp);
        i=0;
        ans=0;
        while ( (i<n)&&(m-a[i].food>=0) )
        {
            m=m-a[i].food;
            ans+=(double)a[i].bean;
            //printf("i=%d bean=%d\n",i,a[i].bean);
            i++;
        }
        if (m>0)
        {
            ans+=((double)m/(a[i].food)) * ((double)a[i].bean);
        }
        printf("%0.3f\n",ans);
    }
    return 0;
}
