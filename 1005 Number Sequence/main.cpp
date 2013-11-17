/*
#include<stdio.h>
int main()
{
    int f[56],a,b,i;
    f[0]=1;
    f[1]=1;
    int n;
    while(1)
    {
        scanf("%d%d%d",&a,&b,&n);
        if(!a && !b && !n)
            break;
        for(i=2; i<49; i++)
            f[i]=(a*f[i-1]+b*f[i-2])%7;
        printf("%d/n",f[(n-1)%49]);
    }
    return 0;
}
*/
#include<stdio.h>

int main()
{
    int a1[50];
    int i,a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF && (a!=0 || b!=0 || c!=0))
    {
        a=a%7;
        b=b%7;
        a1[0]=1;
        a1[1]=1;
        for(i=2; i<48; i++)
            a1[i]=(a1[i-2]*b+a1[i-1]*a)%7;
        c=c%48;
        printf("%d\n",a1[c-1]);
    }
    return 0;
}


