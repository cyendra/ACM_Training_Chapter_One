
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

typedef struct{
    int high;
    int x;
    int y;
}HERO;

HERO a[100];
int f[100];

bool cmp(HERO a,HERO b)
{
    if (a.x>b.x)
    {
        return true;
    }
    else if (a.x<b.x)
    {
        return false;
    }
    else
    {
        if (a.y>b.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    int n,p,x,y,z,tmp,t,loop;
    loop=0;
    while ( cin >> n )
    {
        if (n==0)
        {
            break;
        }
        loop++;
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        p=0;

        for (int i=0;i<n;i++)
        {
            cin >> x >> y >> z;
            if (x>y)
            {
                a[p].x=x;
                a[p].y=y;
            }
            else
            {
                a[p].x=y;
                a[p].y=x;
            }
            a[p].high=z;
            p++;
            if (y>z)
            {
                a[p].x=y;
                a[p].y=z;
            }
            else
            {
                a[p].x=z;
                a[p].y=y;
            }
            a[p].high=x;
            p++;
            if (x>z)
            {
                a[p].x=x;
                a[p].y=z;
            }
            else
            {
                a[p].x=z;
                a[p].y=x;
            }
            a[p].high=y;
            p++;
            //读入数据
        }

        /*
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y >> z;
            a[p].x = min(x,y);
            a[p].y = max(x,y);
            a[p].high = z;
            a[p+1].x = min(x,z);
            a[p+1].y = max(x,z);
            a[p+1].high = y;
            a[p+2].x = min(z,y);
            a[p+2].y = max(z,y);
            a[p+2].high = x;
            p += 3;
        }
        */
        sort(a,a+p,cmp);
        //检验

        tmp=0;
        for (int i=0;i<p;i++)
        {
            f[i]=a[i].high;
            for (int k=0;k<i;k++)
            {
                if ((a[k].x>a[i].x)&&(a[k].y>a[i].y))
                {
                    if (f[k]+a[i].high>f[i])
                    {
                        f[i]=f[k]+a[i].high;
                    }
                }
            }
            if (f[i]>tmp)
            {
                tmp=f[i];
            }
        }
        tmp=0;
        for (int i=0;i<p;i++)
        {
            tmp=max(tmp,f[i]);
        }
        printf("Case %d: maximum height = %d\n",loop,tmp);
    }
    return 0;
}

