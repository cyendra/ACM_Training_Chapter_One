#include <iostream>

using namespace std;

typedef struct{
    int l;
    int r;
}DAT;
DAT a[200];

int main()
{
    int n,x0,t;
    int maxl,minr;
    int ans=0;
    cin >> n >> x0;

    maxl=-999999;
    minr=999999;
    for (int i=0;i<n;i++)
    {
        cin >> a[i].l >> a[i].r;
        if (a[i].l>a[i].r)
        {
            t=a[i].l;
            a[i].l=a[i].r;
            a[i].r=t;
        }
        if (a[i].l>maxl) maxl=a[i].l;
        if (a[i].r<minr) minr=a[i].r;
    }
    if ( maxl>minr )
    {
        ans=-1;
    }
    else if ( (x0>maxl)&&(x0<minr) )
    {
        ans=0;
    }
    else if ( x0<maxl )
    {
        ans=maxl-x0;
    }
    else if ( x0>minr )
    {
        ans=x0-minr;
    }
    cout << ans << endl;
    return 0;
}
