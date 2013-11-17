#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct{
    int v;
    int g;
}HERO;

typedef struct{
    int x;
    int y;
}POINT;

HERO f[30];

POINT a[30];

int n;

int maxfi,maxfv;

int main()
{
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    cin >> a[0].x >> a[0].y;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    for (int i=1;i<=n;i++)
    {
        f[i].v=f[i-1].v+( (a[i].x-a[0].x)*(a[i].x-a[0].x) + (a[i].y-a[0].y)*(a[i].y-a[0].y) );
        f[i].g=0;
        maxfi=0;
        maxfv=0;
        for (int j=1;j<i;j++)
        {
            if (  )
        }
    }
    return 0;
}
