#include <iostream>

using namespace std;

int map[1001][1001];
int a[1001][1001];
int r[1001];
int l[1001];

int main()
{
    int K,m,n,ans,tmp;
    char chr;
    cin >> K;
    for (int loop=1;loop<=K;loop++)
    {
        cin >> m >> n;

        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                cin>>chr;
                if (chr=='R')
                {
                    map[i][j]=0;
                }
                if (chr=='F')
                {
                    map[i][j]=1;
                }
                if (i==0)
                {
                    a[i][j]=map[i][j];
                }
                else
                {
                    if ( map[i][j]==0 )
                    {
                        a[i][j]=0;
                    }
                    else
                    {
                        a[i][j]=a[i-1][j]+1;
                    }
                }
            }
        }

        ans=0;
        for (int lan=0;lan<m;lan++)
        {
        //----------------------------------
        for (int i=0;i<n;i++)
        {
            l[i]=i;
            while ( l[i]>0 && a[lan][i]<=a[lan][l[i]-1] )
            {
                l[i]=l[ l[i]-1 ];
            }
        }
        for (int i=n-1;i>=0;i--)
        {
            r[i]=i;
            while ( r[i]<n-1 && a[lan][i]<=a[lan][r[i]+1] )
            {
                r[i]=r[ r[i]+1 ];
            }
        }

        tmp=0;
        for (int i=0;i<n;i++)
        {
            tmp=(r[i]-l[i]+1) * a[lan][i];
            if (tmp>ans)
            {
                ans=tmp;
            }
        }

        //----------------------------------
        }
        cout << ans*3 << endl;

    }

    return 0;
}
