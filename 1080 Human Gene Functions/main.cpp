#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int map[5][5]={ {5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0} };

int main()
{
    int f[256][256];
    int t,tmp;
    int lena,lenb;
    int a[256],b[256];
    char stra[256],strb[256];
    cin >> t;
    for (int loop=0;loop<t;loop++)
    {
        cin >> lena >> stra;
        cin >> lenb >> strb;
        for (int i=0;i<lena;i++)
        {
            if (stra[i]=='A')
            {
                a[i]=0;
            }
            if (stra[i]=='C')
            {
                a[i]=1;
            }
            if (stra[i]=='G')
            {
                a[i]=2;
            }
            if (stra[i]=='T')
            {
                a[i]=3;
            }
        }
        for (int i=0;i<lenb;i++)
        {
            if (strb[i]=='A')
            {
                b[i]=0;
            }
            if (strb[i]=='C')
            {
                b[i]=1;
            }
            if (strb[i]=='G')
            {
                b[i]=2;
            }
            if (strb[i]=='T')
            {
                b[i]=3;
            }
        }
        //f[0][0]=0;
        //f[1][0]=map[a[0]][4];
        //f[0][1]=map[4][b[0]];
        for (int i=0;i<=lena;i++)
        {
            for (int j=0;j<=lenb;j++)
            {
                if (i==0&&j==0)
                {
                    f[i][j]=0;
                }
                else if( i==0 && j!=0 )
                {
                    f[i][j]=f[0][j-1]+map[4][ b[j-1] ];
                }
                else if ( i!=0 && j==0 )
                {
                    f[i][j]=f[i-1][0]+map[ a[i-1] ][4];
                }
                else
                {
                    f[i][j]=f[i-1][j-1]+map[ a[i-1] ][ b[j-1] ];
                    f[i][j]=max( f[i][j] , f[i-1][j] + map[ a[i-1] ][4] );
                    f[i][j]=max( f[i][j] , f[i][j-1] + map[4][ b[j-1] ] );
                }
            }
        }
        cout << f[lena][lenb] << endl;
    }
    return 0;
}
