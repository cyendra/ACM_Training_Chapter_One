#include <iostream>
#include <cstdio>
using namespace std;

char s[11111];

int main()
{
    int T;
    long long n;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        n=0;
        for (int i=0;s[i];i++)
        {
            n+=s[i]-'0';
        }
        while (n>=10)
        {
            int tmp=0;
            while (n>0)
            {
                tmp+=n%10;
                n=n/10;
            }
            n=tmp;
        }
        printf("%I64d\n",n);
    }
    return 0;
}
