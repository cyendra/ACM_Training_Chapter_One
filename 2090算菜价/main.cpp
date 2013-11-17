#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char s[100];
    double a,b,sum;
    sum=0;
    while (scanf("%s%lf%lf",s,&a,&b)!=EOF)
    {
        sum+=a*b;
    }
    printf("%0.1f\n",sum);
    return 0;
}
