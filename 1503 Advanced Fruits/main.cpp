#include <iostream>
#include <string>
#include <cstring>

using namespace std;

typedef struct{
    int v;
    char last;
    int la;
    int lb;
}HERO;

HERO f[256][256];

int main()
{
    char a[256] ,b[256] ,c[256],ans[256];
    int lena,lenb,lenc,ta,tb,x,y;
    while ( cin >> a >> b )
    {
        memset(f,0,sizeof(f));
        lena=strlen(a);
        lenb=strlen(b);
        for (int i=1;i<=lena;i++)
        {
            for ( int j=1;j<=lenb;j++)
            {
                f[i][j].v=f[i-1][j].v;
                f[i][j].last=f[i-1][j].last;
                f[i][j].la=f[i-1][j].la;
                f[i][j].lb=f[i-1][j].lb;
                if ( f[i][j-1].v > f[i][j].v )
                {
                    f[i][j].v=f[i][j-1].v;
                    f[i][j].last=f[i][j-1].last;
                    f[i][j].la=f[i][j-1].la;
                    f[i][j].lb=f[i][j-1].lb;
                }
                if ( a[i-1]==b[j-1] && f[i][j].v<f[i-1][j-1].v+1 )
                {
                    f[i][j].v=f[i-1][j-1].v+1;
                    f[i][j].last=a[i-1];
                    f[i][j].la=i-1;
                    f[i][j].lb=j-1;
                }
            }
        }

        /*
        for (int i=0;i<=lena;i++)
        {
            for (int j=0;j<=lenb;j++)
            {
                cout << i << j << f[i][j].v << f[i][j].last << f[i][j].la << f[i][j].lb<<endl;
            }
        }
        cout << endl;
        */
        ta=lena;
        tb=lenb;
        lenc=0;
        while ( ta!=0 && tb!=0 && f[ta][tb].last!=0 )
        {
            c[lenc]=f[ta][tb].last;
            x=f[ta][tb].la;
            y=f[ta][tb].lb;
            ta=x;
            tb=y;
            lenc++;
        }
        /*
        for (int i=lenc-1;i>=0;i--)
        {
            cout<<c[i];
        }
        cout << endl;
        */

        //此时最长公共字串倒序储存在c中长度为lenc


        int tmp=lenc-1;
        ta=0;
        tb=0;
        int lenans=0;

        while ( tmp>=0 )
        {
            while (ta<lena && a[ta]!=c[tmp] )
            {
                ans[lenans]=a[ta];
                ta++;
                lenans++;
            }
            while ( tb<lenb && b[tb]!=c[tmp] )
            {
                ans[lenans]=b[tb];
                tb++;
                lenans++;
            }
            ans[lenans]=c[tmp];
            tmp--;
            lenans++;
            ta++;
            tb++;
        }
        for (int i=ta;i<lena;i++)
        {
            ans[lenans]=a[i];
            lenans++;
        }
        for (int i=tb;i<lenb;i++)
        {
            ans[lenans]=b[i];
            lenans++;
        }





        /* //wrong_print
        while ( tmp>=0 && ta<lena && tb<lenb )
        {
            while ( ta<lena && a[ta]!=c[tmp] )
            {
                ans[lenans]=a[ta];
                ta++;
                lenans++;
            }
            while ( tb<lenb && b[tb]!=c[tmp] )
            {
                ans[lenans]=b[tb];
                tb++;
                lenans++;
            }
            if ( tmp>=0 )
            {
                ans[lenans]=c[tmp];
                tmp--;
                lenans++;
                ta++;
                tb++;
            }

        }
        */

        for (int i=0;i<lenans;i++)
        {
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}
