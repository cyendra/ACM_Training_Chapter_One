#include <iostream>
#include <cstring>

using namespace std;

typedef struct
{
    int l;
    int r;
} PER;

int n,p1,p2,p3,t1,t2;
PER a[200];
int d[1500];
int bg,ed;
int t;
int p;
int ans;
int set;

int main()
{
    memset(d,0,sizeof(d));
    cin>>n>>p1>>p2>>p3>>t1>>t2;
    for (int i=0; i<n; i++)
    {
        cin>>a[i].l>>a[i].r;
    }
    ans=0;
    ans=(a[0].r-a[0].l)*p1;
    for (int i=1;i<n;i++)
    {
        set=a[i].l-a[i-1].r;
        if (set>t1+t2)
        {
            ans+=(set-t1-t2)*p3;
            set=t1+t2;
        }
        if (set>t1)
        {
            ans+=(set-t1)*p2;
            set=t1;
        }
        ans+=set*p1;
        ans+=( a[i].r-a[i].l )*p1;
    }
    cout << ans << endl;
    return 0;
}
