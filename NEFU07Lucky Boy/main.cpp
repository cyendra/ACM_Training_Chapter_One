#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const double OO=1e17;
const double eps=0.0000001;

struct POINT
{
    int x;
    int y;
    int num;
} a[1111];

double f[1111][1111];

bool cmp(POINT a,POINT b)
{
    if (a.x==b.x)
    {
        return a.y<b.y;
    }
    return a.x<b.x;
}

int n,m;
double last;
int ss;
bool ok;

int main()
{
    while (~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for (int i=0; i<n; i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }

        for (int i=0; i<n; i++)
        {
            m=0;
            for (int j=0; j<n; j++)
            {
                if (i==j) continue;
                if (a[j].x-a[i].x==0)
                {
                    f[i][m++]=OO;
                    continue;
                }
                f[i][m++]=(double)(a[j].y-a[i].y)/(double)(a[j].x-a[i].x);
            }
            sort(f[i],f[i]+m);
            last=-OO;
            ss=0;
            ok=true;
            for (int j=0; j<m; j++)
            {
                if ( abs(f[i][j]-last)<eps )
                {
                    ss++;
                }
                else
                {
                    last=f[i][j];
                    ss=1;
                }
                if (ss>=2)
                {
                    ok=false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (!ok)
        {
            puts("a is the lucky boy.");
        }
        else
        {
            if (n%3==0)
            {
                puts("b is the lucky boy.");
            }
            else
            {
                puts("a is the lucky boy.");
            }
        }

    }
    return 0;
}
