#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int m,n,min,sum,num,x,y,t,bg,ed;
    int a[100][100];
    bool v[100]={false};
    int f[100]={0};
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
        f[i]=65535;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            a[i][j]=65535;
        }
    for (int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&t);
        a[x][y]=t;
        a[y][x]=t;
    }
    scanf("%d%d",&bg,&ed);
    v[bg]=true;
    f[bg]=0;
    //----------------------------------
    for (int loop=0;loop<n;loop++)
    {
        min=65535;
        for (int i=0;i<n;i++)
        if (v[i]==true)
        {
            for (int j=0;j<n;j++)
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
    if (f[ed]==0)
    {
        printf("-1");
    }
    else
    {
        printf("%d",f[ed]);
    }

    return 0;
}
