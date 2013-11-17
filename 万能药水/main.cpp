#include <iostream>
#include <cstdio>
#include <cstdlib>

float p[101]={0};
int cmp(const void *a,const void *b)
{
    if ( *(float *)a - *(float *)b >0 )
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
using namespace std;

int main()
{
    int m,n,v,c;
    int ansv;
    float ans,t,w;
    scanf("%d",&c);
    for (int loop=0;loop<c;loop++)
    {
        scanf("%d%d%f",&n,&v,&w);
        w=w/100;
        for (int i=0;i<n;i++)
        {
            scanf("%f",&p[i]);
            p[i]=p[i]/100;
        }
        qsort(p,n,sizeof(p[0]),cmp);
        ansv=0;
        ans=0.0;
        for (int i=0;i<n;i++)
        {
                t=((p[i]*v)+ans*ansv)/(v+ansv);
                if (t>=w)
                {
                    break;
                }
                ans=t;
                ansv+=v;
        }
        printf("%d %0.2f\n",ansv,ans);
    }
    return 0;
}
