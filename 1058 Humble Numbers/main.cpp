#include <iostream>
#include <cstdio>
using namespace std;
int f[6000];
int minfour(int a,int b,int c,int d)
{
    int t;
    t=a;
    if (b<t)
    {
        t=b;
    }
    if (c<t)
    {
        t=c;
    }
    if (d<t)
    {
        t=d;
    }
    return t;
}
int main()
{
    int n;
    int p2,p3,p5,p7;
    int e2,e3,e5,e7;
    char o1,o2;
    f[0]=0;
    f[1]=1;
    p2=p3=p5=p7=1;
    for (int i=2;i<5900;i++)
    {
        e2=f[p2]*2;
        e3=f[p3]*3;
        e5=f[p5]*5;
        e7=f[p7]*7;
        f[i]=minfour(e2,e3,e5,e7);
        if (e2==f[i])
        {
            p2++;
        }
        if (e3==f[i])
        {
            p3++;
        }
        if (e5==f[i])
        {
            p5++;
        }
        if (e7==f[i])
        {
            p7++;
        }
    }
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0)
        {
            break;
        }
        o1='t';
        o2='h';
        if (n%10==1)
        {
            o1='s';
            o2='t';
        }
        if (n%10==2)
        {
            o1='n';
            o2='d';
        }
        if (n%10==3)
        {
            o1='r';
            o2='d';
        }
        if ((n%100==11)||(n%100==12)||(n%100==13))
        {
            o1='t';
            o2='h';
        }
        printf("The %d%c%c humble number is %d.\n",n,o1,o2,f[n]);
    }
    return 0;
}
