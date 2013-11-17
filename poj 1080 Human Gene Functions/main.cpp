#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int mp[5][5]={{5,-1,-2,-1,-3},
                    {-1,5,-3,-2,-4},
                    {-2,-3,5,-2,-2},
                    {-1,-2,-2,5,-1},
                    {-3,-4,-2,-1,0}};
int f[111][111];
string s1,s2;
int a[1111],b[1111];
int len1,len2;
int T;

int main()
{
    cin>>T;
    while (T--)
    {
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cin>>len1>>s1;
        cin>>len2>>s2;
        a[0]=4;
        b[0]=4;
        for (int i=0;i<len1;i++)
        {
            switch (s1[i])
            {
                case 'A':
                {
                    a[i+1]=0;
                    break;
                }
                case 'C':
                {
                    a[i+1]=1;
                    break;
                }
                case 'G':
                {
                    a[i+1]=2;
                    break;
                }
                case 'T':
                {
                    a[i+1]=3;
                    break;
                }
            }
        }
        for (int i=0;i<len2;i++)
        {
            switch (s2[i])
            {
                case 'A':
                {
                    b[i+1]=0;
                    break;
                }
                case 'C':
                {
                    b[i+1]=1;
                    break;
                }
                case 'G':
                {
                    b[i+1]=2;
                    break;
                }
                case 'T':
                {
                    b[i+1]=3;
                    break;
                }
            }
        }
        for (int i=1;i<=len1;i++)
        {
            f[i][0]=f[i-1][0]+mp[ a[i] ][ 4 ];
        }
        for (int i=1;i<=len2;i++)
        {
            f[0][i]=f[0][i-1]+mp[ 4 ][ b[i] ];
        }
        for (int i=1;i<=len1;i++)
        {
            for (int j=1;j<=len2;j++)
            {
                f[i][j]=f[i-1][j-1]+mp[ a[i] ][ b[j] ];
                f[i][j]=max( f[i][j] , f[i-1][j]+mp[ a[i] ][ 4 ] );
                f[i][j]=max( f[i][j] , f[i][j-1]+mp[ 4 ][ b[j] ] );
                //cout<<f[i][j]<<" ";
            }
            //cout<<endl;
        }
        cout<<f[len1][len2]<<endl;
    }
    return 0;
}
