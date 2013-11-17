#include <iostream>
#include <algorithm>

using namespace std;

struct LES{
    int l;
    int r;
    int d;
};

LES a[1000];
bool b[10000009];
int n;
int ans[1000];

bool cmp(LES a,LES b)
{
    return a.r<b.r;
}

int main ()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].l>>a[i].r;
        a[i].d=i;
    }
    sort (a,a+n,cmp);
    for (int i = 0; i < n; i++)
    {
        for (int j=a[i].l;j<=a[i].r;j++)
        {
            if ( !b[j] )
            {
                b[j]=true;
                ans[a[i].d]=j;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
