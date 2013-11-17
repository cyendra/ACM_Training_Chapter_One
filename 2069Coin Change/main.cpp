#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n,c50,c25,c10,c5,c1,sum;
    int f[251]={0};

    for (n=0;n<=250;n++)
        for (c50=0;c50*50<=n;c50++)
        {
            for (c25=0;c25*25+c50*50<=n;c25++)
            {
                for (c10=0;c10*10+c25*25+c50*50<=n;c10++)
                {
                    for (c5=0;c5*5+c10*10+c25*25+c50*50<=n;c5++)
                    {
                        c1=n-(c5*5+c10*10+c25*25+c50*50);
                        if (c1+c5+c10+c25+c50<=100)
                        f[n]++;
                    }
                }
            }
        }


    while (scanf("%d",&n)!=EOF)
    {
        printf("%d\n",f[n]);
    }
    return 0;
}
