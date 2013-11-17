#include <iostream>
#include <cstdio>

using namespace std;

int abs(int a)
{
    if (a<0)
    {
        return -a;
    }
    else
    {
        return a;
    }
}

int main()
{
    int n,first,midle,last,sum,max;
    int p=9,rd=360,now;
    while (scanf("%d%d%d%d",&n,&first,&midle,&last))
    {
        now=n;
        if ((0==n)and(0==first)and(0==midle)and(0==last))
        {
            break;
        }
        sum=0;
        sum=2*rd;
        now=first;
        //printf("%d",sum);getchar();
        max=abs(n-now);

        if (abs(now-n+40)<max)
        {
            max=abs(now-n+40);
        }
        if (abs(n-now+40)<max)
        {
            max=abs(n-now+40);
        }
        sum+=max*p;
        //printf("%d",max);getchar();
        sum+=rd;
        //printf("%d",sum);getchar();
        while (now!=midle)
        {
            now++;
            if (now>39)
            {
                now=0;
            }
            sum+=p;
        }
        //printf("%d",sum);getchar();
        while (now!=last)
        {
            now--;
            if (now<0)
            {
                now=39;
            }
            sum+=p;
        }
        //printf("%d",sum);getchar();
        printf("%d\n",sum);
    }

    return 0;
}
