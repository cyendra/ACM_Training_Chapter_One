#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//const int coins[12]={2000,1000,400,200,100,40,20,10,4,2,1};
const int coins[12]={1,2,4,10,20,40,100,200,400,1000,2000};
long long f[40000];
double money;
int m;

int main()
{
    memset(f,0,sizeof(f));
    f[0]=1;
    for (int i=0; i<11; i++)
    {
        for (int j=0; j<=6000-coins[i]; j++)
        {
            if (f[j])
            {
                f[j+coins[i]]+=f[j];
            }
        }
    }
    int a,b;
    //while (~scanf("%lf",&money))
    while (~scanf("%d.%d",&a,&b))
    {
        if (a==0&&b==0) break;
        m=a*20+b/5;
        money=double(a)+double(b)/100;
        printf("%6.2lf",money);
        printf("%17lld\n",f[m]);
    }
    return 0;
}
