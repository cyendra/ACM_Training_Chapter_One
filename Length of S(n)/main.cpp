#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
using namespace std;

int main()
{
    int n,p,sum;
    int str[100];
    int tmp[100];
    int c,len;
    while (scanf("%d",&n))
    {
        if (n==0)
        {
            break;
        }
        str[0]=1;
        len=1;
        p=0;
        //-----------------------------------------
        for (int i=1;i<n;i++)
        {
            sum=0;
            c=str[0];
            for (int j=0;j<len;j++)
            {
                if (str[j]==c)
                {
                    sum++;
                    continue;
                }
                if (str[j]!=c)
                {
                    tmp[p]=sum;
                    p++;
                    tmp[p]=c;
                    p++;
                    sum=1;
                    c=str[j];
                }
            }
            tmp[p]=sum;
            p++;
            tmp[p]=c;
            p++;
            for (int k=0;k<p;k++)
            {
                str[k]=tmp[k];
            }
            len=p;
            p=0;
        }
        //-----------------------------------
        for (int i=0;i<len;i++)
        {
            printf("%d",str[i]);
        }
        printf("\n");
    }
    return 0;
}
