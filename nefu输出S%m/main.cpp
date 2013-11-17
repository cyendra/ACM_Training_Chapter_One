#include <stdio.h>

long long m;

long long pow(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%m;
            b--;
        }
        b>>=1;
        a=a*a%m;
    }
    return ans;
}



long long sum(long long p,long long n)
{
    if(n==0)
    {
        return 1;
    }
    if(n&1)
    {
        return ((1+pow(p,(n>>1)+1))%m * sum(p,n>>1)%m)%m;
    }
    else
    {
        return ((1+pow(p,(n>>1)+1))%m * sum(p,(n-1)>>1)%m + pow(p,n>>1)%m)%m;
    }
}


long long Sum(long long p,long long n)
{
    if(n==0)
        return 1;
    if(n&1)
        return ((1+pow(p,n/2+1)%m)%m*Sum(p,n/2)%m)%m;
    else
        return ((1+pow(p,n/2+1)%m)%m*Sum(p,(n-1)/2)%m+pow(p,n/2)%m)%m;
}

int main()
{
    long long p,n;
    while(~scanf("%I64d%I64d%I64d",&p,&n,&m))
    {
        printf("%I64d\n",(Sum(p,n)+m-1)%m);
    }
    return 0;
}
