#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef struct
{
    float w;
    float v;
}car;
car f[100];

int cmp(const void *a,const void *b)
{
    if (  (*(car *)b).v - (*(car *)a).v >0 )
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
    float sum=0.0;
    int m,n;
    scanf("%d%d",&m,&n);
    for (int i=0;i<n;i++)
    {
        scanf("%f%f",&f[i].w,&f[i].v);
    }
    qsort(f,n,sizeof(f[0]),cmp);
    for (int i=0;i<n;i++)
    {
        if (m==0)
        {
            break;
        }
        if (f[i].w <m)
        {
            sum+=f[i].v * f[i].w;
            m-=f[i].w;
        }
        else
        {
            sum+=f[i].v * m;
            m=0;
        }
    }
    printf("%0.2f",sum);
    return 0;
}
