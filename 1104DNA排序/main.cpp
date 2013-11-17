#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct
{
    char str[101];
    int v;
}DNA;
DNA a[101];
int n,m;
/*
int cmp(const void* x,const void * y)
{
    if ( ((*(DNA*)x).v) > ((*(DNA*)y).v   ) )
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
*/

int cmp(DNA x,DNA y)
{
    if (x.v<y.v)
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
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        scanf("%s",a[i].str);
        a[i].v=0;
        for (int x=0;x<n;x++)
        {
            for (int y=x+1;y<n;y++)
            {
                if (a[i].str[x]>a[i].str[y])
                {
                    a[i].v+=1;
                }
            }
        }
    }
    //qsort(a,m,sizeof(DNA),cmp);
    sort(a,a+m,cmp);
    for (int i=0;i<m;i++)
    {
        printf("%s\n",a[i].str);
    }
    return 0;
}
