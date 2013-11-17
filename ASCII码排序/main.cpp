#include <iostream>
#include <cstdio>
#include <stdio.h>
using namespace std;

void swap(char *a,char *b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    char str[4];
    while (scanf("%s",str)!=EOF)
    {
        if (str[0]>str[1])
            swap(str[0],str[1]);
        if (str[1]>str[2])
            swap(str[1],str[2]);
        if (str[0]>str[1])
            swap(str[0],str[1]);
        printf("%c %c %c\n",str[0],str[1],str[2]);
    }

    return 0;
}
