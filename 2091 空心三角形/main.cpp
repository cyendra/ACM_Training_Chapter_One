/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char c;
    int n,t,tp,ct,p;
    char a[41][41];
    p=0;
    while (c=getchar())
    {
        if (c=='@')
        {
            break;
        }
        scanf("%d",&n);
        getchar();
        if (p==0)
        {
            p++;
        }
        else
        {
            printf("\n");
        }
        if (n==1)
        {
            printf("%c\n",c);
            continue;
        }
        t=2*n-1;
        memset(a,0,sizeof(a));
        for (int i=0;i<41;i++)
        {
            for (int j=0;j<41;j++)
            {
                a[i][j]=' ';
            }
        }
        for (int i=0;i<t;i++)
        {
            a[0][i]=c;
        }
        tp=t/2;
        for (int i=1;i<=tp;i++)
        {
            a[i][i]=c;
            a[i][t-i-1]=c;
        }
        //Êä³ö

        for (int i=0;i<=tp;i++)
        {
            printf("%c",a[tp][i]);
        }
        printf("\n");

        for (int i=tp-1;i>=1;i--)
        {
            ct=0;
            for (int j=0;j<t;j++)
            {
                if (a[i][j]==c)
                {
                    ct++;
                    printf("%c",a[i][j]);
                }
                else
                {
                    printf(" ");
                }
                if (ct>=2)
                {
                    printf("\n");
                    break;
                }
            }
        }
        for (int i=0;i<t;i++)
        {
            printf("%c",a[0][i]);

        }
        printf("\n");
    }
    return 0;
}
*/

#include <stdio.h>

int main(void)
{
    char c;
    int i = 0, n;

    while ((c = getchar()) != '@')
    {
        scanf("%d%*c", &n);
        printf(i ? "\n%*c\n" : "%*c\n", n, c);
        if (n == 1)
        {
            i = 1;
            continue;
        }
        for (i = 1; i + 1 < n; i++)
            printf("%*c%*c\n", n - i, c, i * 2, c);
        for (i = 0; i < 2 * n - 1; i++)
            putchar(c);
        putchar('\n');
    }
    return 0;
}
