#include <iostream>
#include <cstring>

using namespace std;

int f[600][600];
int n,w,h,s,t;
bool a[600][600];
int ans;
int tmp;

int main()
{
    while (cin>>n)
    {
        if (n==0) break;
        ans=0;
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        cin>>w>>h;
        for (int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            a[x][y]=true;
        }
        cin>>s>>t;
        /*
        for (int i=1;i<=w;i++)
        {
            for (int j=1;j<=h;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        for (int i=1;i<=w;i++)
        {
            for (int j=1;j<=h;j++)
            {
                f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
                if ( a[i][j]==true ) f[i][j]+=1;
                //cout<<f[i][j]<<" ";
            }
            //cout<<endl;
        }
        for (int i=s;i<=w;i++)
        {
            for (int j=t;j<=h;j++)
            {
                tmp=f[i][j]-f[i-s][j]-f[i][j-t]+f[i-s][j-t];
                if (tmp>ans) ans=tmp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
