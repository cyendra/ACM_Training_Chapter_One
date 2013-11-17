#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
long int a[100000];
char str[100];

int main()
{
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%s",str);
        a[i]=1;
        for (int k=0;k<strlen(str);k++)
        {

            switch (str[k])
            {
                case 'A':
                case 'B':
                case 'C':
                {
                    a[i]=a[i]*10+2;
                    break;
                }
                case 'D':
                case 'E':
                case 'F':
                {
                    a[i]=a[i]*10+3;
                    break;
                }
                case 'G':
                case 'H':
                case 'I':
                {
                    a[i]=a[i]*10+4;
                    break;
                }
                case 'J':
                case 'K':
                case 'L':
                {
                    a[i]=a[i]*10+5;
                    break;
                }
                case 'M':
                case 'N':
                case 'O':
                {
                    a[i]=a[i]*10+6;
                    break;
                }
                case 'P':
                case 'R':
                case 'S':
                {
                    a[i]=a[i]*10+7;
                    break;
                }
                case 'T':
                case 'U':
                case 'V':
                {
                    a[i]=a[i]*10+8;
                    break;
                }
                case 'W':
                case 'X':
                case 'Y':
                {
                    a[i]=a[i]*10+9;
                    break;
                }
            }
            if ( (str[k]>='0')  and (str[k]<='9') )
            {
                a[i]=a[i]*10+str[k]-'0';
            }
        }
    }
    sort(a,a+n);
    long int t=0;
    int num=1;
    bool ok=false;
    for (int i=0;i<n;i++)
    {
        if (a[i]==t)
        {
            num++;
        }
        if ( (a[i]!=t) and (num>1) )
        {
            ok=true;
            printf("%ld-%ld %d\n",(a[i-1]-10000000)/10000,a[i-1]%10000,num  );
            num=1;
        }
        t=a[i];

    }
    if (num>1)
    {
        ok=true;
        printf("%ld-%ld %d\n",(a[n-1]-10000000)/10000,a[n-1]%10000,num  );
    }

    if (ok==false)
    {
        printf("No duplicates.\n");
    }
    return 0;
}
