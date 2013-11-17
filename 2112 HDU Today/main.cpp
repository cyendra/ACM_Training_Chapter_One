#include <iostream>
#include <string>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n,bg,ed;
    string start,end,s,e;
    int t,p,min,minj;
    int a[151][151];
    int f[151];
    bool v[151];
    map<string,int> mp;
    while (scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for (int i=0;i<=150;i++)
        {
            for (int j=0;j<=150;j++)
            {
                a[i][j]=100;
            }
        }
        if (n==-1)
        {
            break;
        }
        p=1;
        cin >> start >> end;
        for (int i=1;i<=n;i++)
        {
            cin >> s >> e >> t;
            if ( mp[s]==0 )
            {
                mp[s]=p;
                p++;
            }
            if ( mp[e]==0 )
            {
                mp[e]=p;
                p++;
            }
            a[ mp[s] ][ mp[e] ]=t;
            a[ mp[e] ][ mp[s] ]=t;
        }
        //检验
        /*
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        */
        if (start==end)
        {
            printf("0\n");
            continue;
        }
        if ((mp[start]==0)||(mp[end]==0))
        {
            printf("-1\n");
            continue;
        }
        bg=mp[start];
        ed=mp[end];
        //---迪杰斯特拉-----------------------------
        for (int i=0;i<=n;i++)
        {
            v[i]=false;
            f[i]=100;
        }
        v[bg]=true;
        f[bg]=0;
        for (int loop=1;(loop<=n)&&(v[ed]!=true);loop++)
        {
            min=100;
            minj=0;
            for (int i=1;i<=n;i++)
            {
                if (v[i]==true)
                {
                    for (int j=1;j<=n;j++)
                    {
                        if ( (v[j]==false) && (a[i][j]!=100) && ( f[i]+a[i][j]<f[j] ) )
                        {
                            f[j]=f[i]+a[i][j];
                        }
                    }
                }
            }
            for (int j=1;j<=n;j++)
            {
                if (v[j]==false)
                {
                    if (f[j]<min)
                    {
                        min=f[j];
                        minj=j;
                    }
                }
            }
            if ( (minj!=0) && (min<100) ) v[minj]=true;
        }
        //---最短路寻找完毕-------------------------
        if (v[ed]==true)
        {
            printf("%d\n",f[ed]);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
