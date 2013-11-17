/*
#include <iostream>
#include <cstring>
using namespace std;

int f[61][61][61][100];

int ans[61][100];

bool ck(int a,int b,int c);
void bigsum(int *a,int *b);

bool ck(int a,int b,int c)
{
    if ( a>=b && b>=c )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void bigsum(int *a,int *b)
{
    if ( b[0]>a[0] )
    {
        a[0]=b[0];
    }
    for (int i=1;i<=a[0];i++)
    {
        a[i]+=b[i];
        a[i+1]+=a[i]/10;
        a[i]=a[i]%10;
    }
    if ( a[a[0]+1]>0 )
    {
        a[0]++;
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        memset(f,0,sizeof(f));

        for (int a=0;a<=n;a++)
        {
            for (int b=0;b<=n;b++)
            {
                for (int c=0;c<=n;c++)
                {
                    if (a==0)
                    {
                        f[a][b][c][0]=1;
                        f[a][b][c][1]=1;
                        continue;
                    }
                    if ( ck(a,b,c)==false )
                    {
                        continue;
                    }
                    if ( a-1>=0 && ck(a-1,b,c) )
                    {
                        bigsum(f[a][b][c],f[a-1][b][c]);
                    }
                    if ( b-1>=0 && ck(a,b-1,c) )
                    {
                        bigsum(f[a][b][c],f[a][b-1][c]);
                    }
                    if ( c-1>=0 && ck(a,b,c-1) )
                    {
                        bigsum(f[a][b][c],f[a][b][c-1]);
                    }
                    //cout << a<<b<<c<<" f="<<f[a][b][c]<<endl;
                }
            }
        }

        for (int i=f[n][n][n][0];i>=1;i--)
        {
            cout << f[n][n][n][i];
        }
        cout << endl << endl;

    }
    return 0;
}
*/


#include <iostream>
#include <cstring>
#define BYTE unsigned char
using namespace std;

BYTE f[61][61][61][100];

BYTE ans[61][100];

void bigsum(BYTE *a,BYTE *b);

void bigsum(BYTE *a,BYTE *b)
{
    if ( b[0]>a[0] )
    {
        a[0]=b[0];
    }
    for (int i=1; i<=a[0]; i++)
    {
        a[i]+=b[i];
        a[i+1]+=a[i]/10;
        a[i]=a[i]%10;
    }
    if ( a[a[0]+1]>0 )
    {
        a[0]++;
    }
}

int main()
{
    int n;

    for (int a=0; a<=60; a++)
    {
        for (int b=0; b<=60; b++)
        {
            for (int c=0; c<=60; c++)
            {
                if (a==0)
                {
                    f[a][b][c][0]=1;
                    f[a][b][c][1]=1;
                    continue;
                }
                if ( a>=b && b>=c )
                {

                    if ( a-1>=0 &&( a-1>=b && b>=c )  )
                    {
                        bigsum(f[a][b][c],f[a-1][b][c]);
                    }
                    if ( b-1>=0 &&( a>=b-1 && b-1>=c ) )
                    {
                        bigsum(f[a][b][c],f[a][b-1][c]);
                    }
                    if ( c-1>=0 && (a>=b && b>=c-1) )
                    {
                        bigsum(f[a][b][c],f[a][b][c-1]);
                    }
                    if (a==b && b==c)
                    {
                        for (int i=f[a][b][c][0]; i>=0; i--)
                        {
                            ans[a][i]=f[a][b][c][i];
                        }
                    }
                }
                //cout << a<<b<<c<<" f="<<f[a][b][c]<<endl;
            }
        }
    }


    while (cin >> n)
    {
        memset(f,0,sizeof(f));


        for (int i=ans[n][0]; i>=1; i--)
        {
            cout << (int)ans[n][i];
        }
        cout << endl << endl;

    }
    return 0;
}
