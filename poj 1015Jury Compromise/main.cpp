#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int n,m;

const int fix=400;

int p[201],d[201];
int f[201][21][801];
int pre[201][21][801];
int ans[21];
int txt;

int main()
{
    int zero,top;
    txt=0;
    while ( cin>>n>>m )
    {
        if (n==0&&m==0) break;
        memset(f,-1,sizeof(f));
        memset(pre,-1,sizeof(pre));
        top=m*40;
        zero=m*20;
        for (int i=1;i<=n;i++)
        {
            cin>>d[i]>>p[i];
        }

        for (int i=0;i<=n;i++)
        {
            f[i][0][zero]=0;
        }

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m&&j<=i;j++)
            {
                for (int k=0;k<=top;k++)
                {
                    f[i][j][k]=f[i-1][j][k];
                    pre[i][j][k]=pre[i-1][j][k];
                    if ( (k-d[i]+p[i]>=0)&&
                        (k-d[i]+p[i]<=top)&&
                        (f[i-1][j-1][k-d[i]+p[i]]!=-1)&&
                        (f[i-1][j-1][k-d[i]+p[i]]+d[i]+p[i]>=f[i][j][k]) )
                        {
                            f[i][j][k]=f[i-1][j-1][k-d[i]+p[i]]+d[i]+p[i];
                            pre[i][j][k]=i;
                        }
                }
            }
        }
        int i,j;
        for (i=zero;i<=top;i++)
        {
            if (f[n][m][i]!=-1) break;
        }
        for (j=zero-1;j>=0;j--)
        {
            if (f[n][m][j]!=-1) break;
        }

        if (j>=0)
        {
            if ( (i>top) || (i-zero>zero-j) || (i-zero==zero-j&&f[n][m][j]>f[n][m][i]) )
            {
                i=j;
            }
        }

        int c=pre[n][m][i],l=0,r=0;
        for (int k=m;k>=1;k--)
        {
            l+=d[c];
            r+=p[c];
            ans[k]=c;
            i-=(d[c]-p[c]);
            c=pre[c-1][k-1][i];
        }
        txt++;
        cout<<"Jury #"<<txt<<endl;
        cout<<"Best jury has value "<<l<<" for prosecution and value "<<r<<" for defence:"<<endl;
        for (int i=1;i<=m;i++) cout<<" "<<ans[i];
        cout<<endl<<endl;
    }
    return 0;
}
