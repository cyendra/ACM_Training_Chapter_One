#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int a[250],b[250],c[250];
    char s1[250],s2[250];
    int l1,l2,l3;
    while (scanf("%s%s",s1,s2)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        l1=strlen(s1);
        l2=strlen(s2);
        for (int i = 0 ;i<l1;i++ )
        {
            a[i]=s1[l1-i-1]-'A';
        }
        for (int i = 0 ;i<l2;i++ )
        {
            b[i]=s2[l2-i-1]-'A';
        }
        if (l1>l2)
        {
            l3=l1;
        }
        else
        {
            l3=l2;
        }
        for (int i=0;i<l3;i++)
        {
            c[i]=c[i]+a[i]+b[i];
            //printf("i=%d,%d=%d+%d\n",i,c[i],a[i],b[i]);
            if (c[i]>25)
            {
                c[i+1]=c[i+1]+c[i]/26;
                c[i]=c[i]%26;
            }
        }
        while (c[l3]==0)
        {
            l3--;
        }
        if (l3<0)
        {
            l3=0;
        }
        for (int i=l3;i>=0;i--)
        {
            printf("%c", (char)(c[i]+'A') );
        }
        printf("\n");
    }
    return 0;
}
