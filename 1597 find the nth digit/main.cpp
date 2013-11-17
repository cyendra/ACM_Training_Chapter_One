#include<iostream>
#include<cmath>
using namespace std;
__int64 cal(__int64 x)
{
    __int64 t=sqrt(x*2.0);
    if(t*(t+1)/2>=x)t--;
    x-=t*(t+1)/2;
    return (x-1)%9+1;
}
int main()
{
    int t;
    __int64 n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        printf("%I64d\n",cal(n));
    }
    return 0;
}
