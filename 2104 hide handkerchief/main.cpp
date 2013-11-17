#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int gcd(int a,int b)
{
    if (b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}

int main()
{
    int n,m,t;
    while ( scanf("%d%d",&n,&m) )
    {
        if ((n==-1)&&(m==-1))
        {
            break;
        }
        if (m>n)
        {
            t=m;
            m=n;
            n=t;
        }

        if (gcd(n,m)==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("POOR Haha\n");
        }
    }
    return 0;
}
