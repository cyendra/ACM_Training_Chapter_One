/*
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
    int l;
    int w;
    bool v;
} YOO;

YOO a[6000];

bool cmp(YOO a,YOO b)
{
    return a.l>b.l;
}

int main()
{
    int n;
    int sum;
    while (cin>>n)
    {
        sum=0;
        for (int i=0; i<n; i++)
        {
            cin>>a[i].l>>a[i].w;
            a[i].v=true;
        }
        sort(a,a+n,cmp);
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                if (a[j].v&&a[i].l>=a[j].l&&a[i].w>=a[j].w)
                {
                    a[j].v=false;
                }
            }
        }
        for (int i=0; i<n; i++)
        {
            if (a[i].v)
            {
                sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
    int l;
    int w;
}ICE;

ICE a[5100];

bool cmp(ICE a,ICE b);

bool cmp(ICE a,ICE b)
{
    if (a.l==b.l)
    {
        return a.w<b.w;
    }
    else
    {
        return a.l<b.l;
    }
}

bool v[5100];

int main()
{
    int T;
    int n,ok,pl,pw,ans;

    while (cin >> n)
    {
        for (int i=0;i<n;i++)
        {
            cin >> a[i].l >> a[i].w;
            v[i]=false;
        }
        sort(a,a+n,cmp);
        ans=0;
        for (int i=0;i<n;i++)
        {
            if ( v[i]==false )
            {
                pl=a[i].l;
                pw=a[i].w;
                v[i]=true;
                ans++;
                for (int j=i+1;j<n;j++)
                {
                    if ( v[j]==false && a[j].w>=pw && a[j].l >=pl )
                    {
                        pl=a[j].l;
                        pw=a[j].w;
                        v[j]=true;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
