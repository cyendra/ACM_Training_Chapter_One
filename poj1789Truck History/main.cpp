#include <iostream>
#include <cstring>
#define OO 9999999

using namespace std;

int a[2222][2222];
int n;
char str[2222][10];
int d[2222];

int main()
{
    int n,t,mind,ans;
    while (cin>>n)
    {
        if (n==0) break;
        memset(a,0,sizeof(a));
        memset(str,0,sizeof(str));
        memset(d,0,sizeof(d));
        for (int i=1;i<=n;i++)
        {
            cin>>str[i];
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                t=0;
                for (int k=0;k<7;k++)
                {
                    if (str[i][k]!=str[j][k]) t++;
                }
                a[i][j]=t;
                a[j][i]=t;
            }
        }
        //prim
        ans=0;
        t=1;
        for (int i=1;i<=n;i++)
        {
            d[i]=a[t][i];
        }
        for (int loop=1;loop<=n-1;loop++)
        {
            mind=OO;
            for (int i=1;i<=n;i++)
            {
                if (d[i]<mind&&d[i]!=0)
                {
                    mind=d[i];
                    t=i;
                }
            }
            ans+=mind;
            for (int i=1;i<=n;i++)
            {
                if (a[i][t]<d[i])
                {
                    d[i]=a[i][t];
                }
            }
        }
        cout<<"The highest possible quality is 1/"<<ans<<"."<<endl;
    }
    return 0;
}
