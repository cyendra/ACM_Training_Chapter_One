#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int m,n;
int f[30];

int Ark( int a , int b );

int Ark(int a,int b)
{
    if ( a>0 && b==0 )
    {
        return Ark( a-1 ,1 );
    }
    if ( a==0 )
    {
        return b+1;
    }
    if ( a==1 )
    {
        return b+2;
    }
    if ( a==2 )
    {
        return 2*n+3;
    }
    if ( a==3 )
    {
        if ( f[b]!=-1 ) return f[b];
        f[b]=2*Ark( a , b-1 )+3;
        return f[b];
    }
}

int main()
{
    memset(f,-1,sizeof(f));
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        printf("%d\n", Ark(m,n) );
    }
    return 0;
}
