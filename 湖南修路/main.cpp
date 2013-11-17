#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int m,n,min,s,num,sum,x,y,t,tmp;
    bool ok;
    int a[100][100];
    bool v[100]={false};
    int f[100]={0};
    scanf("%d",&n);
    for (int i=0;i<=n;i++)
        f[i]=65535;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
        {
            a[i][j]=65535;
        }
    for (int i=0;i<((n*(n-1))/2);i++)
    {
        scanf("%d%d%d%d",&x,&y,&t,&s);
        a[x][y]=t;
        a[y][x]=t;
        if (s==1)
        {
            a[x][y]=0;
            a[y][x]=0;
        }
    }
    v[1]=true;
    f[1]=0;
    sum=0;
    //----------------------------------
    for (int loop=0;loop<=n;loop++)
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
                tmp=a[i][j];
            }
        }
        if (min!=65535)
        {
            v[num]=true;
            f[num]=min;
            sum+=tmp;
        }
    }
    //-------------------------------------
    printf("%d",sum);

    return 0;
}
