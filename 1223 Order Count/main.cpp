#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void bigsum( int *a, int *b, int *c );
void smallsum( int *a,int *b );
void big( int *a, int *b, int p );
int p,n;
int f[51][51][500];
int t[500];

void bigsum( int *a, int *b, int *c )
{
    a[0]=max( b[0],c[0] );
    for (int i=1; i<=a[0]; i++)
    {
        a[i]+=b[i]+c[i];
        a[i+1]+=a[i]/10;
        a[i]=a[i]%10;
    }
    if ( a[ a[0]+1 ]>0 )
    {
        a[0]++;
    }
}

void smallsum( int *a,int *b )
{
    a[0]=max( b[0],a[0] );
    for (int i=1; i<=a[0]; i++)
    {
        a[i]+=b[i];
        a[i+1]+=a[i]/10;
        a[i]=a[i]%10;
    }
    if ( a[ a[0]+1 ]>0 )
    {
        a[0]++;
    }
}

void big( int *a, int *b, int p )
{
    a[0]=b[0];
    for (int i=1; i<=a[0]; i++)
    {
        a[i]+=b[i]*p;
    }
    for (int i=1; i<a[0]; i++)
    {
        a[i+1]+=a[i]/10;
        a[i]=a[i]%10;
    }
    while ( a[ a[0] ] >= 10 )
    {
        a[ a[0]+1 ]+=a[ a[0] ]/10;
        a[ a[0] ]=a[ a[0] ]%10;
        a[0]++;
    }
}

void pbig(int * a)
{
    for (int tmp=a[0]; tmp>=1; tmp--)
    {
        cout <<a[tmp];
    }
    cout << endl;
}

void cpy(int *a,int *b)
{
    a[0]=b[0];
    for (int i=1;i<=a[0];i++ )
    {
        a[i]=b[i];
    }
}

int main()
{
    cin >> p;
    for (int loop=0; loop<p; loop++)
    {
        cin >> n;
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            f[i][1][0]=1;
            f[i][1][1]=1;
        }
        for (int i=2;i<=n;i++)
        {
            big(f[i][i],f[i-1][i-1],i);
        }

        for (int i=2; i<=n; i++)
        {
            for (int j=2; j<i; j++)
            {
                memset(t,0,sizeof(t));
                big( t , f[i-1][j] , j );
                cout << "i= "<<i<<" j= "<<j << "f[i-1][j]*j= ";
                pbig( t );
                bigsum( f[i][j] , f[i-1][j-1] , t );
                cout <<" f[i][j]= ";
                pbig(f[i][j]);

            }
        }
        memset(t,0,sizeof(t));
        for (int i=1; i<=n; i++)
        {
            smallsum( t , f[n][i] );
        }
        for (int i=t[0]; i>=1; i--)
        {
            cout << t[i];
        }
        cout << endl;
    }
    return 0;
}
