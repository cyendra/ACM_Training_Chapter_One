#include <iostream>
#include <cstring>
#define OO 9999999

using namespace std;

int n,m,w,F;
int a[600][600];
int dist[600];

int main()
{
    int s,e,t;
    bool flag;
    cin>>F;
    while (F--)
    {
        memset(a,0,sizeof(a));
        cin>>n>>m>>w;
        for (int i=1;i<=m;i++)
        {
            cin>>s>>e>>t;
            if (a[s][e]==0)
            {
                a[s][e]=t;
                a[e][s]=t;
            }
            else if (a[s][e]>0&&t<a[s][e])
            {
                a[s][e]=t;
                a[e][s]=t;
            }
        }
        for (int i=1;i<=w;i++)
        {
            cin>>s>>e>>t;
            a[s][e]=-t;
        }
        for (int i=0;i<=n;i++) dist[i]=OO;
        dist[1]=0;
        for (int loop=1;loop<=n;loop++)
        {
            flag=true;
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=n;j++)
                {
                    if (a[i][j]!=0)
                    {
                        if (dist[j]>dist[i]+a[i][j])
                        {
                            dist[j]=dist[i]+a[i][j];
                            flag=false;
                        }
                    }
                }
            }
            if (flag)break;
        }
        if (flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
