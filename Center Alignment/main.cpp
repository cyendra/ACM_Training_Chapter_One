/*
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    char str[1010][1010];
    char out[1010][1010]={0};
    int n=0;
    int maxlen=0;
    int part;
    for ( int p=0;gets(str[p])!=NULL;p++ )
    {
        if ( str[p][0]=='@' ) break;
        if ( strlen( str[p] )>maxlen )
        {
            maxlen=strlen( str[p] );
        }
        n++;
    }
    for (int i=0;i<maxlen+2;i++)
    {
        printf("*");
    }
    puts("");
    for (int i=0;i<n;i++)
    {
        printf("*");
        part=(maxlen-strlen(str[i]))/2;
        for (int k=0;k<part;k++)
        {
            printf(" ");
        }
        for (int k=0;k<strlen(str[i]);k++)
        {
            printf("%c",str[i][k]);
        }
        for (int k=0;k<part;k++)
        {
            printf(" ");
        }
        printf("*\n");
    }
    for (int i=0;i<maxlen+2;i++)
    {
        printf("*");
    }
    printf("\n");
    return 0;
}
*/

 #include<stdio.h>
 #include<string.h>
 char c[1001][1001];
 int main()
 {
     int k[1001], i = 0, j,flag = 1,max = 0,q;
     while(gets(c[i])!=NULL)
     {
         if(c[i][0] == '*')
         break;
         k[i] = strlen(c[i]);
         if(max<k[i])
         max = k[i];
         i++;
     }
     for(j = 1 ; j <= max+2 ; j++)
     printf("*");
     puts("");
     for(j = 0 ; j < i ; j++)
     {
         printf("*");
         if((max-k[j])%2 == 0)
         {
             for(q = 1 ;q<=(max-k[j])/2 ; q++)
             printf(" ");
             for(q = 0 ; q < k[j] ; q++)
             printf("%c",c[j][q]);
             for(q = 1 ;q<=(max-k[j])/2 ; q++)
             printf(" ");
         }
         else
         {
             if(flag == 1)
             {
                  for(q = 1 ;q<=(max-k[j])/2 ; q++)
                 printf(" ");
                 for(q = 0 ; q < k[j] ; q++)
                 printf("%c",c[j][q]);
                 for(q = 1 ;q<=(max-k[j])/2+1 ; q++)
                 printf(" ");
                 flag = 0;
             }
             else
             {
                 for(q = 1 ;q<=(max-k[j])/2+1 ; q++)
                 printf(" ");
                 for(q = 0 ; q < k[j] ; q++)
                 printf("%c",c[j][q]);
                 for(q = 1 ;q<=(max-k[j])/2 ; q++)
                 printf(" ");
                 flag = 1;
             }
         }
         printf("*\n");
     }
     for(j = 1 ; j <= max+2 ; j++)
     printf("*");
     return 0;
 }

