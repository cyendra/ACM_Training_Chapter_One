#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct{
    double bg;
    double ed;
}DAT;

DAT a[1111];
double x,y;
int n;
double d;
double lt;
int loop;

bool cmp(DAT a,DAT b)
{
    return a.ed<b.ed;
}

int main()
{
    int ans;
    bool ok;
    loop=0;
    while (cin>>n>>d)
    {
        loop++;
        ok=true;
        if (n==0&&d==0)break;
        if (d<0) ok=false;
        for (int i=0;i<n;i++)
        {
            cin>>x>>y;
            if (y>d||y<0)
            {
                ok=false;
            }
            a[i].bg=x-sqrt(d*d-y*y);
            a[i].ed=x+sqrt(d*d-y*y);
        }
        if (!ok)
        {
            cout<<"Case "<<loop<<": ";
            cout<<"-1"<<endl;
            continue;
        }
        sort(a,a+n,cmp);
        ans=0;
        lt=-9999999;
        for (int i=0;i<n;i++)
        {
            if (a[i].bg>lt)
            {
                lt=a[i].ed;
                ans++;
            }
        }
        cout<<"Case "<<loop<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
