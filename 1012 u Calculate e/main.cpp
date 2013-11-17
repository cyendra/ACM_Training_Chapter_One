#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int ai[10];
    int n,e;
    double ans;
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");
    ans=2.5;
    ai[0]=1;
    ai[1]=1;
    for (int i=2;i<10;i++)
    {
        ai[i]=ai[i-1]*i;
    }
    for (n=3;n<=9;n++)
    {
        ans=ans+(1.0/ai[n]);
        printf("%d %0.9f\n",n,ans);
    }
    return 0;
}
