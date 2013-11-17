#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    const int green=0;
    const int red=1;
    const int blue=2;
    const int pink=3;
    const int orange=4;
    const int black=5;
    int n;
    int a[10]={0};
    char str[20];
    while (scanf("%d",&n))
    {
        getchar();
        for (int i=0;i<n;i++)
        {
            gets(str);
            if (!strcmp(str,"green"))
            {
                a[green]++;
            }
            if (!strcmp(str,"red"))
            {
                a[red]++;
            }
            if (!strcmp(str,"blue"))
            {
                a[blue]++;
            }
            if (!strcmp(str,"pink"))
            {
                a[pink]++;
            }
            if (!strcmp(str,"orange"))
            {
                a[orange]++;
            }
            if (!strcmp(str,"black"))
            {
                a[black]++;
            }
        }
        int max=0;
        int ans;
        for (int i=0;i<6;i++)
        {
            if (a[i]>max)
            {
                max=a[i];
                ans=i;
            }
        }
        switch (ans)
        {
            case green:printf("green\n");break;
            case red:printf("red\n");break;
            case blue:printf("blue\n");break;
            case pink:printf("pink\n");break;
            case orange:printf("orange\n");break;
            case black:printf("black\n");break;
        }



    }
    return 0;
}
