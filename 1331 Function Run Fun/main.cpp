#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int f[200][200][200];

int qa,qb,qc;

int dp(int a,int b,int c);

int dp(int a,int b,int c)
{
    if ( a<=0 || b<=0 || c<=0 )
    {
        if ( a>=0 && b>=0 && c>=0 ) f[a][b][c]=1;
        return 1;
    }
    if ( a>20 || b>20 || c>20 )
    {
        return dp(20,20,20);
    }
    if ( f[a][b][c]!=-1 ) return f[a][b][c];
    if ( a<b && b<c )
    {
        f[a][b][c]=dp(a,b,c-1)+dp(a,b-1,c-1)-dp(a,b-1,c);
        return f[a][b][c];
    }
    else
    {
        f[a][b][c]=dp(a-1,b,c)+dp(a-1,b-1,c)+dp(a-1,b,c-1)-dp(a-1,b-1,c-1);
        return f[a][b][c];
    }

}

int main()
{
    memset(f,-1,sizeof(f));
    while ( scanf("%d%d%d",&qa,&qb,&qc)!=EOF )
    {
        if ( qa==-1 && qb==-1 && qc==-1 ) break;
        printf("w(%d, %d, %d) = %d\n",qa,qb,qc,dp(qa,qb,qc));
    }
    return 0;
}
