#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
    int x;
    int y;
    int v;
} HERO;

HERO a[200];

bool cmp(HERO a,HERO b)
{
    return ( a.v<b.v );
}

int main()
{
    char map[200][200];
    int fire[200][200];
    int n,ans,p,m,tmp;


    while ( cin >> n && n!=0 )
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin >>map[i][j];
                fire[i][j]=0;
                if ( map[i][j]=='X')//障碍标记为1
                {
                    fire[i][j]=1;
                }
            }
        }
        //寻找并记录影响数目
        m=0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (fire[i][j]==0)
                {
                    tmp=0;
                    p=i+1;
                    while ( p>=0 && p<n && fire[p][j]!=1 )
                    {
                        tmp++;
                        p++;
                    }
                    p=i-1;
                    while ( p>=0 && p<n && fire[p][j]!=1 )
                    {
                        tmp++;
                        p--;
                    }
                    p=j+1;
                    while ( p>=0 && p<n && fire[i][p]!=1 )
                    {
                        tmp++;
                        p++;
                    }
                    p=j-1;
                    while ( p>=0 && p<n && fire[i][p]!=1 )
                    {
                        tmp++;
                        p--;
                    }
                    a[m].x=i;
                    a[m].y=j;
                    a[m].v=tmp;
                    m++;
                }
            }
        }
        sort(a,a+m,cmp);
/*
        for (int i=0;i<m;i++)
        {
            cout << a[i].x << " " << a[i].y << " " << a[i].v << endl;
        }
*/
        ans=0;
        for (int i=0; i<m; i++)
        {
            if (fire[ a[i].x ][ a[i].y ]==0)
            {
                ans++;
                fire[ a[i].x ][ a[i].y ]=3;
                p= a[i].x +1;
                while ( p>=0 && p<n && fire[p][ a[i].y ]!=1 )
                {
                    fire[p][ a[i].y ]=2;
                    p++;
                }
                p= a[i].x -1;
                while ( p>=0 && p<n && fire[p][ a[i].y ]!=1 )
                {
                    fire[p][ a[i].y ]=2;
                    p--;
                }
                p= a[i].y +1;
                while ( p>=0 && p<n && fire[ a[i].x ][p]!=1 )
                {
                    fire[ a[i].x ][p]=2;
                    p++;
                }
                p= a[i].y -1;
                while ( p>=0 && p<n && fire[ a[i].x ][p]!=1 )
                {
                    fire[ a[i].x ][p]=2;
                    p--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
