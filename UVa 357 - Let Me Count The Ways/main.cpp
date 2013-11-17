#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int coins[6]={1,5,10,25,50};
long long f[51111];
int m;

int main()
{
    memset(f,0,sizeof(f));
    f[0]=1;
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<=30000-coins[i];j++)
        {
            if (f[j]) f[j+coins[i]]+=f[j];
        }
    }
    while (~scanf("%d",&m))
    {
        if (f[m]==1)
        {
            printf("There is only 1 way to produce %d cents change.\n",m);
        }
        else
        {
            printf("There are %lld ways to produce %d cents change.\n",f[m],m);
        }
    }
    return 0;
}

