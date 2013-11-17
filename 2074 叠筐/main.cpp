
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    char str[80][80],c1,c2,pc;
    int n,x,y,l,t;
    bool p1,fff;
    fff=false;
    while (scanf("%d",&n)!=EOF)
    {
        if (fff==false)
        {
            fff=!fff;
        }
        else
        {
            printf("\n");
        }
        str[0][0]='\n';
        l=x=y=n/2;
        t=1;
        getchar();
        c1=getchar();
        getchar();
        c2=getchar();
        getchar();
        str[x][y]=c1;
        p1=false;
        while (str[0][0]=='\n')
        {
            if (p1==true)
            {
                pc=c1;
            }
            else
            {
                pc=c2;
            }
            l--;
            t+=2;
            for (int i=l;i<=l+t-1;i++)
            {
                str[i][l]=pc;
                str[i][l+t-1]=pc;
                str[l][i]=pc;
                str[l+t-1][i]=pc;
            }
            p1=!p1;
        }
        if (n>2)
        {
            str[0][0]=' ';
            str[n-1][0]=' ';
            str[0][n-1]=' ';
            str[n-1][n-1]=' ';
        }

        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                printf("%c",str[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}
