#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
    int l;
    int w;
}ICE;

ICE a[5000];

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

bool v[5000];

int main()
{
    int T;
    int n,ok,pl,pw,ans;
    cin >> T;
    for (int loop=0;loop<T;loop++)
    {
        cin >> n;
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
