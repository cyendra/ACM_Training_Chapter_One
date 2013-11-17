#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n,t,s;
    bool f;
    f=false;
    while (scanf("%d",&n)!=EOF)
    {
        if (f==false)
        {
            f=true;
        }
        else
        {
            printf("\n");
        }
        s=0;
        while (n!=0)
        {
           t=n%10;
           if (t%2==0)
           {
                s+=t;
           }
           n/=10;
        }
        printf("%d\n",s);
    }
    return 0;
}
