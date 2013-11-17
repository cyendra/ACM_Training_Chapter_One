#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int m,n,min,sum,num,x,y,t;
    int a[100][100];
    bool v[100]={false};
    int f[100]={0};
    scanf("%d%d",&n,&m);
    for (int i=0;i<=n;i++)
        f[i]=65535;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
        {
            a[i][j]=65535;
        }
    for (int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&t);
        a[x][y]=t;
        a[y][x]=t;
    }
    v[1]=true;
    f[1]=0;
    //----------------------------------
    for (int loop=0;loop<n;loop++)
    {
        min=65535;
        for (int i=1;i<=n;i++)
        if (v[i]==true)
        {
            for (int j=1;j<=n;j++)
            if ((v[j]==false) and (a[i][j])<65535)
            if ((f[i]+a[i][j])<min)
            {
                min=f[i]+a[i][j];
                num=j;
            }
        }
        if (min!=65535)
        {
            v[num]=true;
            f[num]=min;
        }

    }
    //-------------------------------------
    printf("%d",f[n]);
    return 0;
}
