#include <iostream>

using namespace std;

int n,m;
char a[30][30];

int main()
{
    int x1,y1,x2,y2;
    int ans;
    bool ok;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    ans=0;
    for (x1=0;x1<n;x1++)
    {
        for (y1=0;y1<m;y1++)
        {
            for (x2=x1;x2<n;x2++)
            {
                for (y2=y1;y2<m;y2++)
                {
                    if ( (x2-x1+1+y2-y1+1)*2>ans )
                    {
                        ok=true;
                        for (int i=x1;i<=x2;i++)
                        {
                            if (ok) for (int j=y1;j<=y2;j++)
                            {
                                if ( a[i][j]=='1' )
                                {
                                    ok=false;
                                    break;
                                }
                            }
                        }
                        if (ok)
                        {
                            ans=(x2-x1+1+y2-y1+1)*2;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
