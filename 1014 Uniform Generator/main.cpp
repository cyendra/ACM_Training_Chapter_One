#include <iostream>
#include <cstdio>

using namespace std;

int step;
int mod;
int t;
int gcd(int a,int b)
{
    if (b==0)
    {
        return a;
    }
    if (b>a)
    {
        t=a;
        a=b;
        b=t;
    }
    return gcd(b,a%b);
}
int main()
{
    while ( scanf("%d%d",&step,&mod)!=EOF )
    {
        if ( (step<=0)||(mod<=0) )
        {
            printf("%10d%10d    Bad Choice\n\n",step,mod);
            continue;
        }
        if (gcd(step,mod)==1)
        {
            printf("%10d%10d    Good Choice\n",step,mod);
        }
        else
        {
            printf("%10d%10d    Bad Choice\n",step,mod);
        }
        printf("\n");
    }
    return 0;
}
