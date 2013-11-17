#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int len;
char a[5003],b[5003];
short int f[5003][5003];

short int same( char a, char b )
{
    if ( a==b )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

short int sup( int a, int b, int c )
{
    return max(a,max(b,c));
}

int main()
{
    while (cin>>len)
    {
        memset(f,0,sizeof(f));
        cin>>a;
        for (int i=0;i<strlen(a);i++)
        {
            b[len-i-1]=a[i];
        }
        b[len]='/0';
        for (int i=1;i<=len;i++)
        {
            for (int j=1;j<=len;j++)
            {
                f[i][j]=sup( f[i-1][j-1]+same(a[i-1],b[j-1]),f[i-1][j],f[i][j-1] ) ;
            }
        }
        cout<<len-f[len][len]<<endl;
    }
    return 0;
}

