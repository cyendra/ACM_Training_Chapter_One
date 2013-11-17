#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int k,l,sum=0;
    int f[11][17];
    scanf("%d%d",&k,&l);
    memset(f,0,sizeof(f));
    for (int i=0;i<k;i++)
    {
        f[1][i]=1;
    }
    for (int i=0;i<k;i++)
    {
        for (int t=1;t<k;t++)
        {
            if ((i-1!=t)and(i+1!=t))
            {
                f[2][i]+=f[1][t];
            }
        }
    }
    for (int i=3;i<=l;i++)
    {
        for (int j=0;j<k;j++)
        {
            for (int t=0;t<k;t++)
            {
                if ((j-1!=t)and(j+1!=t))
                {
                    f[i][j]+=f[i-1][t];
                }
            }
        }
    }
    for (int i=0;i<k;i++)
    {
        sum+=f[l][i];
    }
    printf("%d\n",sum);
    return 0;
}
